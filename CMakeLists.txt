cmake_minimum_required(VERSION 3.29)

if (DEFINED ENV{USE_VCPKG_TOOLCHAIN} AND "$ENV{USE_VCPKG_TOOLCHAIN}" STREQUAL "1")
    set(CMAKE_TOOLCHAIN_FILE "E:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

project(IpFilter VERSION 1.0.0)

option(WITH_GTEST "Whether to build Google test" ON)

add_executable(ip_filter 
ip_filter.cpp
)
add_library(ip_filter_lib
IpAddress.cpp IpAddress.h
IpList.cpp IpList.h
)

set_target_properties(ip_filter ip_filter_lib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_filter_lib PRIVATE 
	"${CMAKE_BINARY_DIR}"
)

target_link_libraries(ip_filter PRIVATE
    ip_filter_lib
)

if (MSVC)
    target_compile_options(ip_filter PRIVATE /W4)
	target_compile_options(ip_filter_lib PRIVATE /W4)
else ()
    target_compile_options(ip_filter PRIVATE -Wall -Wextra -pedantic) 
	target_compile_options(ip_filter_lib PRIVATE -Wall -Wextra -pedantic)
endif()

if(WITH_GTEST)
	if(POLICY CMP0135)
	cmake_policy(SET CMP0135 NEW)
	set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
	endif()

	find_package(GTest CONFIG REQUIRED)
	add_executable(Gtests gtests.cpp)
	
	set_target_properties(Gtests PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
	)
	
	target_link_libraries(Gtests PRIVATE 
	GTest::gtest 
	GTest::gtest_main
	)
	
	target_link_libraries(Gtests PUBLIC 
	ip_filter_lib
	)
	
	if (MSVC)
	    target_compile_options(Gtests PRIVATE /W4)
	else ()
	    target_compile_options(Gtests PRIVATE -Wall -Wextra -pedantic)
	endif()
	
	add_custom_command(
	    TARGET Gtests POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv
		${CMAKE_CURRENT_BINARY_DIR}
	)
	
	enable_testing()
	add_test(NAME GTEST COMMAND Gtests)
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)




