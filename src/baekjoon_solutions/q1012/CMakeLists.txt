project(q1012)

add_executable(q1012 main_q1012.cpp)

target_include_directories(q1012
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q1012
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q1012
    PRIVATE
        glog)
