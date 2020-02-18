cmake_minimum_required(VERSION 3.0.0)
project(Graph VERSION 0.1.0)

set(SOURCE_FILES main.cpp Edge.cpp EdgeParserImpl.cpp PriorityQueue.cpp EdgeParserWeightedImpl.cpp Graph.cpp DiGraph.cpp WeightedGraph.cpp )
include_directories( ./ )
link_directories( ./ )

include(CTest)
enable_testing()


add_executable(Graph ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
