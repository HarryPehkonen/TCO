all: factorial_standard factorial_tail_recursive factorial_trampoline factorial_cps

factorial_standard: factorial_standard.cpp
	g++ -O0 -o factorial_standard factorial_standard.cpp

run_factorial_standard: factorial_standard
	./factorial_standard

factorial_tail_recursive: factorial_tail_recursive.cpp
	g++ -O0 -o factorial_tail_recursive factorial_tail_recursive.cpp

run_factorial_tail_recursive: factorial_tail_recursive
	./factorial_tail_recursive

factorial_trampoline: factorial_trampoline.cpp
	g++ -O0 -o factorial_trampoline factorial_trampoline.cpp

run_factorial_trampoline: factorial_trampoline
	./factorial_trampoline

factorial_cps: factorial_cps.cpp
	g++ -std=c++17 -o factorial_cps factorial_cps.cpp

run_factorial_cps: factorial_cps
	./factorial_cps

clean:
	rm factorial_standard
	rm factorial_tail_recursive
	rm factorial_trampoline
	rm factorial_cps
