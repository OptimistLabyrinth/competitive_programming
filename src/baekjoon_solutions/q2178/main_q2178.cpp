#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int horizontal_length;
int vertical_length;
vector<vector<bool>> maze;
vector<vector<bool>> is_visited;
deque<pair<int, int>> neighboring_paths;
int number_of_needed_pop_front;
int current_new_path_count;
int row_step[4] = {-1, 0, 1, 0};
int col_step[4] = {0, -1, 0, 1};
int path_length;

void add_new_path_if_possible(const pair<int, int>& current);

int main() {
    std::string line;
    std::string token;
    std::getline(std::cin, line);
    {
        std::stringstream ss(line);
        std::getline(ss, token, ' ');
        vertical_length = stoi(token);
        std::getline(ss, token);
        horizontal_length = stoi(token);
    }
    maze.resize(vertical_length, vector<bool>(horizontal_length, false));
    is_visited.resize(vertical_length, vector<bool>(horizontal_length, false));
    for (int c = 0; c < vertical_length; ++c) {
        std::getline(std::cin, line);
        for (int r = 0; r < horizontal_length; ++r) {
            if (line[r] == '1') {
                maze[c][r] = true;
            } else if (line[r] == '0') {
                maze[c][r] = false;
            }
        }
    }
    neighboring_paths.emplace_back(0, 0);
    is_visited[0][0] = true;
    number_of_needed_pop_front = 1;
    pair<int, int> current(0, 0);
    bool found_path = false;
    while (not neighboring_paths.empty()) {
        current_new_path_count = 0;
        for (int i = 0; i < number_of_needed_pop_front; ++i) {
            current = neighboring_paths.front();
            neighboring_paths.pop_front();
            if (current.first == horizontal_length - 1 and current.second == vertical_length - 1) {
                found_path = true;
                break;
            }
            add_new_path_if_possible(current);
        }
        if (found_path) {
            break;
        }
        number_of_needed_pop_front = current_new_path_count;
        ++path_length;
    }
    cout << path_length + 1<< "\n";
    return 0;
}

void add_new_path_if_possible(const pair<int, int>& current) {
    int current_row = 0;
    int current_col = 0;
    for (int i = 0; i < 4; ++i) {
        current_row = current.first + row_step[i];
        current_col = current.second + col_step[i];
        if (0 <= current_row and current_row < horizontal_length and
            0 <= current_col and current_col < vertical_length and
            maze[current_col][current_row] and not is_visited[current_col][current_row])
        {
            neighboring_paths.emplace_back(current_row, current_col);
            is_visited[current_col][current_row] = true;
            ++current_new_path_count;
        }
    }
}
