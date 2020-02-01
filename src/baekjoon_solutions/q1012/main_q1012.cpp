#include <deque>
#include <iostream>
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

void run_test();
void bfs(int row, int col);

int main() {
    cin >> number_of_test_case;
    for (int test_case = 0; test_case < number_of_test_case; ++test_case) {
        run_test();
    }
    return 0;
}

void run_test() {
    cin >> horizontal_length >> vertical_length >> number_of_cabbage;
    cabbage_farm.resize(vertical_length, vector<bool>(horizontal_length, false));
    has_earthworm.resize(vertical_length, vector<bool>(horizontal_length, false));
    int L = 0;
    int R = 0;
    for (int count = 0; count < number_of_cabbage; ++count) {
        cin >> L >> R;
        cabbage_farm[R][L] = true;
    }
    number_of_needed_earthworm_for_each_test_case = 0;
    for (int c = 0; c < vertical_length; ++c) {
        for (int r = 0; r < horizontal_length; ++r) {
            if (cabbage_farm[c][r] and not has_earthworm[c][r]) {
                bfs(r, c);
                ++number_of_needed_earthworm_for_each_test_case;
            }
        }
    }
    cout << number_of_needed_earthworm_for_each_test_case << "\n";
    cabbage_farm.clear();
    has_earthworm.clear();
    neighboring_cabbage.clear();
    std::cin.ignore();
}

void bfs(int row, int col) {
    neighboring_cabbage.emplace_back(row, col);
    pair<int, int> current(0, 0);
    int current_row = 0;
    int current_col = 0;
    while (not neighboring_cabbage.empty()) {
        current = neighboring_cabbage.front();
        neighboring_cabbage.pop_front();
        for (int i = 0; i < 4; ++i) {
            current_row = current.first + row_step[i];
            current_col = current.second + col_step[i];
            if (0 <= current_row && current_row < horizontal_length and
                0 <= current_col && current_col < vertical_length and
                cabbage_farm[current_col][current_row] and not has_earthworm[current_col][current_row])
            {
                neighboring_cabbage.emplace_back(current_row, current_col);
                has_earthworm[current_col][current_row] = true;
            }
        }
    }
}
