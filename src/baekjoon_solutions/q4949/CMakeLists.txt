project(q4949)

add_executable(q4949 main.cpp)

target_include_directories(q4949
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q4949
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q4949
    PRIVATE
        glog)
