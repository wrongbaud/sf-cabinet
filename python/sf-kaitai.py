from sfbin import *
import logging
import sys
import os

logfile = open("/home/wrongbaud/blog/sf-cabinet/file-info.txt","w")
target = Sfbin.from_file("/home/wrongbaud/blog/sf-cabinet/sf-cab.bin")
for entry in target.minfs_file_table:
    logfile.write(f"{entry}")
logfile.close()    
'''
os.mkdir("output-files")
    if entry.flags != target.FileType.directory:
        with open(f"output-files/{entry.name}",'wb') as ofile:
            ofile.write(entry.file_data)

def replace_file_contents(sfRom,target_file,replacement_data):
    # Walk the file table and locate what we want to replace
    for f_entry in sfRom.minfs_file_table:
        if f_entry.name == target_file:
            # Check the size of the resulting data to make sure that we're not overwriting anything
            if len(replacement_data > f_entry.raw_size):
                logging.error("Replacement file too large! Must be less than original file")
                sys.exit()
            # 
'''