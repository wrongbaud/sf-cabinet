import ctypes
import logging
import struct
import os
import sys

class MinFS:
    def __init__(data):
        self.dat = data
        self.header = self.parseHeader(data)

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
class minfsFile:
    def __init__(self):
        self.offset = None
        self.rawSize = None
        self.origSize = None
        self.entryLength = None
        self.flags = None
        self.nameLen = None
        self.name = ""
        self.offset = None

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
    for x in range(0,newFile.nameLen):
        newFile.name += struct.unpack("c",data.read(1))[0].decode()
    data.read((newFile.entryLen - newFile.nameLen - 20))
    return newFile

def parseMinFSHeader(infile):
    return
def main(infile):
    logging.info(f"Analyzing: {infile}")
    with open(infile,'rb') as test:
        test.seek(0x200)
        for x in range(0,60):
            parseFileEntry(test)

if __name__ == "__main__":
    infile = sys.argv[1]
    main(infile)
