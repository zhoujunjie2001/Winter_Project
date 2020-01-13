#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define ARRAY_SIZE 20

#define SELECTSORT_TEST
#define BUBBLESORT_TEST
#define INSERTSORT_TEST
#define MERGESORT_TEST
#define QUICKSORT_TEST

void print(int* MyArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << MyArray[i] << "\t";
	}
	cout << endl;
}

void Init(int* MyArray, int size) {
	srand((int)time(0));
	for (int i = 0; i < size; i++)
	{
		MyArray[i] = rand() % 100;
	}
}


void SelectSort(int* MyArray, int size) {
	for (int i = 0; i < size - 1; i++) {
		int k = i;
		for (int j = i + 1; j < size; j++)
			if (MyArray[k] > MyArray[j]) k = j;
		if (k != i) {
			int t = MyArray[k]; MyArray[k] = MyArray[i]; MyArray[i] = t;
		}
	}
}

void BubbleSort(int* MyArray, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (MyArray[j] > MyArray[j + 1]) {
				int t = MyArray[j];
				MyArray[j] = MyArray[j + 1];
				MyArray[j + 1] = t;
			}
}

void InsertSort(int* MyArray, int size) {
	for (int i = 1; i < size; i++) {
		int x = MyArray[i], j = i - 1;
		while (x < MyArray[j]) {
			MyArray[j + 1] = MyArray[j];
			j--;
		}
		MyArray[j + 1] = x;
	}
}

void MergeSort_help(int* MyArray, int s, int t) {
	int r[ARRAY_SIZE];
	int m, i, j, k;
	if (s == t) return;
	m = (s + t) / 2;
	MergeSort_help(MyArray, s, m);
	MergeSort_help(MyArray, m + 1, t);
	i = s; j = m + 1; k = s;
	while (i <= m && j <= t) {
		if (MyArray[i] < MyArray[j]) {
			r[k] = MyArray[i]; i++; k++;
		}
		else {
			r[k] = MyArray[j]; j++; k++;
		}
	}
	while (i <= m) {
		r[k] = MyArray[i]; i++; k++;
	}
	while (j <= t) {
		r[k] = MyArray[j]; j++; k++;
	}
	for (int i = s; i <= t; i++) MyArray[i] = r[i];
}

void MergeSort(int* MyArray, int size) {
	MergeSort_help(MyArray, 0, size - 1);
}

void QuickSort_help(int* MyArray, int l, int r) {
	int i, j, mid, t;
	i = l; j = r;
	mid = MyArray[(l + r) / 2];
	do
	{
		while (MyArray[i] < mid) i++;
		while (MyArray[j] > mid) j--;
		if (i <= j) {
			t = MyArray[i]; MyArray[i] = MyArray[j]; MyArray[j] = t;
			i++; j--;
		}
	} while (i <= j);
	if (l < j) QuickSort_help(MyArray, l, j);
	if (i < r) QuickSort_help(MyArray, i, r);
}


void QuickSort(int* MyArray, int size) {
	QuickSort_help(MyArray, 0, size - 1);
}

int main()
{
	int* MyArray = new int[ARRAY_SIZE];

	// Init
	Init(MyArray, ARRAY_SIZE);
	cout << "Before Sort:"; print(MyArray, ARRAY_SIZE);

#ifdef SELECTSORT_TEST
	SelectSort(MyArray, ARRAY_SIZE);
	cout << "After SelectSort:"; print(MyArray, ARRAY_SIZE);
#endif // SELECTSORT_TEST

#ifdef BUBBLESORT_TEST
	BubbleSort(MyArray, ARRAY_SIZE);
	cout << "After BubbleSort:"; print(MyArray, ARRAY_SIZE);
#endif // BUBBLESORT_TEST

#ifdef INSERTSORT_TEST
	InsertSort(MyArray, ARRAY_SIZE);
	cout << "After InsertSort:"; print(MyArray, ARRAY_SIZE);
#endif // INSERTSORT_TEST

#ifdef MERGESORT_TEST
	MergeSort(MyArray, ARRAY_SIZE);
	cout << "After MergeSort:"; print(MyArray, ARRAY_SIZE);
#endif // MERGESORT_TEST

#ifdef QUICKSORT_TEST
	QuickSort(MyArray, ARRAY_SIZE);
	cout << "After QuickSort:"; print(MyArray, ARRAY_SIZE);
#endif // QUICKESORT_TEST
	delete[]MyArray;
}

// Q1: What is the time complexity of your sorting algorithm£¿ 
// the time complexity of SELECTSORT_TEST,BUBBLESORT_TEST,INSERTSORT_TEST is O(N^2)
// because all belong to the situation that one "for" nested in the one "for" 
// the time complexity of MERGESORT_TEST,QUICKESORT_TEST is O(Nlog2N)
// because both using recursion and "dichotomous" to cut the problem into the son problem so that to reduce time

// Q2: What is the loop invariant of your sorting algorithm?
// the loop invariant of sorting algorithm is that the numbers that are sorted are in order,such as MERGESORT_TEST ensure that the numbers between s and t are in order. 

// Q3: What difficulties did you encounter when writing the code?
// emmm,among the period of writing the code,I once write the wrong boundry of a "for" resulting in the number<0 and finally find out it.