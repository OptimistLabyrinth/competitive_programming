project(q7569)

add_executable(q7569 main_q7569.cpp)

target_include_directories(q7569
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q7569
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q7569
    PRIVATE
        glog)
