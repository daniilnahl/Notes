## 1. What is running time?

The speed of an algorithm is often described using **running time** in **Big O notation**. Big O tells you how fast an algorithm is in terms of the size of the input, typically denoted as $O(n)$, where $n$ is the number of operations or the size of the input. Algorithms' times are measured in terms of the growth of an algorithm's operations as the input size increases.

* The highest order term (N) dominates runtime.
* Ignore constants in runtime.

**Example**: For a runtime expressed as $N^3 + 5N^2 + 5N + 21$, the Big O runtime would be $O(N^3)$.

### Common Big O run times:

1.  **$O(\log n)$** - logarithmic time. Ex: binary search. (FASTEST)
2.  **$O(n)$** - linear time. Ex: simple search.
3.  **$O(n \log n)$** - log-linear time. Ex: fast sorting algorithms like quicksort and merge sort.
4.  **$O(n^2)$** - quadratic time. Ex: slow sorting algorithms like selection sort.
5.  **$O(n!)$** - factorial time. Ex: a really slow algorithm, like traveling salesperson for finding all permutations. (SLOWEST)

### Complexity classes

| Class         | Big O        | If N is doubled         | Example Time with growing N |
| :------------ | :----------- | :---------------------- | :-------------------------- |
| constant      | $O(1)$       | unchanged               | 10ms                        |
| logarithmic   | $O(\log_2 N)$ | increase slightly       | 175ms                       |
| linear        | $O(N)$       | doubles                 | 3.2 sec                     |
| log linear    | $O(N \log_2 N)$| slightly more than doubles | 6 sec                       |
| quadratic     | $O(N^2)$     | quadruples              | 1 min 4 sec                 |
| cubic         | $O(N^3)$     | multiplies by 8         | 55 min                      |
| exponential   | $O(2^N)$     | multiplies drastically  | 5 * $10^{61}$ years         |