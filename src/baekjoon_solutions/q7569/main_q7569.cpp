#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include <unistd.h>

using namespace std;

struct tomato {
    tomato(int row, int col, int height) : row(row), col(col), height(height) {}
    bool operator== (const tomato& v) {
        return row == v.row and col == v.col and height == v.height;
    }
    int row;
    int col;
    int height;
};

int horizontal_length;
int vertical_length;
int height_lenght;
vector<vector<vector<int>>> tomato_box;
int row_step[6] = {-1, 0, 1, 0, 0, 0};
int col_step[6] = {0, -1, 0, 1, 0, 0};
int layer_step[6] = {0, 0, 0, 0, 1, -1};
int number_of_initially_unripped_tomato;
int peiods_until_tomato_ripped;
vector<tomato> currently_ripped_tomato;
vector<tomato> newly_ripped_tomato_vector;

void ripe_adjacent_tomato();
bool cannot_ripe_all_tomato();

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> horizontal_length >> vertical_length >> height_lenght;
    tomato_box.resize(height_lenght);
    for (auto& square : tomato_box) { square.resize(vertical_length, vector<int>(horizontal_length, 0)); }
    number_of_initially_unripped_tomato = 0;
    for (int h = 0; h < height_lenght; ++h) {
        for (int c = 0; c < vertical_length; ++c) {
            for (int r = 0; r < horizontal_length; ++r) {
                std::cin >> tomato_box[h][c][r];
                if (tomato_box[h][c][r] == 0) {
                    ++number_of_initially_unripped_tomato;
                }
            }
        }
    }

//    for (int h = 0; h < height_lenght; ++h) {
//        for (int c = 0; c < vertical_length; ++c) {
//            for (int r = 0; r < horizontal_length; ++r) {
//                cout << setw(2) << tomato_box[h][c][r] << " ";
//            }
//            cout << "\n";
//        }
//    }

    if (number_of_initially_unripped_tomato == 0) {
        cout << "0\n";
        return 0;
    }

    while (true) {
        ripe_adjacent_tomato();
        if (newly_ripped_tomato_vector.empty()) {
            break;
        }
        ++peiods_until_tomato_ripped;
        sleep(1);
    }

    if (cannot_ripe_all_tomato()) {
        cout << "-1\n";
    } else {
        cout << peiods_until_tomato_ripped << "\n";
    }

    return 0;
}

void ripe_adjacent_tomato() {
    currently_ripped_tomato.clear();
    newly_ripped_tomato_vector.clear();
    for (int h = 0; h < height_lenght; ++h) {
        for (int c = 0; c < vertical_length; ++c) {
            for (int r = 0; r < horizontal_length; ++r) {
                if (tomato_box[h][c][r] == 1) {
                    currently_ripped_tomato.emplace_back(r, c, h);
                }
            }
        }
    }
//    cout << "< tomato bax >\n";
//    for (int h = 0; h < height_lenght; ++h) {
//        for (int c = 0; c < vertical_length; ++c) {
//            for (int r = 0; r < horizontal_length; ++r) {
//                cout << setw(2) << tomato_box[h][c][r] << " ";
//            }
//            cout << "\n";
//        }
//    }
    int current_row = 0;
    int current_col = 0;
    int current_height = 0;
    for (const auto& v : currently_ripped_tomato) {
        for (int i = 0; i < 6; ++i) {
            current_row = v.row + row_step[i];
            current_col = v.col + col_step[i];
            current_height = v.height + layer_step[i];
            if (0 <= current_row and current_row < horizontal_length and
                0 <= current_col and current_col < vertical_length and
                0 <= current_height and current_height < height_lenght and
                tomato_box[current_height][current_col][current_row] == 0)
            {
                newly_ripped_tomato_vector.emplace_back(current_row, current_col, current_height);
            }
        }
    }
    std::unique(newly_ripped_tomato_vector.begin(), newly_ripped_tomato_vector.end());
//    cout << "number of newly matured tomato: " << newly_ripped_tomato_vector.size() << "\n";
    for (const auto& vt : newly_ripped_tomato_vector) {
        tomato_box[vt.height][vt.col][vt.row] = 1;
//        cout << "    [h][c][r] => [" << vt.height << "][" << vt.col << "][" << vt.row << "]\n";
    }
}

bool cannot_ripe_all_tomato() {
    bool is_impossible = false;
    for (int h = 0; h < height_lenght; ++h) {
        for (int c = 0; c < vertical_length; ++c) {
            for (int r = 0; r < horizontal_length; ++r) {
                if (tomato_box[h][c][r] == 0) {
                    is_impossible = true;
                    goto ENDLOOP;
                }
            }
        }
    }
ENDLOOP:
    return is_impossible;
}
