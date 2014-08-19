#include <iostream>
#include <vector>
using namespace std;

class Queue{
  
protected:
  vector<int> queue;
  int maxSize;
  
public:
  Queue();
  Queue(int num);
  bool push(int num);
  bool pop();
  int top();
  bool full();
  bool empty();
  void print();
};

Queue::Queue()
{
  maxSize = 10;
}

Queue::Queue(int size)
{
  maxSize = size;
}

bool Queue::push(int num)
{
  if(full()){
    cout << "queue is full" << endl;
    return false;
  }
  else{
    queue.push_back(num);
    return true;
  }
}

bool Queue::pop()
{
  if(empty()){
    cout << "queue empty" << endl;
    return false;
  }
  else{
    queue.erase(queue.begin());
    return true;
  }
}

bool Queue::full()
{
  return queue.size() == maxSize;
}

bool Queue::empty()
{
  return queue.size() == 0;
}

int Queue::top()
{
  return queue[0];
}

void Queue::print()
{
  int i;
  for(i = queue.size()-1; i >= 0; ++i) {
    cout << queue[i] << endl;
  }
}


int main()
{
  Queue x(4);
  x.pop();
  x.push(1);
  x.push(2);
  x.push(3);
  x.push(9);
  x.push(8);
  x.pop();
  cout << "top: " << x.top() << endl;
  x.print();
}
