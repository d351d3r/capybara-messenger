########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(asio_COMPONENT_NAMES "")
set(asio_FIND_DEPENDENCY_NAMES "")

########### VARIABLES #######################################################################
#############################################################################################
set(asio_PACKAGE_FOLDER_RELEASE "/Users/anatolii/.conan2/p/asio052545cf6fbd5/p")
set(asio_BUILD_MODULES_PATHS_RELEASE )


set(asio_INCLUDE_DIRS_RELEASE "${asio_PACKAGE_FOLDER_RELEASE}/include")
set(asio_RES_DIRS_RELEASE )
set(asio_DEFINITIONS_RELEASE "-DASIO_STANDALONE")
set(asio_SHARED_LINK_FLAGS_RELEASE )
set(asio_EXE_LINK_FLAGS_RELEASE )
set(asio_OBJECTS_RELEASE )
set(asio_COMPILE_DEFINITIONS_RELEASE "ASIO_STANDALONE")
set(asio_COMPILE_OPTIONS_C_RELEASE )
set(asio_COMPILE_OPTIONS_CXX_RELEASE )
set(asio_LIB_DIRS_RELEASE )
set(asio_BIN_DIRS_RELEASE )
set(asio_LIBRARY_TYPE_RELEASE UNKNOWN)
set(asio_IS_HOST_WINDOWS_RELEASE 0)
set(asio_LIBS_RELEASE )
set(asio_SYSTEM_LIBS_RELEASE )
set(asio_FRAMEWORK_DIRS_RELEASE )
set(asio_FRAMEWORKS_RELEASE )
set(asio_BUILD_DIRS_RELEASE )
set(asio_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(asio_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${asio_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${asio_COMPILE_OPTIONS_C_RELEASE}>")
set(asio_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${asio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${asio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${asio_EXE_LINK_FLAGS_RELEASE}>")


set(asio_COMPONENTS_RELEASE )