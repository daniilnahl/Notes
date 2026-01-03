from collections import deque

queue = deque()

queue.append(10)
queue.append(20)
queue.append(30)

print(queue.popleft()) # 10
print(queue.popleft()) # 20