from sfbin import *
import logging
import sys
import os

logfile = open("/home/wrongbaud/blog/sf-cabinet/file-info.txt","w")
target = Sfbin.from_file("/home/wrongbaud/blog/sf-cabinet/sf-cab.bin")
for entry in target.minfs_file_table:
    logfile.write(f"{entry}")
logfile.close()    
os.mkdir("output-files")
    if entry.flags != target.FileType.directory:
        with open(f"output-files/{entry.name}",'wb') as ofile:
            ofile.write(entry.file_data)
