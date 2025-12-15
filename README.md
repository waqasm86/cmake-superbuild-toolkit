![CI](https://github.com/waqasm86/cmake-superbuild-toolkit/actions/workflows/ci.yml/badge.svg)

# CMake Superbuild Toolkit

**A Qt-style build tooling demo** focused on **reproducible builds, packaging, CI, and downstream consumption**.

This repository is intentionally light on application logic and heavy on **build-system architecture**.  
It demonstrates modern CMake patterns commonly required in large, cross-platform C++ frameworks (such as Qt): dependency bootstrapping, feature options, install/export, continuous integration, and packaging.

---

## Why this project exists (Build Tools focus)

This project demonstrates build-system responsibilities typically owned by a **Build Tools** team:

- **Modern CMake** with strict target-based usage and namespaced aliases (`MyApp::myapp`)
- **Superbuild-style dependency management** using `FetchContent`
- **Configurable feature flags** for modular builds
- **Install + exported package config** so downstream projects can use `find_package(...)`
- **CTest + Catch2** based testing
- **CPack** packaging (TGZ / ZIP)
- **CI build matrix** (Linux + Windows, Debug/Release, features on/off)

The design mirrors real-world requirements of large frameworks where:
- consumers must not depend on internal layout
- packaging must be reproducible
- configuration options must remain stable over time

---

## Features

- Dependency bootstrapping via `FetchContent`
- Optional logging (`spdlog`)
- Optional testing (`Catch2`)
- Exported CMake package configuration
- Cross-platform CI (GitHub Actions)
- Binary packaging via CPack

---

## Quick start

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
