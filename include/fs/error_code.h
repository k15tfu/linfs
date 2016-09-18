// error_code.h -- Error codes

#pragma once

#include <cstdint>

namespace fs {

enum class ErrorCode : uint8_t {
  // Common:
  kSuccess = 0,             // ok: no error
  kErrorNoMemory,           // error: no memory
  kErrorExist,              // error: file or directory already exists
  kErrorExists,
  kErrorNotFound,           // error: file or directory not found
  kErrorNotSupported,       // error: operation not supported

  // Device and system errors:
  kErrorDeviceUnknown,      // error: unknown error while opening a device
  kErrorInvalidSignature,   // error: invalid device signature
  kErrorFormat,             // error: invalid format, device is corrupted
  kErrorInputOutput,        // error: input/output system error

  // Directory errors:
  kErrorIsDirectory,        // error: it is a directory
  kErrorNotDirectory,       // error: not a directory
  kErrorDirectoryNotEmpty,  // error: directory not empty

  // File errors:
  // TODO? remove these
  kErrorNoData,             // error: no data
  kErrorBrokenFile,         // error: file entry is broken
};

}  // namespace fs
