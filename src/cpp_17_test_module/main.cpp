#include <cstdlib>
#include "glog/logging.h"

#include "competitive_programming/ProblemSolving.h"
#include "test_anything/TestAnything.h"

namespace cpp_17_test_module {

void glog_logging_to_file();
void glog_logging_to_stderr();
void work();

}



int main() {
    FLAGS_minloglevel = google::GLOG_INFO;
//    cpp_17_test_module::glog_logging_to_file();
    cpp_17_test_module::glog_logging_to_stderr();

    cpp_17_test_module::work();

    return 0;
}



void cpp_17_test_module::glog_logging_to_file() {
    FLAGS_logtostderr = false;
    google::SetLogDestination(google::GLOG_INFO, "/home/ksyoo/tmp/glog_log_files/cpp-17-test");
    FLAGS_alsologtostderr = false;
    google::InitGoogleLogging("cpp-17-test main()");
    std::atexit(google::ShutdownGoogleLogging);
}

void cpp_17_test_module::glog_logging_to_stderr() {
    FLAGS_logtostderr = true;
    google::InitGoogleLogging("cpp-17-test main()");
    std::atexit(google::ShutdownGoogleLogging);
}

void cpp_17_test_module::work() {
//    test_anything::TestAnything testAnything;
//    testAnything.Run();

    competitive_programming::ProblemSolving problemSolving;
    problemSolving.Run();
}
