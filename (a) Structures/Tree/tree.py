
class Node:

  def __init__(self, n):
    self.num = n
    self.left = None
    self.right = None

class Tree:

  def __init__(self):
    self.root = None

  def insert(self, root, n):
    if root == None:
      root = Node(n);
      print root.num
      print root.left
      print root.right
    else:
      if n < root.num:
        print root.left
        root.left.insert(root.left, n)
      else:
        self.insert(root.right, n)

  def printTree(self, root):
    if self.root != None:
      self.printTree(self.root.left)
      print root.num
      self.printTree(self.root.right)

def main():
  BinTree = Tree()
  BinTree.insert(BinTree.root, 5)
  BinTree.insert(BinTree.root, 3)
  BinTree.insert(BinTree.root, 8)
  BinTree.printTree(BinTree.root)
  #print BinTree.root.num
  #print BinTree.root.left

if __name__ == "__main__":
  main()