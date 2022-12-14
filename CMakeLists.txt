cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(02_ip_filtration VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

add_executable(02_ip_filtration 
				main.cpp main.h
				filter.cpp filter.h
				print.cpp print.h
				readData.cpp readData.h
				sort.cpp sort.h
				split.cpp split.h)

set_target_properties(02_ip_filtration PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(02_ip_filtration
    PRIVATE "${CMAKE_BINARY_DIR}"
)

install(TARGETS 02_ip_filtration RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT alexsh93@live.ru)
include(CPack)