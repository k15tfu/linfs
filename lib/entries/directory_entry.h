#pragma once

#include <cstdint>
#include <memory>

#include "fs/error_code.h"
#include "lib/entries/entry.h"
#include "lib/reader_writer.h"
#include "lib/section.h"
#include "lib/section_allocator.h"
#include "lib/section_directory.h"

namespace fs {

namespace linfs {

class DirectoryEntry : public Entry {
 public:
  static std::shared_ptr<DirectoryEntry> Create(const Section& place,
                                                ReaderWriter* reader_writer,
                                                ErrorCode& error_code,
                                                const char *name);

  DirectoryEntry(uint64_t base_offset)
      : Entry(Type::kDirectory, base_offset) {}
  ~DirectoryEntry() override {}

  ErrorCode AddEntry(std::shared_ptr<Entry> entry, ReaderWriter* reader_writer, SectionAllocator* allocator);
  ErrorCode RemoveEntry(std::shared_ptr<Entry> entry,
                        ReaderWriter* reader_writer,
                        SectionAllocator* allocator);
  std::shared_ptr<Entry> FindEntryByName(const char *entry_name,
                                         ReaderWriter* reader_writer,
                                         ErrorCode& error_code,
                                         SectionDirectory* section_directory = nullptr,
                                         SectionDirectory::Iterator *iterator = nullptr);
  ErrorCode GetNextEntryName(const char *prev, ReaderWriter* reader_writer, char* next_buf);
};

}  // namespace linfs

}  // namespace fs
