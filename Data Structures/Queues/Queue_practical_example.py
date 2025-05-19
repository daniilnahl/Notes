# Problem: Task Scheduling in a Print Queue
# When multiple users send print jobs, the printer processes them in the order they arrive.

from collections import deque

print_queue = deque()

def add_job(job):
    print_queue.append(job)
    print(f"Added: {job}")

def process_job():
    if print_queue:
        print(f"Processing: {print_queue.popleft()}")
    else:
        print("No jobs in queue")

add_job("Print Document A")
add_job("Print Document B")
process_job()  # Processing: Print Document A
