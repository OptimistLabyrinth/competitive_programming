#include <iostream>
#include <stack>

class MyStack {
public:
  MyStack() = default;
  MyStack(const MyStack& my_stack) = default;
  MyStack& operator= (const MyStack& my_stack) = default;
  MyStack(MyStack&& my_stack) = default;
  MyStack& operator= (MyStack&& my_stack) = default;
  ~MyStack() = default;

  void Push(int x);
  int Pop();
  size_t Size();
  int IsEmpty();
  int Top();

private:
  std::stack<int> stack_;
};

void MyStack::Push(int x) {
  stack_.push(x);
}

int MyStack::Pop() {
  if (stack_.empty()) {
    return -1;
  }
  int top_element = stack_.top();
  stack_.pop();
  return top_element;
}

size_t MyStack::Size() {
  return stack_.size();
}

int MyStack::IsEmpty() {
  return stack_.empty() ? 1 : 0; 
}

int MyStack::Top() {
  if (stack_.empty()) {
    return -1;
  }
  return stack_.top();
}

int main() {
  int N; std::cin >> N;
  if (N == 0) {
    return 0;
  }
  MyStack my_stack;
  std::string command;
  std::string num_str;
  int num = 0;
  while (N--) {
    std::cin >> command;
    if (command == "push") {
      std::cin >> num_str;
      num = std::stoi(num_str);
      my_stack.Push(num);
    } else if (command == "pop") {
      std::cout << my_stack.Pop() << "\n";
    } else if (command == "size") {
      std::cout << my_stack.Size() << "\n";
    } else if (command == "empty") {
      std::cout << my_stack.IsEmpty() << "\n";
    } else if (command == "top") {
      std::cout << my_stack.Top() << "\n";
    } else {
      continue;
    }
  }

  return 0;
}
