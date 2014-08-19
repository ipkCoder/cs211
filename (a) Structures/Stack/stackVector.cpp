#include <iostream>
#include <vector>
using namespace std;

class Stack{
  
protected:
  vector<int> stack;
  int maxSize;
  
public:
  Stack();
  Stack(int num);
  bool push(int num);
  bool pop();
  int top();
  bool full();
  bool empty();
  void print();
};

Stack::Stack()
{
  maxSize = 10;
}

Stack::Stack(int size)
{
  maxSize = size;
}

bool Stack::push(int num)
{
  if(full()){
    cout << "stack is full" << endl;
    return false;
  }
  else{
    stack.push_back(num);
    return true;
  }
}

bool Stack::pop()
{
  if(empty()){
    cout << "stack is empty" << endl;
    return false;
  }
  else{
    stack.pop_back();
    return true;
  }
}

bool Stack::full()
{
  return stack.size() == maxSize;
}

bool Stack::empty()
{
  return stack.size() == 0;
}

int Stack::top()
{
  return stack[stack.size() - 1];
}

void Stack::print()
{
  int i;
  for(i = stack.size()-1; i >= 0; i--)
    cout << stack[i] << endl;
}


int main()
{
  Stack x(3);
  x.pop();
  x.push(1);
  x.push(2);
  x.push(3);
  x.push(9);
  cout << "top: " << x.top() << endl;
  x.print();
}