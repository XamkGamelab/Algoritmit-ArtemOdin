#pragma once
#define MAX_SIZE 256

class Heap 
{
public:
	Heap(){
		heaparray = new int[MAX_SIZE + 1];
		heaparray[0] = 0;
	}

	void insert(int key);
	int del_min();
	void print();
	int length() { return heaparray[0]; }
	void measureSortTime(int num);
	void sort();
private:
	int* heaparray;
	int arrayLength = MAX_SIZE;
};