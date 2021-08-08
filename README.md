# sf-cabinet

Tools and utilities for modifying [SF2 Cabinets](https://www.myarcadegaming.com/products/street-fighter-2-champion-edition)

## What

This repository contains research and tooling around the mini Street Fighter 2 cabinet releasd late last year

Current capabilties include:
* SPI flash extraction via the ```sunxi-fel``` utilities
    * **Note** You can also do this in circuit with a SOP8 clip and flashrom, but it's obviously much easier to do this via the FEL loader
* Startup script modification via the scripts listed below
* MINFS partition parsing, allowing for a full extraction of all availalble files

---

## Tools

* ```minfs-parse.py```: Tool to extract files from the MINFS partition, resulting in an image of the filesystem
* ```startup-patch.py```: Used to patch the startup script embedded in the flash that starts on boot, use this for testing scripts, listing directory entries, etc
* ```extract_startup.sh```: Used to extract the portion of the SPI flash dump that contains the startup script to be modified by ```startup-patch.py```
* ```patch_startup.sh```: Calls the ```sunxi-fel``` tool to reflash the portion of the SPI flash containing the startup script. Cabinet must be in FEL mode to run this

---

## Current Tasks / Next Steps

* While some files can be viewed normally, others are compressed with some [variation of LZMA](https://github.com/wrongbaud/sf-cabinet/wiki/file-compression)
    * While we can extract _some_ of these manually, this process could and should be automated
* Decompression of the executable files 
    * These are similarly compressed with some form of LZMA, but do not compress as easily as the bitmap files
* Document and write up example of extracting and decompressing the splash screen on boot

## Cabinet Specs

* Architecture: ARM (Allwinner SoC)
* Operating System: EPOS
   * Some tools and utiltiies can be found [here](https://epos.lisha.ufsc.br/EPOS+User+Guide)
   * [Some API documentation](https://usermanual.wiki/Document/SW1103REF005MELIS20PROGRAM20GUIDEModule.77258713.pdf)
* Filesystem(s): MINFS,FAT12
* OSS in Use: FBA 


