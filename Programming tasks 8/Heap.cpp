#include "Heap.h"
#include <iostream>
#include <chrono>  

void Heap::insert(int key)
{
	if (length() >= arrayLength)
		return;

	heaparray[0]++;

	if (length() == 1) {
		heaparray[1] = key;
		return;
	}

	int index = length();
	heaparray[index] = key;

	int parent_index = index / 2;
	while (heaparray[parent_index] > heaparray[index] && index > 1) 
	{
		//swap
		int tmp = heaparray[parent_index];
		heaparray[parent_index] = heaparray[index];
		heaparray[index] = tmp;
		index = parent_index;;
		parent_index /= 2;

	}

	return;
}

int Heap::del_min()
{
	if (length() == 0)
		return -1;

	int toDelete = heaparray[1];
	int currentIndex = 1;


	if (length() == 1) {
		heaparray[0] -= 1;
		return toDelete;
	}

	int currentParent = toDelete;
	int childIndex1 = currentIndex * 2;
	int childIndex2 = childIndex1 + 1;
	int child1 = heaparray[childIndex1];
	int child2 = heaparray[childIndex2];

	heaparray[currentIndex] = heaparray[length()];
	currentParent = heaparray[currentIndex];
	heaparray[0] -= 1;


	while (childIndex2 <= length()) 
	{
		child1 = heaparray[childIndex1];
		child2 = heaparray[childIndex2];

		if (currentParent > child1 || currentParent > child2) 
		{
			if (currentParent > child1 && child1 < child2) {
				heaparray[currentIndex] = child1;
				heaparray[childIndex1] = currentParent;
				currentIndex = childIndex1;
			}
			else
			{
				heaparray[currentIndex] = child2;
				heaparray[childIndex2] = currentParent;
				currentIndex = childIndex2;
			}
			
		}
		else 
		{
			break;
		}
		
		childIndex1 = currentIndex * 2;
		childIndex2 = childIndex1 + 1;

	}

	if (childIndex1 <= length()) 
	{
		child1 = heaparray[childIndex1];

		if (currentParent > child1)
		{
			heaparray[currentIndex] = child1;
			heaparray[childIndex1] = currentParent;
			currentIndex = childIndex1;
			currentParent = child1;
		}
		
	}


	return toDelete;
}

void Heap::print()
{
	for (int i = 1; i <= length(); i++)
	{
		std::cout << heaparray[i] << " ";
	}
	std::cout << std::endl;

}

void Heap::measureSortTime(int num)
{
	int* array = new int[num + 1];

	heaparray = array;

	heaparray[0] = 0;

	arrayLength = num;

	for (int i = 0; i < num; i++)
	{
		int toAdd = rand() % 100000;
		insert(toAdd);
	}


	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	sort();

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

	std::cout << "Time elapsed for sorting of " << num << " elemements is " << time << " ns " << std::endl;
}

void Heap::sort()
{
	int size = length();

	int* sorted = new int[size + 1];

	for (int i = 1; i < size + 1; i++)
	{
		sorted[i] = del_min();
	}

	sorted[0] = size;

	heaparray = sorted;

	delete[] sorted;

}
