#include <iostream>
#include <vector>

std::vector<char> paranthesis_vector;

bool IsBalancedWorld(const std::string& sentence);
void OpeningParanthesis(char x);
void ClosingParanthesis(char x, bool& result);

bool IsBalancedWorld(const std::string& sentence) {
  bool result = true;
  for (auto x : sentence) {
    if (x == '(' || x == '[') {
      OpeningParanthesis(x);
    } else if (x == ')' || x == ']') {
      ClosingParanthesis(x, result);
      if (!result) {
        break;
      }
    } else {
      continue;
    }
  }
  if (!paranthesis_vector.empty()) {
    result = false;
  }
  paranthesis_vector.clear();
  return result;
}

void OpeningParanthesis(char x) {
  paranthesis_vector.push_back(x);
}

void ClosingParanthesis(char x, bool& result) {
  if (x == ')' && paranthesis_vector.back() == '(') {
    paranthesis_vector.pop_back();
  } else if (x == ']' && paranthesis_vector.back() == '[') {
    paranthesis_vector.pop_back();
  } else {
    result = false;
  }
}

int main() {
  std::string sentence;
  while (true) {
    std::getline(std::cin, sentence);
    if (sentence == ".") {
      break;
    }
    if (IsBalancedWorld(sentence)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}
