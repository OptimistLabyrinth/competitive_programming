project(q2606)

add_executable(q2606 main_q2606.cpp)

target_include_directories(q2606
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q2606
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q2606
    PRIVATE
        glog)
