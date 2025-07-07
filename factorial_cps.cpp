#include <iostream>
#include <functional>

// A "Continuation" is a function that takes the result of a subproblem
// and performs the rest of the computation.
using Continuation = std::function<long long(long long result)>;

long long factorial_cps(int n, Continuation k) {
    std::cout << "Entering factorial_cps(n=" << n << ")\n";

    if (n <= 1) {
        // Base case: We have the initial result (1).
        // Instead of returning it, we PASS it to our continuation.
        std::cout << "  Base case. Calling continuation k(1)\n";
        return k(1);
    }

    // "Recursive" step:
    // We define a NEW continuation for the subproblem (n-1).
    // This new continuation will receive the result of factorial(n-1),
    // multiply it by n, and then pass that product to the ORIGINAL continuation k.
    Continuation next_k = [=](long long sub_result) {
        std::cout << "  Continuation for n=" << n << " received sub_result=" << sub_result << ". Calling outer k(" << n << " * " << sub_result << ")\n";
        return k(n * sub_result);
    };

    // This is the "tail call". We call the next factorial_cps,
    // but we pass it the NEW continuation we just created.
    return factorial_cps(n - 1, next_k);
}

int main() {
    const int N = 5;
    std::cout << "Calculating factorial(" << N << ") with Continuation-Passing Style...\n\n";

    // To start the process, we provide the "identity" continuation,
    // which is the final step that just returns the result it receives.
    Continuation identity = [](long long final_result) {
        return final_result;
    };

    long long final_value = factorial_cps(N, identity);

    std::cout << "\nFinal Value: " << final_value << std::endl;
    return 0;
}
