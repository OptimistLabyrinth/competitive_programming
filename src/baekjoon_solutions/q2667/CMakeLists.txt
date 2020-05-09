project(q2667)

add_executable(q2667 main_q2667.cpp)

target_include_directories(q2667
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q2667
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q2667
    PRIVATE
        glog)
