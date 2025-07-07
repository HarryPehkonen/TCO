#include <iostream>

// This function is NOT tail-recursive.
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    // The multiplication n * ... must happen AFTER the recursive
    // call factorial(n - 1) returns. This is pending work
    // that consumes stack space for every call.
    return n * factorial(n - 1);
}

int main() {
    // This number is large enough to cause a stack overflow on most systems.
    const int N = 200000;
    
    std::cout << "Attempting to calculate factorial(" << N << ") with standard recursion..." << std::endl;
    
    // We don't care about the numerical result (it's too large for long long).
    // We only care if the program crashes.
    factorial(N); 
    
    std::cout << "Success! (This is unexpected... the compiler might have been too smart)." << std::endl;
    
    return 0;
}
