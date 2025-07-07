#include <iostream>

// Helper function that IS tail-recursive.
long long factorial_helper(int n, long long accumulator) {
    if (n <= 1) {
        // Base case: return the final accumulated result.
        return accumulator;
    }

    // The recursive call IS the very last thing this function does.
    // Its result is immediately returned by the current function
    // without any further modification. The compiler can optimize this.
    return factorial_helper(n - 1, accumulator * n);
}

// User-facing function that starts the process.
long long factorial(int n) {
    return factorial_helper(n, 1);
}

int main() {
    const int N = 200000;
    std::cout << "Calculating factorial(" << N << ") with a tail-recursive function..." << std::endl;
    factorial(N);
    std::cout << "Success! No stack overflow occurred." << std::endl;
    return 0;
}
