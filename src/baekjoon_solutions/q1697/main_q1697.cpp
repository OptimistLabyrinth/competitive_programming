#include <climits>
#include <deque>
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

int Farmer_John;
int fugitive_cow;
constexpr int MAX_FUGITIVE_COW = 100001;
vector<bool> is_checked;
deque<int> possible_positions;
int previously_push_backed_positions;
int currently_push_backed_positions;
int periods_until_found;

void search_possible_positions(int current);

int main() {
    cin >> Farmer_John >> fugitive_cow;
    if (Farmer_John == fugitive_cow) {
        cout << "0\n";
        return 0;
    }
    is_checked.resize(MAX_FUGITIVE_COW, false);
    periods_until_found = 0;
    search_possible_positions(Farmer_John);
    cout << periods_until_found - 1 << "\n";

    return 0;
}

void search_possible_positions(int current) {
    possible_positions.clear();
    possible_positions.push_back(current);
    is_checked[current] = false;
    previously_push_backed_positions = 1;
    int pos = 0;
    while (not possible_positions.empty()) {
        ++periods_until_found;

        cout << "in deque => ";
        for (const auto& each : possible_positions) {
            cout << each << " ";
        }
        cout << "\n";

        currently_push_backed_positions = 0;
        for (int i = 0; i < previously_push_backed_positions; ++i) {
            pos = possible_positions.front();
            possible_positions.pop_front();
            if (pos == fugitive_cow) {
                return;
            }
            if (0 < pos - 1 and not is_checked[pos - 1]) {
                possible_positions.push_back(pos - 1);
                ++currently_push_backed_positions;
            }
            if (pos + 1 < MAX_FUGITIVE_COW and not is_checked[pos - 1]) {
                possible_positions.push_back(pos + 1);
                ++currently_push_backed_positions;
            }
            if (pos != 0 and 2 * pos < MAX_FUGITIVE_COW and not is_checked[pos - 1]) {
                possible_positions.push_back(2 * pos);
                ++currently_push_backed_positions;
            }
        }
        previously_push_backed_positions = currently_push_backed_positions;
        sleep(1);
    }
}
