#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStatic"
#include "ProblemSolving.h"

#include "../commonly_used_algorithms/algorithm_aggregate.h"

using namespace std;

void cpp_17_test_module::competitive_programming::ProblemSolving::Run() {
    run_commonly_used_algorithms();
}

// private
void cpp_17_test_module::competitive_programming::ProblemSolving::run_commonly_used_algorithms() {
    using namespace commonly_used_algorithms;
    bfs_01::BFS bfs; bfs.Run();
    dfs_01::DFS dfs; dfs.Run();
}

#pragma clang diagnostic pop