

#include <iostream>

int FibonacciNumber1(int n);
int FibonacciNumber2(int n);

int main()
{
	int a = 15;
	std::cout << a << "th Fibonacci number is " << FibonacciNumber1(a);

	std::cout << "\n";

	std::cout << a << "th Fibonacci number is " << FibonacciNumber2(a);

}

int FibonacciNumber1(int n) {
	int* numbers = new int[n];

	for (int i = 0; i < n; i++)
		numbers[i] = i;
	
	for (int i = 0; i < n; i++) {

		if (i == 0) {
			numbers[i] = 0;
			continue;
		}

		if (i == 1) {
			numbers[i] = 1;
			continue;
		}

		numbers[i] = (numbers[i - 2] + numbers[i - 1]);
		
	}

    return numbers[n - 1];
}

int FibonacciNumber2(int n) {

	int a = 0;
	int b = 1;

	int result = 0;

	for (int i = 2; i < n; i++) {
		result = a + b;
		a = b;
		b = result;
	}
	

	return result;
}