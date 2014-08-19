

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Node {

public:
  int number;
  Node *next;
  Node *prev;
  
  Node();
  Node(const int &n);
  int getInt();
};

Node::Node(): number(0) {
  next = NULL;
  prev = NULL;
}

Node::Node(const int &n): number(0) {
  next = NULL;
  prev = NULL;
}

int Node::getInt() {
  return number;
}
//---------------------------------------------
//---------------------------------------------
//---------------------------------------------

// Double Linked list
// includes 'last' pointer

class DLL {

private:
  Node *top;
  Node *last;
  void destroy(Node *&head, Node *&end);
  bool copy(Node *aTop, Node *&bTop, Node *&bEnd);

public:
  DLL();
  DLL(const DLL &toCopy);
  ~DLL();
  bool insertBeforeFirst(const int &n); // unshift
  // shift - pop from front return first node
  bool insertAfterFirst(const int &n);
  bool insertBeforeLast(const int &n);
  bool insertAfterLast(const int &n); // push
  // pop - pop from back, return last node
  bool remove(const int &n);
  bool search(const int &n);
  int count();
  void print();
};

DLL::DLL() {
  top = last = NULL;
}
DLL::DLL(const DLL &toCopy) {
  top = last = NULL;
  copy(toCopy.top, top, last);
}
DLL::~DLL() {
  destroy(top, last);
}

/*
 * Insert before first node in list.
 *
 * Cases: 1) empty
 *        2) one or more node
 */
bool DLL::insertBeforeFirst(const int &n) {
  
  Node *node = new Node(n);
  
  // test if empty set top and last to node, else insert at beginning
  if(top == NULL){
    top = last = node;
  }
  else{
    node->next = top;
    top->prev = node;
    top = node;
  }
  return true;
}
/*
 * Insert after first node in list.
 *
 * Cases: 1) empty
 *        2) one node
 *        3) more than one node
 */
bool DLL::insertAfterFirst(const int &n) {

  if(top == NULL){
    insertBeforeFirst(n);
  }
  else if(top->next == NULL){
    Node *node = new Node(n);
    node->prev = top;
    top->next = node;
    last = node;
  }
  else{
    Node *node = new Node(n);
    node->next = top->next;
    node->prev = top;
    top->next->prev = node;
    top->next = node;
  }
  return true;
}
/*
 * Insert before end of list
 *
 * Cases: 1) empty, only one node
 *        2) more than one node
 */
bool DLL::insertBeforeLast(const int &n) {

  if(top == NULL || top->next == NULL){
    insertBeforeFirst(n);
  }
  else{
    Node *node = new Node(n);
    node->next = last;
    node->prev = last->prev;
    last->prev->next = node;
    last->prev = node;
  }
  return true;
}
/*
 * Remove from end of list
 *
 * Cases: 1) empty
 *        2) one or more nodes
 */
bool DLL::insertAfterLast(const int &n) {

  if(top == NULL){
    insertBeforeFirst(n);
  }
  else{
    Node *node = new Node(n);
    node->prev = last;
    last->next = node;
    last = node;
  }
  return true;
}
/*
 * Remove integer from list.
 *
 * Cases: 1) empty or integer not found - return false
 *        2) head of list and only one node
 *        3) head of list and more than one node
 *        4) end of list
 *        5) middle of list
 */
bool DLL::remove(const int &n) {

  Node *curr = top;
  
  while(curr != NULL){
    
    if(curr->getInt() == n){
      // check if at front of DLL
      if(curr->prev == NULL){
        // if only one node, set top, last to NULL
        if(last->prev == NULL){
          top = last = NULL;
        }
        // else, just move top to next node
        else{
          top = top->next;
        }
      }
      // else, check if at end of DLL
      else if(curr->next == NULL){
        last = curr->prev;
        last->next = NULL;
      }
      // else, remove from middle part of DLL
      else{
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
      }
      // delete node
      delete curr;
      return true;
    }
    // if node is not a match, move to next node
    else{
      curr = curr->next;
    }
  }
  
  // empty or didn't find
  return false;
}

bool DLL::search(const int &n) {

  Node *curr = top;
  while(curr != NULL){
    if(curr->getInt() == n){
      return true;
    }
    else{
      curr = curr->next;
    }
  }
  return false;
}

bool DLL::copy(Node *aTop, Node*& bTop, Node *&bEnd) {

  Node *acurr, *bcurr;
  
  destroy(bTop, bEnd);
  
  if(aTop != NULL){
    bTop = new Node(aTop->getInt());
    acurr = aTop;
    bcurr = bTop;
    bEnd = bcurr; // set end pointer to last node
    while(acurr->next != NULL){
      acurr = acurr->next;
      bcurr->next = new Node(acurr->getInt());
      bcurr->next->prev = bcurr;
      bcurr = bcurr->next;
      bEnd = bcurr; // set end pointer to last node
    }
  }
}

void DLL::destroy(Node *&head, Node *&end) {

  if(head != NULL){
    Node *temp;
    while(head != NULL){
      temp = head;
      head = head->next;
      //cout << "deleting: " << temp->getInt() << endl;
      delete temp;
    }
    end = NULL;
  }
}

void DLL::print() {

  Node *curr = top;
  while(curr != NULL){
    cout << setw(8) << curr->getInt();
    curr = curr->next;
  }
}

int DLL::count() {

  int count = 0;
  Node *curr = top;
  while(curr != NULL){
    ++count;
    curr = curr->next;
  }
  return count;
}

int main() {

  DLL dll1, dll2, dll3, dll4;
  
  // test insert when empty list
  dll1.insertAfterLast(5);
  
  dll2.insertAfterFirst(7);
  
  dll3.insertBeforeFirst(4);
  
  dll4.insertBeforeLast(3);
  
  cout << "Test all inserts on empty list" << endl;
  cout << "DLL1: "; dll1.print(); cout << endl;
  cout << "DLL2: "; dll2.print(); cout << endl;
  cout << "DLL3: "; dll3.print(); cout << endl;
  cout << "DLL4: "; dll4.print(); cout << endl;
  
  dll1.insertAfterLast(7);
  dll2.insertAfterFirst(8);
  dll3.insertBeforeLast(0);
  dll4.insertBeforeFirst(10);
  
  cout << "Test all inserts with one node in list" << endl;
  cout << "DLL1: "; dll1.print(); cout << endl;
  cout << "DLL2: "; dll2.print(); cout << endl;
  cout << "DLL3: "; dll3.print(); cout << endl;
  cout << "DLL4: "; dll4.print(); cout << endl;
  
  dll1.insertAfterLast(3);
  dll2.insertAfterFirst(83);
  dll3.insertBeforeLast(30);
  dll4.insertBeforeFirst(103);
  
  cout << "Test all inserts with two nodes in list" << endl;
  cout << "DLL1: "; dll1.print(); cout << endl;
  cout << "DLL2: "; dll2.print(); cout << endl;
  cout << "DLL3: "; dll3.print(); cout << endl;
  cout << "DLL4: "; dll4.print(); cout << endl;
  
  cout << dll1.search(7) << endl;
  
  DLL dll5(dll1);
  dll5.print();
  
  dll2.insertAfterLast(18);
  dll2.insertBeforeFirst(2);
  dll2.insertAfterFirst(12);
  dll2.insertBeforeLast(8);
  dll2.print();
  cout << dll2.count() << endl;
}

