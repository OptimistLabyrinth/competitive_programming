#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-concat-nested-namespaces"
#ifndef CPP_17_TEST_DFS_01_H
#define CPP_17_TEST_DFS_01_H

#include <map>
#include <vector>

namespace commonly_used_algorithms {
namespace dfs_01 {

class DFS {
public:
    DFS();
    ~DFS();
    void Run();

private:
    void dfs_util(const int& current);

    std::map<int, std::vector<int>> graph;
    std::vector<bool> is_visited;
};

} // namespace dfs_01
} // namespace commonly_used_algorithms

#endif // CPP_17_TEST_DFS_01_H

#pragma clang diagnostic pop