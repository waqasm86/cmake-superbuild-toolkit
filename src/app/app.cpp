#include "myapp/app.h"

#include <fmt/core.h>

#if MYAPP_ENABLE_LOGGING
  #include <spdlog/spdlog.h>
#endif

namespace myapp {

static std::string platform_name() {
#if defined(MYAPP_PLATFORM_WINDOWS)
  return "windows";
#elif defined(MYAPP_PLATFORM_MACOS)
  return "macos";
#elif defined(MYAPP_PLATFORM_LINUX)
  return "linux";
#else
  return "unknown";
#endif
}

Info info() {
  Info out;
  out.platform = platform_name();
  out.logging_enabled = (MYAPP_ENABLE_LOGGING != 0);

#if MYAPP_ENABLE_LOGGING
  spdlog::info("myapp::info() platform={}, logging={}", out.platform, out.logging_enabled);
#endif

  return out;
}

std::string join_with_commas(const std::vector<std::string>& items) {
  if (items.empty()) return {};
  std::string out = items.front();
  for (size_t i = 1; i < items.size(); ++i) {
    out = fmt::format("{},{}", out, items[i]);
  }
  return out;
}

} // namespace myapp
