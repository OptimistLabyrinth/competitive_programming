project(q2941)

add_executable(q2941 main_q2941.cpp)

target_include_directories(q2941
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q2941
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q2941
    PRIVATE
        glog)
