import os
import sys
import argparse

SCRIPT_OFFSET=0x9D980
SCRIPT_SIZE=0x4A1
# When we write back to the SPI flash over USB it needs to be a multiple of 4096
BLOCK_OFFSET=0x9D000
BLOCK_END=0x9E000

def scriptCheck(scriptfile):
    data = None
    with open(scriptfile, 'rb') as script:
        data = script.read()
        print(f"Script file is {len(data)} bytes")
        # Terminate the file
        if len(data) > 0x4A1:
            print(f"Input script file is too large, please decrease the size and try again")
            return None
        else:
            pad_len = 0x4A1 - len(data)
            for x in range(0,pad_len):
                if x == pad_len - 2:
                    data += b'\x0d'
                elif x == pad_len -1:
                    data += b'\x0a'
                else:
                    data+=b'\x20'
        return data

def main(scriptfile,infile,outfile):
    data = scriptCheck(scriptfile)
    inputData = bytearray(open(infile,'rb').read())
    outputRom = open(outfile,'wb')
    scriptOffset = SCRIPT_OFFSET
    for element in bytearray(data):
        inputData[scriptOffset] = element
        scriptOffset+=1
    outputData = inputData[0x9D000:0x9E000]
    outputRom.write(outputData)
    return
    
if  __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--script","-s",type=str,help="Startup script to inject into image")
    parser.add_argument("--image","-i",type=str,help="Image to build new image from")
    parser.add_argument("--output","-o",type=str,help="Output file for new image containing new startup script")
    args = parser.parse_args()
    print(args.script)
    print(args.image)
    print(args.output)
    main(args.script,args.image,args.output)
