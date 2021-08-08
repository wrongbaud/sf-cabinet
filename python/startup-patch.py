#!/usr/bin/python3
import os
import sys
import logging
import argparse

def main(script,image):
    with open(script,'rb') as scriptfile:
        scriptData = scriptfile.read()
        scriptData = bytes(scriptData)
        print(scriptData)
        if len(scriptData) > 0x35A:
            logging.warning("Script size too large! This will likely clobber other useful data!")
            sys.exit()
        with open(image,'rb+') as imgFile:
            # Seek to the start of the startup script
            imgFile.seek(0x980)
            imgFile.write(scriptData)
            # Terminate the file properly
            imgFile.write(b'\x0d\x0a')
     

if __name__ == "__main__":
    script = sys.argv[1]
    image = sys.argv[2]
    main(script,image)
