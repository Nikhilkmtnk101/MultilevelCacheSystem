cmake_minimum_required(VERSION 3.27)
project(MultilevelCacheSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultilevelCacheSystem
        main.cpp
        eviction_policy/LRUEvictionPolicy.hpp
)

include_directories(${CMAKE_SOURCE_DIR}/models)
include_directories(${CMAKE_SOURCE_DIR}/storage)
include_directories(${CMAKE_SOURCE_DIR}/utility)
include_directories(${CMAKE_SOURCE_DIR}/eviction_policy)
include_directories(${CMAKE_SOURCE_DIR}/cache_provider)
include_directories(${CMAKE_SOURCE_DIR}/level_cache)
include_directories(${CMAKE_SOURCE_DIR}/service)

