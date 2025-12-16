![CI](https://github.com/waqasm86/cmake-superbuild-toolkit/actions/workflows/ci.yml/badge.svg)

# CMake Superbuild Toolkit

A **Qt-style build tooling demo** focused on **reproducible builds, packaging, CI, and downstream consumption**.

This repository is intentionally light on application logic and heavy on **build-system architecture**.  
The C++ code is intentionally minimal — the goal is to demonstrate build tooling patterns used in large, cross-platform C++ frameworks (like Qt): dependency bootstrapping, feature options, install/export, continuous integration, and packaging.

---

## What this repository demonstrates

- **Modern CMake**: target-based usage, exported targets, and namespaced aliases (e.g. `MyApp::myapp`)
- **Dependency bootstrapping** using `FetchContent` (spdlog, Catch2)
- **Feature flags** (e.g. `MYAPP_ENABLE_LOGGING`, `MYAPP_ENABLE_TESTS`)
- **Install + export** so downstream projects can use `find_package(MyApp CONFIG REQUIRED)`
- **CTest + Catch2** for tests
- **CPack** packaging (TGZ / ZIP)
- **CI matrix**: Linux + Windows, Debug/Release, feature ON/OFF combinations

---

## CI build matrix

The GitHub Actions workflow builds and tests:

- **Ubuntu**: Debug + Release, logging ON/OFF
- **Windows**: Debug + Release, logging ON/OFF

(Artifacts are *not* committed; build outputs and CPack directories are ignored via `.gitignore`.)

---

## Project layout

- `src/` — minimal C++ targets (demo application + library)
- `tests/` — Catch2 tests (enabled via option)
- `packaging/` — CPack configuration
- `cmake/` — CMake modules/helpers
- `.github/workflows/` — CI pipeline

---

## Prerequisites

- CMake 3.22+ (3.24+ recommended)
- A C++17 compiler (GCC/Clang/MSVC)
- Git

Dependencies (spdlog, Catch2) are fetched automatically via `FetchContent`.

---

## Quick start

### Configure + build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
