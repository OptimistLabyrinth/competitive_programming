#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int number_of_computers;
int number_of_edges;
map<int, set<int>> network;
std::vector<bool> is_checked;
int infected_count;

void dfs_util(int current);

int main() {
    cin >> number_of_computers;
    cin >> number_of_edges;
    for (int i = 1; i <= number_of_computers; ++i) {
        network[i] = {};
    }
    is_checked.resize(number_of_computers, false);
    int one;
    int two;
    for (int i = 0; i < number_of_edges; ++i) {
        cin >> one >> two;
        network[one].insert(two);
        network[two].insert(one);
    }

    int infected_computer = 1;
    dfs_util(infected_computer);
    cout << infected_count - 1 << "\n";

    return 0;
}

void dfs_util(int current) {
    is_checked[current - 1] = true;
    ++infected_count;
    for (int i : network[current]) {
        if (not is_checked[i - 1]) {
            dfs_util(i);
        }
    }
}
