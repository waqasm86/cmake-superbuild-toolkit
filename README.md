# CMake Superbuild Toolkit
**A Qt-style build tooling demo** that focuses on *reproducible builds, packaging, and downstream consumption*.

This repository is intentionally small in application logic and heavy on build-system patterns typically needed in large, cross-platform C++ frameworks (like Qt): dependency bootstrapping, feature options, install/export, CI, and packaging.

## Why this exists (Build Tools focus)
This project demonstrates:
- **Modern CMake** targets (`MyApp::myapp` alias) and strict target-based usage
- **Superbuild-style dependency management** via `FetchContent`
- **Feature flags** for modular configuration (`MYAPP_ENABLE_TESTS`, `MYAPP_ENABLE_LOGGING`, `MYAPP_ENABLE_PACKAGING`)
- **Install + exported package config** so downstream projects can do `find_package(MyApp CONFIG REQUIRED)`
- **CTest + Catch2** based testing
- **CPack** packaging (TGZ/ZIP)
- **CI matrix** (Linux + Windows, Debug/Release, logging on/off)

## Quick start
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
