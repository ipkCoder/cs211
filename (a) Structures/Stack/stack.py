
class Node:
  def __init__(self, n):
    self.num = n
    self.next = None

class Stack:

  def __init__(self, n):
    self.top = None
    self.size = 0
    self.maxSize = n

  def push(self, num):
    node = Node(num)
    node.next = self.top
    self.top = node
    self.size += 1

  def pop(self):
    temp = self.top
    self.top = self.top.next
    del temp
    self.size -= 1

  def printStack(self):
    node = self.top
    while node != None:
      print node.num
      node = node.next

def main():
  x = Stack(10)
  x.push(10)
  x.push(8)
  x.push(9)
  x.printStack()
  x.pop()
  x.printStack()

if __name__ == "__main__":
  main()