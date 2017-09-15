cmake_minimum_required (VERSION 2.6.2)
project (cereal-yaml)

if(NOT CMAKE_VERSION VERSION_LESS 3.0) # installing cereal-yaml requires INTERFACE lib
    option(JUST_INSTALL_CEREAL_YAML "Don't do anything besides installing the library" OFF)
endif()

option(THREAD_SAFE "Use mutexes to ensure thread safety" OFF)
if(THREAD_SAFE)
    add_definitions(-DCEREAL_YAML_THREAD_SAFE=1)
    set(CEREAL_YAML_THREAD_LIBS "pthread")
else()
    set(CEREAL_YAML_THREAD_LIBS "")
endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /W3 /WX")
else()
    set(CMAKE_CXX_FLAGS "-Wall -g -Wextra -Wshadow -pedantic -Wold-style-cast ${CMAKE_CXX_FLAGS}")
    option(WITH_WERROR "Compile with '-Werror' C++ compiler flag" OFF)
    if(WITH_WERROR)
        set(CMAKE_CXX_FLAGS "-Werror ${CMAKE_CXX_FLAGS}")
    endif(WITH_WERROR)
    if(CMAKE_VERSION VERSION_LESS 3.1)
        set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
    else()
        if(NOT DEFINED CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD STREQUAL "98")
            set(CMAKE_CXX_STANDARD 11)
        endif()
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
    endif()
endif()

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    add_library(cereal-yaml INTERFACE)
    target_include_directories(cereal-yaml INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )
    install(TARGETS cereal-yaml EXPORT cereal-yaml
        DESTINATION lib) # ignored
    install(EXPORT cereal-yaml FILE cereal-yaml-config.cmake
        DESTINATION share/cmake/cereal-yaml)
    install(DIRECTORY include/cereal-yaml DESTINATION include)
endif()

if(JUST_INSTALL_CEREAL_YAML)
    return()
endif()

include_directories(./include)
include_directories(cereal/include)
include_directories(cereal/unittests)
include_directories(yaml-cpp/include)
add_subdirectory(yaml-cpp)

# Boost serialization for performance sandbox
find_package(Boost COMPONENTS serialization)

if(Boost_FOUND)
  include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif(Boost_FOUND)

enable_testing()
add_subdirectory(unittests)
add_subdirectory(example)
