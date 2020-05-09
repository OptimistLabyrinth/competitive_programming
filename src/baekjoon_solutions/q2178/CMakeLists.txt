project(q2178)

add_executable(q2178 main_q2178.cpp)

target_include_directories(q2178
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q2178
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q2178
    PRIVATE
        glog)
