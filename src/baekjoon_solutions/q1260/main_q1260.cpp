#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <vector>

using namespace std;

int number_of_vertex;
int number_of_edge;
int root_vertex;
std::map<int, std::set<int>> graph;
std::vector<bool> is_visited;
std::deque<int> vertice_nearby;

void dfs_traverse();
void dfs_util(int current);
void bfs_traverse();

int main() {
    cin >> number_of_vertex >> number_of_edge >> root_vertex;
    if (number_of_vertex == 1) {
        cout << "1\n1\n";
        return 0;
    }

    for (int i = 1; i <= number_of_vertex; ++i) {
        graph[i] = {};
    }
    int left = 0;
    int right = 0;
    for (int i = 0; i < number_of_edge; ++i) {
        cin >> left >> right;
        graph[left].insert(right);
        graph[right].insert(left);
    }
    is_visited.resize(number_of_vertex, false);

    dfs_traverse();
    for (auto&& i : is_visited) {
        i = false;
    }
    bfs_traverse();

    return 0;
}

void dfs_traverse() {
    dfs_util(root_vertex);
    cout << "\n";
}

void dfs_util(int current) {
    is_visited[root_vertex - 1] = true;
    cout << current;
    for (int i : graph[current]) {
        if (not is_visited[i - 1]) {
            is_visited[i - 1] = true;
            cout << " ";
            dfs_util(i);
        }
    }
}

void bfs_traverse() {
    vertice_nearby.push_back(root_vertex);
    is_visited[root_vertex - 1] = true;
    int current = 0;
    while (not vertice_nearby.empty()) {
        if (current != 0) {
            cout << " ";
        }
        current = vertice_nearby.front();
        vertice_nearby.pop_front();
        for (int i : graph[current]) {
            if (not is_visited[i - 1]) {
                vertice_nearby.push_back(i);
                is_visited[i - 1] = true;
            }
        }
        cout << current;
    }
    cout << "\n";
}
