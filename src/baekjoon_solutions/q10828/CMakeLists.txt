project(q10828)

add_executable(q10828 main.cpp)

target_include_directories(q10828
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q10828
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q10828
    PRIVATE
        glog)
