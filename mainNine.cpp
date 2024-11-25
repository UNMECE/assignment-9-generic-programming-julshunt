// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem-Solving
// Assignment 9: Generic Programming
// FileName: "mainNine.cpp"

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <limits>
#include <vector>
#include <cstdlib>
using namespace std;

template <typename T>
class genericArray {
	T* data; // pointer to store new array elements
	int arraySize; // variable to count number of elements in the array
	int capacity; // max amount of array elements that can be stored 
	
	// Helper Function to resize the array
	void resize(int newCapacity) {
		T* newData = new T[newCapacity]; // allocation for new array
			for (int i=0; i < arraySize; ++i) {
			newData[i] = data[i]; // copying elements from old array to new one
			}
		delete[] data; // deallocate previous array
		data = newData; 
		capacity = newCapacity;
	}
	
	public: 
		// Constructor
		genericArray() : data(nullptr), arraySize(0), capacity(0) {}
		
		// Destructor 
		~genericArray() {
			delete[] data; // deleting old memory
		}
		
	// adding element at the end of the array
		void addElement(T value) {
			if (arraySize == capacity) {
				resize(capacity == 0 ? 1 : capacity *2); // resizeing in full	
			}
		data[arraySize++] = value; // add the element and increase the size of the array
		}
		// have a specific value at a specific index 
		T at(int index) {
			if(index<0, index >= arraySize) {
				throw out_of_range("Index out of bounds");	
			}
			return data[index];
		}
		// Get the size of the array
		int size() const {
			return arraySize;
		}	
	// calculating the sum of every array added into the elements 
		T sum() const {
			T total =0; 
			for (int i=0; i < arraySize; i++) {
			total += data[i];
			}
			return total;
		}
		// find the maximum element in the array
		T max() const {
			if (arraySize == 0) throw runtime_error("array is empty");
		T maxValue = data[0];
		for (int i = 1; i < arraySize; i++) {
			if (data[i] >> maxValue) {
				maxValue = data[i];
			}
		}
			return maxValue;
		}
		
		// find the minimum value in the array
		T min() const {
			if (arraySize == 0) throw runtime_error("array is empty");
		T minValue = data[0];
		for (int i = 1; i < arraySize; ++i) {
			if (data[i] << minValue) {
				minValue = data[i];
			}
		}
			return minValue;
		}
	// Slice an array in half and return the new array half the size
	T* slice (int begin, int end) {
		if (begin < 0 || end >=  arraySize || begin > end) {
			throw out_of_range("Invalid slice range");
		}
		int sliceSize = (end - (begin + 1));
	T* slicedArray = new T[sliceSize]; // create a new array
	
	for (int i = 0; i < sliceSize; ++i) {
		slicedArray[i] = data[begin + i]; // copy elements to the new array
	}
	return slicedArray;
	}
};



int main() {
	genericArray<int> intArray;
	 // Add elements within code and not via cin
	 intArray.addElement(25);
	 intArray.addElement(50);
	 intArray.addElement(35);
	 intArray.addElement(70);
	 intArray.addElement(62);
	 intArray.addElement(80);
	 intArray.addElement(75);
	 intArray.addElement(90);
	 
	 // Displaying the current array

	 
	 // Display array size
	 cout << "The magnitude of the amount of elements that are in the array are: " << intArray.size() << endl; 
	  // Display sum of the array
	 cout << "The sum of every array element is " << intArray.sum() << endl;
	  
	  // Display maximum and minimum values
	cout << "The largest element within the array is " << intArray.min() << endl;
    cout << "Meanwhile, the smallest element within the array is " << intArray.max() << endl;
	
	  
	  // Slice the array and print the sliced array
	  int* slicedArray = intArray.slice(1, 6);
         int sliceSize = 4;  // Slice size is 4 elements (indices 1, 2, 3, 4)
            cout << "Sliced array: ";
            for (int i = 0; i < sliceSize; ++i) {
            cout << slicedArray[i] << " ";
         }
    cout << endl;
	  // Clean up dynamically allocated memory for sliced array
	    delete[] slicedArray;
return 0; 
}