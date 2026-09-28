

#include <iostream>
#include <chrono>  

long long int simpleSort(float* a, int n);
float* allocate_float_array(int n);

int main()
{
	int n = 1000;
	float* a = allocate_float_array(n);

	std::cout << std::endl;

	std::cout << "Simple sort for an array of " << n << " completed in approximately "
		<< simpleSort(a, n) << " ns " << std::endl;

	n = 10000;
	a = allocate_float_array(n);

	std::cout << std::endl;

	std::cout << "Simple sort for an array of " << n << " completed in approximately "
		<< simpleSort(a, n) << " ns " << std::endl;

	n = 100000;
	a = allocate_float_array(n);

	std::cout << std::endl;

	std::cout << "Simple sort for an array of " << n << " completed in approximately "
		<< simpleSort(a, n) << " ns " << std::endl;
	
	//When increasing n in 10 times, functions takes 100 more nanoseconds to complete,
	//so it is O(n^2)

}


long long int simpleSort(float* a, int n) {

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] < a[i])
                std::swap(a[j], a[i]);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long long int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

	return time;

}

float* allocate_float_array(int n)
{
	std::cout << "Reserving memory...";
	float* array = new float[n];
	std::cout << "Done!\n";

	std::cout << "Assigning data into array...";
	for (int i = 0; i < n; i++)
		array[i] = i;
	std::cout << "Done!\n";

	return array;
}