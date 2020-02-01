#include "DFS.h"

#include <iostream>
#include <deque>

using namespace std;

commonly_used_algorithms::dfs_01::DFS::DFS() = default;

commonly_used_algorithms::dfs_01::DFS::~DFS() = default;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStatic"
void commonly_used_algorithms::dfs_01::DFS::Run() {
//    graph = {
//            {1,  {2, 7, 8}},
//            {2,  {1, 3, 6}},
//            {3,  {2, 4, 5}},
//            {4,  {3}},
//            {5,  {3}},
//            {6,  {2}},
//            {7,  {1}},
//            {8,  {1, 9, 12}},
//            {9,  {8, 10, 11}},
//            {10, {9}},
//            {11, {9}},
//            {12, {8}}
//    };
    graph = {
            {1, {2, 3, 4}},
            {2, {1, 4}},
            {3, {1, 4}},
            {4, {1, 2, 3}}
    };
    is_visited = std::vector<bool>(graph.size(), false);
    int root_vertex = 1;
    is_visited[root_vertex - 1] = true;
    cout << "DFS Travers\n  ";
    dfs_util(root_vertex);
    cout << "\n";
}
#pragma clang diagnostic pop

void commonly_used_algorithms::dfs_01::DFS::dfs_util(const int& current) {
    cout << current;
    deque<int> vertice_nearby;
    for (int i : graph[current]) {
        if (not is_visited[i - 1]) {
            is_visited[i - 1] = true;
            cout << "->";
            dfs_util(i);
        }
    }
}
