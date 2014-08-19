
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
Node::Node(): id(0) {
  next = NULL;
}
//--------------------------------------------------------------------------------
Node::Node(int ID): id(ID) {
  next = NULL;
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
class Stack {
  
protected:
  Node* top;
  int currentSize;
  int maxSize;
  
public:
  Stack();
  Stack(int max);
  bool push(Node *node);
  bool pop();
  Node* topOfStack();
  bool empty();
  bool full();
  void print();
};
//--------------------------------------------------------------------------------
Stack::Stack() {
  top = NULL;
  currentSize = 0;
  maxSize = 10;
}
//--------------------------------------------------------------------------------
Stack::Stack(int max)
{
  top = NULL;
  currentSize = 0;
  maxSize = max;
}
//--------------------------------------------------------------------------------
bool Stack::full()
{
  return currentSize == maxSize;
}
//--------------------------------------------------------------------------------
bool Stack::empty()
{
  if(top == NULL)
    return true;
  else
    return false;
}
//--------------------------------------------------------------------------------
bool Stack::push(Node *node)
{
  if(full()){
    cout << "stack is full." << endl;
    return false;
  }
  else{
    node->next = top;
    top = node;
    ++currentSize;
    return true;
  }
}
//--------------------------------------------------------------------------------
bool Stack::pop()
{
  if(empty()){
    cout << "stack is empty." << endl;
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
Node* Stack::topOfStack()
{
  return top;
}
//--------------------------------------------------------------------------------
void Stack::print()
{
  Node *curr = top;
  while(curr != NULL){
    cout << curr->id << endl;
    curr = curr->next;
  }
}
//--------------------------------------------------------------------------------
int main(){
  Stack stack;
  Node *x;
  stack.pop();
  int i;
  for (i = 0; i < 10; i++) {
    x = new Node(i*i);
    stack.push(x);
  }
  stack.pop();
  stack.print();
  Node* a = stack.topOfStack();
  cout << a->id << endl;
}

