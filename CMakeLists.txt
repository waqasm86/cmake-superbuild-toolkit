cmake_minimum_required(VERSION 3.24)

project(CMakeSuperbuildToolkit
  VERSION 0.1.0
  DESCRIPTION "Qt-style CMake superbuild + packaging + CI example for modern C++ tooling"
  LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(MYAPP_ENABLE_TESTS     "Build tests" ON)
option(MYAPP_ENABLE_PACKAGING "Enable CPack packaging" ON)
option(MYAPP_ENABLE_LOGGING   "Enable spdlog logging" ON)

# ---- Tooling quality defaults
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Helpful for tooling projects
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Dependencies (superbuild style)
include(cmake/Dependencies/fmt.cmake)

if(MYAPP_ENABLE_LOGGING)
  include(cmake/Dependencies/spdlog.cmake)
endif()

# ---- Library
add_library(myapp STATIC)
add_library(MyApp::myapp ALIAS myapp)

target_sources(myapp
  PRIVATE
    src/app/app.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/myapp/app.h
)

target_include_directories(myapp
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(myapp
  PUBLIC
    fmt::fmt
)

target_compile_definitions(myapp PUBLIC MYAPP_ENABLE_LOGGING=$<BOOL:${MYAPP_ENABLE_LOGGING}>)


if(MYAPP_ENABLE_LOGGING)
  target_link_libraries(myapp PRIVATE spdlog::spdlog_header_only)
endif()

# Platform markers (Qt-style pragmatism)
if(WIN32)
  target_compile_definitions(myapp PUBLIC MYAPP_PLATFORM_WINDOWS=1)
elseif(APPLE)
  target_compile_definitions(myapp PUBLIC MYAPP_PLATFORM_MACOS=1)
elseif(UNIX)
  target_compile_definitions(myapp PUBLIC MYAPP_PLATFORM_LINUX=1)
endif()

# ---- CLI executable
add_executable(myapp_cli src/main.cpp)
target_link_libraries(myapp_cli PRIVATE MyApp::myapp)

# ---- Install + Export (very important signal for Qt tooling)
install(TARGETS myapp myapp_cli
  EXPORT MyAppTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT MyAppTargets
  FILE MyAppTargets.cmake
  NAMESPACE MyApp::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyApp
)

# Package config
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyAppConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/MyAppConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyApp
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/MyAppConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MyAppConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/MyAppConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyApp
)

# ---- Tests
if(MYAPP_ENABLE_TESTS)
  enable_testing()
  include(cmake/Dependencies/catch2.cmake)

  add_executable(test_myapp tests/test_app.cpp)
  target_link_libraries(test_myapp PRIVATE MyApp::myapp Catch2::Catch2WithMain)

  add_test(NAME myapp.unit COMMAND test_myapp)
endif()

# ---- Packaging
if(MYAPP_ENABLE_PACKAGING)
  include(packaging/CPackConfig.cmake)
endif()
