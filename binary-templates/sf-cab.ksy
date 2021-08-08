meta:
  id: sfbin
  endian: le
seq:
  - id: bt0
    type: bt0_data
  - id: bt1
    type: bt1_data
  - id: epos_ptable
    type: epos_placeholder
  - id: minfs_header
    type: minfs_table_header
  - id: minfs_pad
    size: minfs_header.tree_offset-32
  - id: minfs_file_table
    type: minfs_table_entry
    repeat: expr
    repeat-expr: minfs_header.tree_entries

types:
  bt0_data:
    doc: "First stage bootloader controls jump to FEL"
    seq:
      - id: bt0_data
        size: 0x6000
  bt1_data:
    doc: "Second stage bootloader, FEL loader lives here as well"
    seq:
      - id: bt1_data
        size: 0x1E000
  epos_placeholder:
    doc: "Simple placeholder for overarching partition table that is not fully understood yet"
    seq:
      - id: part_table
        size: 0x400
  epos_partition_table:
    seq:
      - id: magic
        contents: [0x82, 0xB0, 0x4B, 0x87]
      - id: version
        type: u4
      - id: desc_str
        type: u4
      - id: ver_
        type: u4
      - id: unknown
        type: u4
      - id: partition_count
        type: u4
      - id: unknown_2
        type: u4
      - id: offset_1
        type: u4
      - id: part_type
        type: u4
      - id: pad
        type: u4
      - id: part_name
        type: u4
  minfs_table_header:
    doc: "Table header for MINFS partition, points to first entry of file table and provides number of total entries"
    seq:
      - id: magic
        contents: [0x4D ,0x49 ,0x4E ,0x46 ,0x53, 0x00]
      - id: version
        type: u2
      - id: tree_offset
        type: u4
      - id: root_size
        type: u4
      - id: tree_entries
        type: u4
      - id: tree_size
        type: u4
      - id: fdata_length
        type: u4
      - id: image_size
        type: u4
  minfs_table_entry:
    seq:
      - id: flash_offset
        type: u4
      - id: raw_size
        type: u4
      - id: original_size
        type: u4
      - id: entry_length
        type: u2
      - id: flags
        type: u2
        enum: file_type
      - id: name_length
        type: u2
      - id: extra_length
        type: u2
      - id: name
        type: str
        encoding: UTF-8
        size: name_length
      - id: pad
        size: entry_length - name_length - 20
    instances:
      directory_contents:
        io: _root._io
        pos: flash_offset +  0x24400
        type: minfs_table_entry
        size: raw_size
        if: flags == file_type::directory
      file_data:
        io: _root._io
        pos: flash_offset +  0x24400
        size: raw_size
        if: flags != file_type::directory
        
enums:
  file_type:
    1: directory
    0: raw_file
    6: compressed_axf