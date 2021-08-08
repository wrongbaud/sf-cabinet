# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

from pkg_resources import parse_version
import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import Enum


if parse_version(kaitaistruct.__version__) < parse_version('0.9'):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Sfbin(KaitaiStruct):

    class FileType(Enum):
        raw_file = 0
        directory = 1
        compressed_axf = 6
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.bt0 = Sfbin.Bt0Data(self._io, self, self._root)
        self.bt1 = Sfbin.Bt1Data(self._io, self, self._root)
        self.epos_ptable = Sfbin.EposPlaceholder(self._io, self, self._root)
        self.minfs_header = Sfbin.MinfsTableHeader(self._io, self, self._root)
        self.minfs_pad = self._io.read_bytes((self.minfs_header.tree_offset - 32))
        self.minfs_file_table = [None] * (self.minfs_header.tree_entries)
        for i in range(self.minfs_header.tree_entries):
            self.minfs_file_table[i] = Sfbin.MinfsTableEntry(self._io, self, self._root)


    class Bt0Data(KaitaiStruct):
        """First stage bootloader controls jump to FEL."""
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.bt0_data = self._io.read_bytes(24576)


    class EposPartitionTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(4)
            if not self.magic == b"\x82\xB0\x4B\x87":
                raise kaitaistruct.ValidationNotEqualError(b"\x82\xB0\x4B\x87", self.magic, self._io, u"/types/epos_partition_table/seq/0")
            self.version = self._io.read_u4le()
            self.desc_str = self._io.read_u4le()
            self.ver_ = self._io.read_u4le()
            self.unknown = self._io.read_u4le()
            self.partition_count = self._io.read_u4le()
            self.unknown_2 = self._io.read_u4le()
            self.offset_1 = self._io.read_u4le()
            self.part_type = self._io.read_u4le()
            self.pad = self._io.read_u4le()
            self.part_name = self._io.read_u4le()


    class MinfsTableEntry(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.entry_addr = self._io.pos()
            self.flash_offset = self._io.read_u4le()
            self.raw_size = self._io.read_u4le()
            self.original_size = self._io.read_u4le()
            self.entry_length = self._io.read_u2le()
            self.flags = KaitaiStream.resolve_enum(Sfbin.FileType, self._io.read_u2le())
            self.name_length = self._io.read_u2le()
            self.extra_length = self._io.read_u2le()
            self.name = (self._io.read_bytes(self.name_length)).decode(u"UTF-8")
            self.pad = self._io.read_bytes(((self.entry_length - self.name_length) - 20))

        def __str__(self):
            entrystr = f"Name: {self.name}\n"
            entrystr += f"\tFile Type: {self.flags}"
            entrystr += f"\tRaw Size: {self.raw_size:#04x}\n"
            entrystr += f"\tOriginal Size: {self.original_size:#04x}\n"
            return entrystr

        @property
        def directory_contents(self):
            if hasattr(self, '_m_directory_contents'):
                return self._m_directory_contents if hasattr(self, '_m_directory_contents') else None

            if self.flags == Sfbin.FileType.directory:
                io = self._root._io
                _pos = io.pos()
                io.seek((self.flash_offset + 148480))
                self._raw__m_directory_contents = io.read_bytes(self.raw_size)
                _io__raw__m_directory_contents = KaitaiStream(BytesIO(self._raw__m_directory_contents))
                self._m_directory_contents = Sfbin.MinfsTableEntry(_io__raw__m_directory_contents, self, self._root)
                io.seek(_pos)

            return self._m_directory_contents if hasattr(self, '_m_directory_contents') else None

        @property
        def file_data(self):
            if hasattr(self, '_m_file_data'):
                return self._m_file_data if hasattr(self, '_m_file_data') else None

            if self.flags != Sfbin.FileType.directory:
                io = self._root._io
                _pos = io.pos()
                io.seek((self.flash_offset + 148480))
                self._m_file_data = io.read_bytes(self.raw_size)
                io.seek(_pos)

            return self._m_file_data if hasattr(self, '_m_file_data') else None


    class Bt1Data(KaitaiStruct):
        """Second stage bootloader, FEL loader lives here as well."""
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.bt1_data = self._io.read_bytes(122880)


    class EposPlaceholder(KaitaiStruct):
        """Simple placeholder for overarching partition table that is not fully understood yet."""
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.part_table = self._io.read_bytes(1024)


    class MinfsTableHeader(KaitaiStruct):
        """Table header for MINFS partition, points to first entry of file table and provides number of total entries."""
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(6)
            if not self.magic == b"\x4D\x49\x4E\x46\x53\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x4D\x49\x4E\x46\x53\x00", self.magic, self._io, u"/types/minfs_table_header/seq/0")
            self.version = self._io.read_u2le()
            self.tree_offset = self._io.read_u4le()
            self.root_size = self._io.read_u4le()
            self.tree_entries = self._io.read_u4le()
            self.tree_size = self._io.read_u4le()
            self.fdata_length = self._io.read_u4le()
            self.image_size = self._io.read_u4le()
