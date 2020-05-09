#include <iostream>
#include <stack>

void listen_to_boss(std::stack<int>& num_stack, int num) {
  if (num == 0 && !num_stack.empty()) {
      num_stack.pop();
  } else {
    num_stack.push(num);
  }
}

int main() {
  std::stack<int> num_stack;
  int N; std::cin >> N;
  int num;
  while (N--) {
    std::cin >> num;
    listen_to_boss(num_stack, num);
  }
  long long sum = 0;
  while (!num_stack.empty()) {
    sum += num_stack.top();
    num_stack.pop();
  }
  std::cout << sum << "\n";
  return 0;
}
