#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
std::vector<std::vector<bool>> sky_map;
std::vector<std::vector<bool>> is_visited;
std::vector<int> number_of_apartment_per_each_complex;
std::deque<std::pair<int, int>> neighboring_apartments;
int row_step[4] = {-1, 0, 1, 0};
int col_step[4] = {0, -1, 0, 1};

void bfs(int row, int col);

int main() {
    std::string line;
    std::getline(std::cin, line);
    N = stoi(line);
    if (N == 1) {
        std::getline(std::cin, line);
        if (stoi(line) == 1) cout << "1\n1\n";
        else cout << "0\n0\n";
        return 0;
    }

    sky_map.resize(N, std::vector<bool>(N, false));
    is_visited.resize(N, std::vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        for (int k = 0; k < N; ++k) {
            if (line[k] == '0') {
                sky_map[i][k] = false;
                is_visited[i][k] = true;
            } else if (line[k] == '1') {
                sky_map[i][k] = true;
            }
        }
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (sky_map[r][c] && not is_visited[r][c]) {
                bfs(r, c);
            }
        }
    }
    sort(number_of_apartment_per_each_complex.begin(), number_of_apartment_per_each_complex.end());
    cout << number_of_apartment_per_each_complex.size() << "\n";
    for (int i : number_of_apartment_per_each_complex) {
        cout << i << "\n";
    }

    return 0;
}

void bfs(int row, int col) {
    number_of_apartment_per_each_complex.push_back(1);
    neighboring_apartments.clear();
    neighboring_apartments.emplace_back(row, col);
    std::pair<int, int> current;
    int current_row = 0;
    int current_col = 0;
    while (not neighboring_apartments.empty()) {
        current = neighboring_apartments.front();
        neighboring_apartments.pop_front();
        if (current.first != row || current.second != col) {
            ++number_of_apartment_per_each_complex.back();
        }
        for (int i = 0; i < 4; ++i) {
            current_row = current.first + row_step[i];
            current_col = current.second + col_step[i];
            if (0 <= current_row && current_row < N && 0 <= current_col && current_col < N &&
                sky_map[current_row][current_col] && not is_visited[current_row][current_col])
            {
                neighboring_apartments.emplace_back(current_row, current_col);
                is_visited[current_row][current_col] = true;
            }
        }
    }
}
