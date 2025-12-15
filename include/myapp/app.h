#pragma once
#include <string>
#include <vector>

namespace myapp {

struct Info {
  std::string platform;
  bool logging_enabled;
};

Info info();
std::string join_with_commas(const std::vector<std::string>& items);

} // namespace myapp
