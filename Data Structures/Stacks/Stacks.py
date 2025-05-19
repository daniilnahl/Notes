class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop() # .pop() is a built-in Python list method that removes and returns the last element (mimicking a LIFO stack).
        return "Stack is empty" #doesn't call the class function pop() since the pop() functions is being called onto the stac variable which is a python list

    def peek(self):
        return self.stack[-1] if not self.is_empty() else "Stack is empty"

    def is_empty(self):
        return len(self.stack) == 0

stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
print(stack)
print(stack.pop()) # 30
print(stack.pop()) # 20
