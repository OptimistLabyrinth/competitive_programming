#include <iostream>

int cyrillic_letter_count;

int how_many_cyrillic_letter_in_the_string(const std::string& letter);

int main() {
    std::string input;
    std::getline(std::cin, input);
    how_many_cyrillic_letter_in_the_string(input);

    std::cout << cyrillic_letter_count << "\n";

    return 0;
}

int how_many_cyrillic_letter_in_the_string(const std::string& letter) {
    size_t i = 0;
    size_t len = letter.size();
    while (i < len) {
        switch (letter[i])
        {
            case 'c':
            {
                if (i+1 < len && letter[i+1] == '=') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else if (letter[i+1] == '-') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            case 'd':
            {
                if (i+1 < len && letter[i+1] == '-') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else if (i+2 < len && letter[i+1] == 'z' && letter[i+2] == '=') {
                    ++cyrillic_letter_count; i += 2; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            case 'l':
            {
                if (i+1 < len && letter[i+1] == 'j') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            case 'n':
            {
                if (i+1 < len && letter[i+1] == 'j') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            case 's':
            {
                if (i+1 < len && letter[i+1] == '=') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            case 'z':
            {
                if (i+1 < len && letter[i+1] == '=') {
                    ++cyrillic_letter_count; i += 1; break;
                }
                else {
                    ++cyrillic_letter_count; break;
                }
            }
            default:
                ++cyrillic_letter_count; break;
        }
        ++i;
    }
    return cyrillic_letter_count;
}
