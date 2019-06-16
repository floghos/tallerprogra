// Para este problema utilizaré un heap que no me molesté en crear yo mismo,
// sin embargo el algoritmo para resolver el problema ha sido ideado por mi.
// La implementación del heap utilizado se encuentra en:
// https://www.geeksforgeeks.org/binary-heap/

#include <iostream>
#include <climits>
#include <time.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap {
    int *harr; //pointer to array of elements in heap
    int capacity; //maximum possible size of min heap
    int heap_size; //Current number of elements in min heap
public:
    MinHeap(int capacity);
	~MinHeap() { delete harr; }
    // to heapify a subtree with the root at given index
    void MinHeapify(int i);

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
	int size() { return heap_size; }

	int getMin() { return harr[0]; }
    int popMin();
    void insert(int k);
};

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insert(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insert\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i]) { //this is an upheap
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::popMin() {
    if (heap_size <= 0) return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}


class MaxHeap {
    int *harr;
    int capacity;
    int heap_size;
public:
    MaxHeap(int capacity);
	~MaxHeap() { delete harr; }

    void MaxHeapify(int i);

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
	int size() { return heap_size; }

	int getMax() { return harr[0]; }
    int popMax();
    void insert(int k);
};

MaxHeap::MaxHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MaxHeap::insert(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insert\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] < harr[i]) { //upheap
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int MaxHeap::popMax() {
    if (heap_size <= 0) return INT_MIN;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int greatest = i;

    if (l < heap_size && harr[l] > harr[i]) greatest = l;
    if (r < heap_size && harr[r] > harr[greatest]) greatest = r;

    if (greatest != i) {
        swap(&harr[i], &harr[greatest]);
        MaxHeapify(greatest);
    }
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[]) {
	int max_size = 1000000;

	int days;
	cin >> days;

	while (days) {
		MinHeap minheap(max_size);
		MaxHeap maxheap(max_size);
		int totalCost = 0;
		for (int i = 0; i < days; i++) {
			int suckers;
			cin >> suckers;
			for (int j = 0; j < suckers; j++) {
				int bill;
				cin >> bill;
				minheap.insert(bill);
				maxheap.insert(bill);
			}
			totalCost += maxheap.popMax() - minheap.popMin();
			if (minheap.size() == 1) {
				minheap.popMin();
				maxheap.popMax();
			}
		}

		cout << totalCost << '\n';
		cin >> days;
	}




	//testing heaps
	// srand(time(NULL));
	// for (int i = 0; i < n; i++) {
	// 	minheap.insert(rand() % 1000);
	// 	maxheap.insert(rand() % 1000);
	// }
	//
	// std::cout << "minheap size(): " << minheap.size() << '\n';
	// std::cout << "maxheap size(): " << maxheap.size() << '\n';
	//
	// int total = maxheap.size();
	// for (int i = 0; i < total; i++) {
	// 	std::cout << maxheap.popMax() << '\n';
	// }

	return 0;
}
