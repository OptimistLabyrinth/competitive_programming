project(cpp_17_test_module)

add_executable(cpp_17_test_module main.cpp)

target_sources(cpp_17_test_module
    PUBLIC
        commonly_used_algorithms/bfs_01/BFS.cpp
        commonly_used_algorithms/bfs_01/BFS.h
        commonly_used_algorithms/dfs_01/DFS.cpp
        commonly_used_algorithms/dfs_01/DFS.h
        commonly_used_algorithms/algorithm_aggregate.h
        competitive_programming/ProblemSolving.cpp
        competitive_programming/ProblemSolving.h
        test_anything/TestAnything.cpp
        test_anything/TestAnything.h)

target_include_directories(cpp_17_test_module
    PUBLIC
        ${GLOG_INCLUDE_DIR})

target_link_directories(cpp_17_test_module
    PUBLIC
        ${GLOG_LIBRARY_DIR})

target_link_libraries(cpp_17_test_module
    PUBLIC
        glog)
