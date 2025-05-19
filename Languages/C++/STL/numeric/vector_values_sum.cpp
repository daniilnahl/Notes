#include <vector>
#include <numeric>
#include <iostream>

double sum_vector(const std::vector<double>& vec) {
  return std::accumulate(vec.begin(), vec.end(), 0.0);
}

int main() {
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    double sum = sum_vector(numbers);
    std::cout << "The sum of the vector is: " << sum << std::endl; // Output: The sum of the vector is: 15
    return 0;
  }
  