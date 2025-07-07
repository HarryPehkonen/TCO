#include <iostream>

// A simple struct to hold the state of our "recursive" calls.
// This is analogous to your `TailCall` struct in Computo.
struct State {
    int n;
    long long accumulator;
};

long long factorial_trampoline(int n) {
    // Initialize the state, just like the first call to factorial_helper(n, 1).
    State current_state = {n, 1};

    // This is the trampoline loop. It replaces the call stack.
    while (true) {
        // The base case: when we would stop recursing, we exit the loop.
        if (current_state.n <= 1) {
            return current_state.accumulator;
        }

        // The "recursive" step. Instead of calling a new function,
        // we just calculate the next state.
        int next_n = current_state.n - 1;
        long long next_accumulator = current_state.accumulator * current_state.n;

        // Update the state for the next iteration of the loop.
        current_state = {next_n, next_accumulator};
        
        // The `continue` is the "tail call". It jumps back to the start
        // of the loop with the new state, using no extra stack space.
        continue;
    }
}

int main() {
    const int N = 200000;
    std::cout << "Calculating factorial(" << N << ") with a manual trampoline..." << std::endl;
    factorial_trampoline(N);
    std::cout << "Success! No stack overflow occurred." << std::endl;
    return 0;
}
