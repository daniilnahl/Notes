## 1. What is backtracking?

* A search algorithm that explores all possible solutions recursively.
* Recursively builds a solution and removes invalid choices when they don't lead to a solution.

## 2. Why use backtracking?

* Efficiently explores combinations/permutations.
* **Prunes** (eliminates or discards) invalid paths to reduce unnecessary computation.
* Used in problems with multiple choices at each step.
* Finds all solutions or optimal ones.

## 3. How does backtracking work?

1.  **Choose**: Select a valid option from the current possibilities.
2.  **Explore**: Recursively move deeper into the problem space with the selected option.
3.  **Unchoose (Backtrack)**: If the current path leads to an invalid state or doesn't result in a solution, undo the last choice and return to the previous state to try a different option.

## 4. When to use backtracking?

* **Combinatorial Problems**: Subsets, permutations, combinations.
* **Constraint Satisfaction Problems**: Sudoku, N-Queens.
* **Pathfinding**: Maze solving, word ladders.
* **Game Theory**: AI for games like Chess or Tic-Tac-Toe.