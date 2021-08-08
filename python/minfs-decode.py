from minfs import *
import logging
import sys
import os

target = Minfs.from_file("/home/wrongbaud/blog/sf-cabinet/output-files/ramdisk.iso")
os.mkdir("/home/wrongbaud/blog/sf-cabinet/ramdisk/")
for entry in target.minfs_file_table:
    if entry.flags != target.FileType.directory:
        with open(f"/home/wrongbaud/blog/sf-cabinet/ramdisk/{entry.name}",'wb') as ofile:
            ofile.write(entry.file_data)