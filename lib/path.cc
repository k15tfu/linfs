#include "lib/path.h"

#include <cstddef>

namespace fs {

namespace linfs {

Path Path::Normalize(const char *path_cstr, ErrorCode& error_code) {
  if (path_cstr[0] == '/')
    path_cstr++;
  return Path(path_cstr);
}

std::string Path::FirstName() const {
  // TODO or std::size_t?
  size_t it = data_.find('/');
  if (it == std::string::npos)
    return data_;
  return std::string(data_, 0, it);
}

Path Path::ExceptFirstName() const {
  size_t it = data_.find('/');
  if (it == std::string::npos)
    return Path();
  return Path(data_.c_str() + it);
}

std::string Path::LastName() const {
  size_t it = data_.rfind('/');
  if (it == std::string::npos)
    return data_;
  return std::string(data_, it + 1);
}

Path Path::ExceptLastName() const {
  size_t it = data_.rfind('/');
  if (it == std::string::npos)
    return Path();
  return std::string(data_, 0, it);
}

}  // namespace linfs

}  // namespace fs
