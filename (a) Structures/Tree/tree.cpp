#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Node{

public:// make protected by using getters and setters
  int id;
  Node *left;
  Node *right;
  Node();
  Node(int ID);
};
//--------------------------------------------------------------------------------
Node::Node()
{
  id = 0;
  left = right = NULL;
}
//--------------------------------------------------------------------------------
Node::Node(int ID)
{
  id = ID;
  left = right = NULL;
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
class Tree{
  
protected: // need too make protected functions so don't allow access to 'root'
  Node *root;
  bool insert(Node *&root, const int &num);
  bool search(Node *node, const int &num);
  void destroy(Node *&node);
  int count(Node *node);
  int countLongest(Node *node);
  int countShortest(Node *node);
  int countEvens(Node *node);
  void inOrderPrint(Node* node);
  void preOrderPrint(Node* node);
  void postOrderPrint(Node* node);
public:
  Tree();
  ~Tree();
  bool insertNum(const int &num);
  bool searchNum(const int &num);
  int countNodes();
  int countLongestPath();
  int countShortestPath();
  int countEvenNums();
  void printInOrder();
  void printPreOrder();
  void printPostOrder();
};
//--------------------------------------------------------------------------------
Tree::Tree()
{
  root = NULL;
}
//--------------------------------------------------------------------------------
Tree::~Tree()
{
  destroy(root);
}
//--------------------------------------------------------------------------------
//---------------------------- Public Functions ----------------------------------
//--------------------------------------------------------------------------------
bool Tree::insertNum(const int &num)
{
  return insert(root, num);
}
bool Tree::searchNum(const int &num)
{
  return search(root, num);
}
int Tree::countNodes()
{
  return count(root);
}
int Tree::countLongestPath()
{
  return countLongest(root);
}
int Tree::countShortestPath()
{
  return countShortest(root);
}
int Tree::countEvenNums()
{
  return countEvens(root);
}
void Tree::printInOrder()
{
  inOrderPrint(root);
}
void Tree::printPreOrder()
{
  preOrderPrint(root);
}
void Tree::printPostOrder()
{
  postOrderPrint(root);
}
//--------------------------------------------------------------------------------
//--------------------------- Private Functions  ---------------------------------
//--------------------------------------------------------------------------------
void Tree::destroy(Node *&node)
{
  if(node == NULL){
    return;
  }
  else{
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = NULL;
  }
}
//--------------------------------------------------------------------------------
bool Tree::insert(Node *&node, const int &num)
{
  if(node == NULL){
    node = new Node(num);
  }
  else{
    if(num < node->id)
      insert(node->left, num);
    else
      insert(node->right, num);
  }
  return true;
}
//--------------------------------------------------------------------------------
bool Tree::search(Node *node, const int &num)
{
  if(node == NULL){
    return false;
  }
  else{
    if(node->id == num)
      return true;
    else if(num < node->id)
      return search(node->left, num);
    else
      return search(node->right, num);
  }
}
//--------------------------------------------------------------------------------
int Tree::count(Node *node)
{
  if(node == NULL){
    return 0;
  }
  else{
    int L = count(node->left);
    int R = count(node->right);
    return L + R + 1;
  }
}
//--------------------------------------------------------------------------------
int Tree::countLongest(Node *node)
{
  if(node == NULL){
    return 0;
  }
  else{
    int L = countLongest(node->left);
    int R = countLongest(node->right);
    if(L > R)
      return (L + 1);
    else
      return (R + 1);
  }
}
//--------------------------------------------------------------------------------
int Tree::countShortest(Node *node)
{
  if(node == NULL){
    return 0;
  }
  else{
    int L = countShortest(node->left);
    int R = countShortest(node->right);
    if((R == 0) || ((L != 0) && (L < R)))
      return L + 1;
    else
      return R + 1;
  }
}
//--------------------------------------------------------------------------------
int Tree::countEvens(Node *node)
{
  if(node == NULL){
    return 0;
  }
  else{
    int L = countEvens(node->left);
    int R = countEvens(node->right);
    if(node->id % 2 == 0)
      return (L + R + 1);
    else
      return (L + R);
  }
}
//--------------------------------------------------------------------------------
void Tree::inOrderPrint(Node* node)
{
  if(node != NULL){
    inOrderPrint(node->left);
    cout << node->id << endl;
    inOrderPrint(node->right);
  }
}
//--------------------------------------------------------------------------------
void Tree::preOrderPrint(Node* node)
{
  if(node != NULL){
    cout << node->id << endl;
    preOrderPrint(node->left);
    preOrderPrint(node->right);
  }
}
//--------------------------------------------------------------------------------
void Tree::postOrderPrint(Node* node)
{
  if(node != NULL){
    postOrderPrint(node->left);
    postOrderPrint(node->right);
    cout << node->id << endl;
  }
}
//--------------------------------------------------------------------------------
int main(){
  int a[10] = {2,9,6,4,0,1,7,5,3,8};
  Tree tree;
  int i;
  for (i = 0; i < 10; i++) {
    tree.insertNum(a[i]);
  }
  tree.printInOrder();
  tree.printPreOrder();
  tree.printPostOrder();
  bool x = tree.searchNum(19);
  cout << x << endl;
  cout << "Total nodes: " << tree.countNodes() << endl;
  cout << "Even nodes: " << tree.countEvenNums() << endl;
  cout << "Longest path: " << tree.countLongestPath() << endl;
  cout << "Shortest path: " << tree.countShortestPath() << endl;
}


