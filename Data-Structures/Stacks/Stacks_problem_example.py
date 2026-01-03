# Problem: Undo Functionality in a Text Editor
# A text editor allows users to undo their last action. This can be implemented using a stack:
#   1.    Each action is pushed onto the stack.
#   2.    When the user presses "Undo," the last action is popped from the stack.

undo_stack = []

def perform_action(action):
    undo_stack.append(action)
    print(f"Performed: {action}")

def undo():
    if undo_stack:
        print(f"Undo: {undo_stack.pop()}")
    else:
        print("Nothing to undo")

perform_action("Typed 'Hello'")
perform_action("Deleted word")
undo()  # Undo: Deleted word
