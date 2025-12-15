#include "myapp/app.h"
#include <fmt/core.h>

int main() {
  const auto i = myapp::info();
  fmt::print("myapp_cli: platform={}, logging={}\n", i.platform, i.logging_enabled);

  const auto s = myapp::join_with_commas({"qt", "cmake", "tooling"});
  fmt::print("joined: {}\n", s);
  return 0;
}
