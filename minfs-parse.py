#!/usr/bin/python3
import ctypes
import logging
import struct
import os
import sys
logging.basicConfig(level=logging.DEBUG)


'''
typedef struct {
  char magic[6];
  minfs_short_t version;
  minfs_long_t  tree_offset;
  minfs_long_t  root_size;
  minfs_long_t  tree_entries;
  minfs_long_t  tree_size;
  minfs_long_t  fdata_length;
  minfs_long_t  image_size;
} minfs_header_t;
'''

class MinFS:
    def __init__(self,data,extraction_path):
        self.dat = data
        self.magic = None
        self.version = None
        self.tree_offset = None 
        self.root_size = None
        self.tree_entries  = None
        self.tree_size = None
        self.fdata_length = None
        self.image_size = None
        self.header = self.parseHeader(data)
        self.rootDir = []
        self.parseRootfs(self.dat)
        self.current_dir = []
        self.current_dir.append(extraction_path)
        self.extractFs()

    def extractFs(self):
        self.current_dir.append("rootfs")
        for folder in self.current_dir:
            print(folder)
        os.makedirs(self.getCurrentDir())
        for entry in self.rootDir:
            # If we have a directory, recursively extract it
            if entry.flags == 1:
                self.extractDir(entry)
            else:
                self.extractFile(entry)
    '''
    Extract all files in a given directory, if another directory is discovered, call recursively
    '''
    def extractDir(self,dir):
        # First, make the directory and append it to the current dir
        self.current_dir.append(dir.name.decode()) 
        os.makedirs(self.getCurrentDir())
        # Now look through the directory and either generate files or new dirs...
        self.dat.seek(dir.offset) 
        # Read through all files in the root directory
        bytesRead = 0
        print(self.getCurrentDir())
        while(bytesRead < dir.rawSize):
            self.dat.seek(dir.offset+bytesRead)
            newFile = MinFSFile(self.dat)
            logging.info(f"File located in directory {self.getCurrentDir()} named {newFile.name}")
            logging.info(f"{newFile}")
            bytesRead += newFile.entryLen
            if newFile.flags == 1:
                self.extractDir(newFile)
            else:
                self.extractFile(newFile) 
        self.current_dir.pop()

    def getCurrentDir(self):
        return "/".join(folder for folder in self.current_dir)

    def extractFile(self,mFile):
        logging.info(f"Extracting file: {mFile.name}")
        print(mFile)
        with open(self.getCurrentDir()+"/"+mFile.name.decode(), 'wb') as oFile:
            self.dat.seek(mFile.offset)
            oFile.write(self.dat.read(mFile.rawSize))
             
    def parseHeader(self,data):
        self.magic = struct.unpack("6s",data.read(6))[0]
        if self.magic != b'MINFS\x00':
            logging.error("Cannot detect MINFS header, exiting now!")
            sys.exit()
        self.version = struct.unpack("H",data.read(2))[0]
        self.tree_offset = struct.unpack("I",data.read(4))[0]
        self.root_size = struct.unpack("I",data.read(4))[0]
        self.tree_entries = struct.unpack("I",data.read(4))[0]
        self.tree_size = struct.unpack("I",data.read(4))[0]
        self.fdata_length = struct.unpack("I",data.read(4))[0]
        self.image_size = struct.unpack("I",data.read(4))[0]
    
    def parseRootfs(self,data):
        # Seek to offset where RootFS starts
        data.seek(self.tree_offset)
        # Read through all files in the root directory
        bytesRead = 0
        while(bytesRead < self.root_size):
            newFile =  MinFSFile(data)
            bytesRead += newFile.entryLen
            self.rootDir.append(newFile)
            
         

    def __str__(self):
        return (
        f"Version: {self.version}\n"
        f"Tree Offset: {self.tree_offset}\n"
        f"Root Size: {self.root_size}\n"
        f"Tree Entries: {self.tree_entries}\n"
        f"Tree Size: {self.tree_size}\n"
        f"FData Length: {self.fdata_length}\n"
        f"Image Size: {self.image_size}\n"
        )

class MinFSDir:
    def __init__(data):
        self.dirname = none
        self.files = []

'''
typedef struct {
  minfs_long_t  offset;
  minfs_long_t  raw_size;
  minfs_long_t  orig_size;
  minfs_short_t entry_length;
  minfs_short_t flags;
  minfs_short_t name_length;
  minfs_short_t extra_length;
} minfs_entry_t;

'''
class MinFSFile:
    def __init__(self,data):
        self.offset = None
        self.rawSize = None
        self.origSize = None
        self.entryLen = None
        self.flags = None
        self.nameLen = None
        self.name = ""
        self.offset = None
        self.parseFileEntry(data)

    def parseFileEntry(self,data):
        logging.info(f"Parsing File Entry for file at {data.tell()}")
        self.offset = struct.unpack("I",data.read(4))[0]
        self.rawSize = struct.unpack("I",data.read(4))[0]
        self.origSize = struct.unpack("I",data.read(4))[0]
        self.entryLen = struct.unpack("H",data.read(2))[0]
        self.flags = struct.unpack("H",data.read(2))[0]
        self.nameLen = struct.unpack("H",data.read(2))[0]
        self.extraLen = struct.unpack("H",data.read(2))[0]
        self.name = struct.unpack(f"{self.nameLen}s",data.read(self.nameLen))[0]
        data.read((self.entryLen - self.nameLen - 20))

    def __str__(self):
        return (
        f"Offset: {self.offset}\n"
        f"Raw Size: {self.rawSize}\n"
        f"origSize: {self.origSize}\n"
        f"Entry Length: {self.entryLen}\n"
        f"Flags: {self.flags}\n"
        f"Name Length: {self.nameLen}\n"
        f"Extra Length: {self.extraLen}\n"
        f"Name : {self.name}\n"
    )

def parseFileEntry(data):
    newFile = minfsFile()
    newFile.offset = struct.unpack("I",data.read(4))[0]
    newFile.rawSize = struct.unpack("I",data.read(4))[0]
    newFile.origSize = struct.unpack("I",data.read(4))[0]
    newFile.entryLen = struct.unpack("H",data.read(2))[0]
    newFile.flags = struct.unpack("H",data.read(2))[0]
    newFile.nameLen = struct.unpack("H",data.read(2))[0]
    newFile.extraLen = struct.unpack("H",data.read(2))[0]
    newFile.name = struct.unpack(f"{newFile.nameLen}c",data.read(newFile.nameLen))
    '''
    for x in range(0,newFile.nameLen):
        newFile.name += struct.unpack("{}c",data.read(1))[0].decode()
    '''
    data.read((newFile.entryLen - newFile.nameLen - 20))
    return newFile

def main(infile):
    logging.info(f"Analyzing: {infile}")
    with open(infile,'rb') as test:
        fs = MinFS(test,"test-output")
        print(fs)

if __name__ == "__main__":
    infile = sys.argv[1]
    main(infile)
