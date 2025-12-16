set(CPACK_PACKAGE_NAME "myapp-toolkit")
set(CPACK_PACKAGE_VENDOR "waqasm86")
set(CPACK_PACKAGE_CONTACT "waqasm86")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# Prefer safe generators per-platform
if(WIN32)
  set(CPACK_GENERATOR "ZIP")
else()
  set(CPACK_GENERATOR "TGZ;ZIP")
endif()

include(CPack)
