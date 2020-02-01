#include <deque>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int number_of_test_case;
int horizontal_length;
int vertical_length;
int number_of_cabbage;
vector<vector<bool>> cabbage_farm;
vector<vector<bool>> has_earthworm;
int number_of_needed_earthworm_for_each_test_case;
deque<pair<int, int>> neighboring_cabbage;
int row_step[4] = {-1, 0, 1, 0};
int col_step[4] = {0, -1, 0, 1};

void bfs(int row, int col);

int main() {
    std::string line;
    std::string token;
    int L = 0;
    int R = 0;
    std::getline(std::cin, line);
    number_of_test_case = stoi(line);
    int test_case = 0;
    while (test_case++ < number_of_test_case) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::getline(ss, token, ' ');
        horizontal_length = stoi(token);
        std::getline(ss, token, ' ');
        vertical_length = stoi(token);
        std::getline(ss, token);
        number_of_cabbage = stoi(token);
        if (number_of_cabbage == 0) {
            cout << "0\n";
            continue;
        }
        else if (number_of_cabbage == 1) {
            cout << "1\n";
            continue;
        }
        cabbage_farm.resize(vertical_length, vector<bool>(horizontal_length, false));
        has_earthworm.resize(vertical_length, vector<bool>(horizontal_length, false));
        for (int i = 0; i < number_of_cabbage; ++i) {
            std::getline(std::cin, line);
            std::stringstream ss2(line);
            std::getline(ss2, token, ' ');
            L = stoi(token);
            std::getline(ss2, token);
            R = stoi(token);
            cabbage_farm[R][L] = true;
        }

//        cout << "\n";
//        for (int c = 0; c < vertical_length; ++c) {
//            for (int r = 0; r < horizontal_length; ++r) {
//                cout << "(" << r << "," << c << ")=" << cabbage_farm[c][r] << " " << std::flush;
//            }
//            cout << "\n" << std::flush;
//        }

        number_of_needed_earthworm_for_each_test_case = 0;
        for (int c = 0; c < vertical_length; ++c) {
            for (int r = 0; r < horizontal_length; ++r) {
                if (cabbage_farm[c][r] && not has_earthworm[c][r]) {
                    bfs(r, c);
                    ++number_of_needed_earthworm_for_each_test_case;
                }
            }
        }
        cout << number_of_needed_earthworm_for_each_test_case << "\n";
    }

    return 0;
}

void bfs(int row, int col) {
    cout << "bfs(" << row << "," << col << ") START\n";
    neighboring_cabbage.emplace_back(row, col);
    has_earthworm[col][row] = true;
    pair<int, int> current(0, 0);
    int current_row = 0;
    int current_col = 0;
    while (not neighboring_cabbage.empty()) {
        current = neighboring_cabbage.front();
        neighboring_cabbage.pop_front();
        cout << "    row: " << current.first << ", col: " << current.second << "\n";
        for (int i = 0; i < 4; ++i) {
            current_row = current.first + row_step[i];
            current_col = current.second + col_step[i];
            if (0 <= current_row && current_row < horizontal_length &&
                0 <= current_col && current_col < vertical_length &&
                cabbage_farm[current_col][current_row] && not has_earthworm[current_col][current_row])
            {
                neighboring_cabbage.emplace_back(current_row, current_col);
                has_earthworm[current_col][current_row] = true;
            }
        }
    }
}
