project(q10773)

add_executable(q10773 main.cpp)

target_include_directories(q10773
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q10773
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q10773
    PRIVATE
        glog)
