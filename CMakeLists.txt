cmake_minimum_required(VERSION 3.29) #не тестировалась на версиях ниже, поэтому так. Хотя безусловно будет на них работать :)

project(IpFilter VERSION 0.0.1)

add_executable(main main.cpp)

set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(main PRIVATE 
	"${CMAKE_BINARY_DIR}"
)

install(TARGETS main RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)