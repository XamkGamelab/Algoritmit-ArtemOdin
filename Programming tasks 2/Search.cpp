

#include <iostream>  
#include <chrono>  
#include <random>  

long long int LinearSearch(long long int* a, long long int x, long long unsigned int n);
int CountLinearSearch(long long int* a, long long unsigned int n);

long long int BinarySearch(long long int* a, long long int x, long long unsigned int n);
int CountBinarySearch(long long int* a, long long unsigned int n);


long long int* allocate_array(long long unsigned n)
{
	std::cout << "Reserving memory...";
	long long int* array = new long long int[n];
	std::cout << "Done!\n";

	std::cout << "Assigning data into array...";
	for (long long unsigned i = 0; i < n; i++)
		array[i] = i;
	std::cout << "Done!\n";

	return array;
}

int result;

int main()  
{  
	std::random_device rd;
	std::mt19937 gen(rd());


   long long unsigned int n = 100000;
   long long int* a = allocate_array(n);

   std::cout << std::endl;

   std::cout << "Linear search for an array of " << n << " completed in approximately " 
	   << CountLinearSearch(a,n) << " ns " << std::endl;

   std::cout << std::endl;

   std::cout << "Binary search for an array of " << n << " completed in approximately "
	   << CountBinarySearch(a, n) << " ns " << std::endl;

   std::cout << std::endl;

   delete[] a;

   n = 1000000;
   a = allocate_array(n);

   std::cout << std::endl;

   std::cout << "Linear search for an array of " << n << " completed in approximately "
	   << CountLinearSearch(a, n) << " ns " << std::endl;

   std::cout << std::endl;

   std::cout << "Binary search for an array of " << n << " completed in approximately "
	   << CountBinarySearch(a, n) << " ns " << std::endl;

   std::cout << std::endl;

   delete[] a;

   n = 10000000;
   a = allocate_array(n);

   std::cout << std::endl;

   std::cout << "Linear search for an array of " << n << " completed in approximately "
	   << CountLinearSearch(a, n) << " ns " << std::endl;

   std::cout << std::endl;

   std::cout << "Binary search for an array of " << n << " completed in approximately "
	   << CountBinarySearch(a, n) << " ns " << std::endl;


   return EXIT_SUCCESS;
}

//Linear serach assumes that a[] is in ascending order!!!
long long int LinearSearch(long long int* a, long long int x, long long unsigned int n)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	

	long long unsigned int i = 0; //current array index
	while (i < n && a[i] <= x) { //while index less than size of array, 
		if (a[i] == x) 
		{ 
			return i; 
		} //number was found to return
		i++;
	}


	return -1;
}

long long int BinarySearch(long long int* a, long long int x, long long unsigned int n)
{
	long long int left, right, mid;
	left = 0; right = n - 1;
	

	while (left != right) {
		mid = (left + right) / 2; //find the midpoint

		if (a[mid] == x) {
		
			return mid;
		}
		if (a[mid] > x) { //middle element is BIGGER
			// choose the left part
			right = mid;
		}
		else { //middle element is SMALLER
			left = mid + 1;//or with the optional check: left = mid + 1
		}
	}
	if (a[left] == x) { 
		
		return left; 
	
	}


	return -1;
}

int CountLinearSearch(long long int* a, long long unsigned int n) {


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, n);


	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (int i = 0; i < 10; i++)
	{
		long long int x = dist(gen);

		result = LinearSearch(a, x, n);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

	return time / 10;
}


int CountBinarySearch(long long int* a, long long unsigned int n) {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, n);

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (int i = 0; i < 10; i++)
	{
		long long int x = dist(gen);
		result = BinarySearch(a, x, n);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

	return time / 10;
}

