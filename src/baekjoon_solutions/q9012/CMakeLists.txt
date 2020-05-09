project(q9012)

add_executable(q9012 main.cpp)

target_include_directories(q9012
    PRIVATE
        ${GLOG_INCLUDE_DIR})

target_link_directories(q9012
    PRIVATE
        ${GLOG_LIBRARY_DIR})

target_link_libraries(q9012
    PRIVATE
        glog)
