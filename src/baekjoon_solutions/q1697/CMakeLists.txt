project(q1697)

add_executable(q1697 main_q1697.cpp)

target_include_directories(q1697
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q1697
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q1697
    PRIVATE
        glog)
