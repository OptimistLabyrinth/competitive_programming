#include "BFS.h"

#include <iostream>
#include <deque>
#include <map>
#include <vector>

using namespace std;

commonly_used_algorithms::bfs_01::BFS::BFS() = default;

commonly_used_algorithms::bfs_01::BFS::~BFS() = default;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStatic"
void commonly_used_algorithms::bfs_01::BFS::Run() {
//    map<int, vector<int>> graph = {
//        {1, {2, 3, 4}},
//        {2, {1, 5, 6}},
//        {3, {1}},
//        {4, {1, 7, 8}},
//        {5, {2, 9, 10}},
//        {6, {2}},
//        {7, {4, 11, 12}},
//        {8, {4}},
//        {9, {5}},
//        {10, {5}},
//        {11, {7}},
//        {12, {7}}
//    };
    map<int, vector<int>> graph = {
        {1, {2, 3, 4}},
        {2, {1, 4}},
        {3, {1, 4}},
        {4, {1, 2, 3}}
    };
    vector<bool> is_visited(graph.size(), false);

    int root_vertex = 1;
    deque<int> vertice_nearby(1, root_vertex);
    is_visited[root_vertex - 1] = true;

    cout << "BFS Travers\n  " << std::flush;
    int current_vertex = 0;
    while (not vertice_nearby.empty()) {
        if (current_vertex != 0) {
            cout << "->" << std::flush;
        }
        current_vertex = vertice_nearby.front();
        vertice_nearby.pop_front();
        for (int i : graph[current_vertex]) {
            if (not is_visited[i - 1]) {
                vertice_nearby.push_back(i);
                is_visited[i - 1] = true;
            }
        }
        cout << current_vertex << std::flush;
    }
    cout << "\n";
}
#pragma clang diagnostic pop
