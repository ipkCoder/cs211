// Queue is same as stack except for push(Node* node)
// have to push to end, not on top

#include <iostream>
#include <string>
using namespace std;

class Node{
public:
  int id;
  Node* next;
  Node();
  Node(int ID);
};
//--------------------------------------------------------------------------------
Node::Node()
{
  id = 0;
  next = NULL;
}
//--------------------------------------------------------------------------------
Node::Node(int ID)
{
  id = ID;
  next = NULL;
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
class Queue{
  
protected:
  Node* top;
  Node* last;
  int currentSize;
  int maxSize;
  
public:
  Queue();
  Queue(int max);
  bool push(Node *node);
  bool pop();
  Node* topOfQueue();
  bool empty();
  bool full();
  void print();
};
//--------------------------------------------------------------------------------
Queue::Queue()
{
  top = last = NULL;
  currentSize = 0;
  maxSize = 10;
}
//--------------------------------------------------------------------------------
Queue::Queue(int max)
{
  top = last = NULL;
  currentSize = 0;
  maxSize = max;
}
//--------------------------------------------------------------------------------
bool Queue::full()
{
  return currentSize == maxSize;
}
//--------------------------------------------------------------------------------
bool Queue::empty()
{
  if(top == NULL)
    return true;
  else
    return false;
}
//--------------------------------------------------------------------------------
bool Queue::push(Node *node)
{
  if(full()){
    cout << "Queue is full." << endl;
    return false;
  }
  else if(empty()){
    top = last = node;
  }
  else{
    last->next = node;
    last = node;
  }
  
  ++currentSize;
  return true;
}
//--------------------------------------------------------------------------------
bool Queue::pop()
{
  if(empty()){
    cout << "Queue is empty." << endl;
    return false;
  }
  else{
    Node* temp = top;
    top = top->next;
    delete temp;
    --currentSize;
    return true;
  }
}
//--------------------------------------------------------------------------------
Node* Queue::topOfQueue()
{
  return top;
}
//--------------------------------------------------------------------------------
void Queue::print()
{
  Node *curr = top;
  while(curr != NULL){
    cout << curr->id << endl;
    curr = curr->next;
  }
}
//--------------------------------------------------------------------------------
int main(){
  Queue queue;
  Node *x;
  queue.pop();
  int i;
  for (i = 0; i < 12; i++) {
    x = new Node(i*i);
    queue.push(x);
  }
  queue.pop();
  queue.print();
  Node* a = queue.topOfQueue();
  cout << a->id << endl;
}
