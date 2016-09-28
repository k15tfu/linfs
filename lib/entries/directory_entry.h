#pragma once

#include <cstdint>

#include "fs/error_code.h"
#include "lib/entries/entry.h"
#include "lib/reader_writer.h"
#include "lib/sections/section.h"
#include "lib/sections/section_directory.h"
#include "lib/section_allocator.h"

namespace fs {

namespace linfs {

class DirectoryEntry : public Entry {
 public:
  static std::unique_ptr<DirectoryEntry> Create(uint64_t entry_offset,
                                                uint64_t entry_size,
                                                ReaderWriter* writer,
                                                const char* name);

  DirectoryEntry(uint64_t base_offset) : Entry(Type::kDirectory, base_offset) {}
  ~DirectoryEntry() override = default;

  void AddEntry(const Entry* entry, ReaderWriter* reader_writer, SectionAllocator* allocator);
  bool RemoveEntry(const Entry* entry,
                   ReaderWriter* reader_writer,
                   SectionAllocator* allocator);
  bool HasEntries(ReaderWriter* reader);
  std::unique_ptr<Entry> FindEntryByName(const char* entry_name,
                                         ReaderWriter* reader);
  uint64_t GetNextEntryName(uint64_t cursor, ReaderWriter* reader, char* next_buf);

 private:
  SectionDirectory CursorToSection(uint64_t& cursor, ReaderWriter* reader);
  static void ClearEntries(uint64_t entries_offset, uint64_t entries_end, ReaderWriter* writer);
};

}  // namespace linfs

}  // namespace fs
