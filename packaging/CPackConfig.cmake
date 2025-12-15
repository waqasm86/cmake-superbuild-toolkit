include(CPack)

set(CPACK_PACKAGE_NAME "myapp-toolkit")
set(CPACK_PACKAGE_VENDOR "waqasm86")
set(CPACK_PACKAGE_CONTACT "waqasm86")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# Simple, cross-platform defaults
set(CPACK_GENERATOR "TGZ;ZIP")
