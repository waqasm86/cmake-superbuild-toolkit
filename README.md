# CMake Superbuild Toolkit (Qt-style build tooling demo)

This repository demonstrates build-system engineering patterns commonly required in large C++ frameworks:
- Modern CMake targets + dependency management (superbuild via FetchContent)
- Feature flags and platform-aware logic
- Install + exported targets for downstream consumers
- Automated tests and CI matrix (Linux/Windows)
- Basic packaging with CPack

The focus is **tooling quality and build reliability**, not application complexity.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/myapp_cli
