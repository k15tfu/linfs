#pragma once

#include <exception>

#include "fs/error_code.h"

namespace fs {

namespace linfs {

class ExceptionHandler {
 public:
  // TODO? rename ExceptionToErrorCode
  static ErrorCode ToErrorCode(std::exception_ptr exception_pointer) noexcept;
};

}  // namespace linfs

}  // namespace fs
