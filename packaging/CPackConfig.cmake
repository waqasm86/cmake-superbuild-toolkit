# CPack configuration
#
# IMPORTANT: Set CPACK_* variables *before* including CPack.

set(CPACK_PACKAGE_NAME "CMakeSuperbuildToolkit")
set(CPACK_PACKAGE_VENDOR "waqasm86")
set(CPACK_PACKAGE_CONTACT "waqasm86")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")

# Stable filename across generators
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}")

# Cross-platform generators:
# - Windows: ZIP is safe on runners
# - Linux/macOS: TGZ + ZIP works on GitHub runners
if(WIN32)
  set(CPACK_GENERATOR "ZIP")
else()
  set(CPACK_GENERATOR "TGZ;ZIP")
endif()

include(CPack)
