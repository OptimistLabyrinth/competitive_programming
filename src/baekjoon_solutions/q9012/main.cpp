#include <iostream>
#include <vector>
#include <tuple>

class ParanthesisStringValidator {
public:
  ParanthesisStringValidator() = default;
  ParanthesisStringValidator(const ParanthesisStringValidator& other) = default;
  ParanthesisStringValidator& operator= (const ParanthesisStringValidator& other) = default;
  ParanthesisStringValidator(ParanthesisStringValidator&& other) = default;
  ParanthesisStringValidator& operator= (ParanthesisStringValidator&& other) = default;
  ~ParanthesisStringValidator() = default;

  bool Run(const std::string& ps);

private:
  void OpeningParanthesis();
  void ClosingParanthesis(bool& result);

  std::vector<char> vector_;
};

bool ParanthesisStringValidator::Run(const std::string &ps) {
  bool result = true;
  if (ps.front() == '(' && ps.back() == ')') {
    for (auto x : ps) {
      if (x == '(') {
        OpeningParanthesis();
      } else {
        ClosingParanthesis(result);
      }

      if (!result) {
        break;
      }
    }
    if (!vector_.empty()) {
      result = false;
    }
    vector_.clear();
  } else {
    result = false;
  }
  return result;
}

void ParanthesisStringValidator::OpeningParanthesis() {
  vector_.push_back('(');
}

void ParanthesisStringValidator::ClosingParanthesis(bool& result) {
  if (vector_.back() == '(') {
    vector_.pop_back();
  } else {
    result = false;
  }
}

int main() {
  std::string answer_strore;
  int N; std::cin >> N;
  ParanthesisStringValidator validator;
  std::string paranthesis_string;
  while (N--) {
    std::cin >> paranthesis_string;
    if (validator.Run(paranthesis_string)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
