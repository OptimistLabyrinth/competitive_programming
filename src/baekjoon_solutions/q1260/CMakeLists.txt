project(q1260)

add_executable(q1260 main_q1260.cpp)

target_include_directories(q1260
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q1260
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q1260
    PRIVATE
        glog)
