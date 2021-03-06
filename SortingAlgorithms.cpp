//
// Created by Kuma on 6/11/2020.
//
#include "SortingAlgorithms.h"
#include <algorithm>
using namespace std;
SortingAlgorithms::SortingAlgorithms() {
    std::vector<std::vector<int>> fog(0,std::vector<int>(0)); // Defaults to zero initial value
    list = fog;
}
/*Method for Geting the vector
 * By: Kurmanbek Karaev*/
vector<vector<int>> SortingAlgorithms::getList() {
    return this->list;
}
/*Method for the Quick Sort Important Partitioning
 * By: Kurmanbek Karaev
 * */
int SortingAlgorithms::partition(vector<int> &arr,  int left,  int right) {
    int i = left;
    int pivot_value = arr[right];
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot_value)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;

}
/*Method for reading from the file and pushing them to vector within*/
void SortingAlgorithms::readFromFile(string fileName) {
    //Adarsh Shankar: Minor modification 6/17/2020
    string line;
    int count = 0;
    ifstream reader;
    reader.open(fileName);
    if(!reader.is_open()) {
        cout << "not exists file";
        return;
    }
    vector<int> array(0);
    while(getline(reader, line)) { //untill the end of file, there will be a loop
        stringstream ss(line);
        while(getline(ss, line, ',')) { //while the end of the line
            array.push_back(stoi(line)); //insert the num into the vector
        }
    }
    list.push_back(array);
}
/*Iterative Implementation of the Quick Sort
 * By: Kurmanbek*/
vector<int> SortingAlgorithms::QuickSort(vector<int> &array, int start, int end) {
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;
    while(top >= 0)
    {
        end = stack[top--];
        start = stack[top--];
        int pivot_index = partition(array, start, end);
        if (pivot_index - 1 > start )
        {
            stack[++top] = start;
            stack[++top] = pivot_index -1;
        }
        if (pivot_index + 1 < end)
        {
            stack[++top] = pivot_index + 1;
            stack[++top] = end;
        }
    }
    return array;
}

/*Insertion sort implementation
By: Minh Tai Le */
vector<int> SortingAlgorithms::InsertionSort(vector<int> &array){
int i, value, j;
for(i = 1; i < array.size(); i++)
{
    value = array[i];
    j=i-1;
    while(j >= 0 && array[j] > value)
    {
        array[j+1]= array[j];
        j=j-1;
    }
    array[j+1] = value;
}
return array;
}

/*Shell sort implementation
By: Michael Pham*/
vector<int> SortingAlgorithms::ShellSort(vector<int>& array)
{
	int size = array.size();
	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i += 1) {
			int temp = array[i];
			int j;
			//Orders all elemnts in the gap set (shifts them over until sorted)
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
	return array;
}

/*Heapify */
void SortingAlgorithms:: heapify(vector<int>& arr, int n, int i) 
{ //Minor modifications: Adarsh Shankar 6/19/20
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 
/* Heap Sort
    by Michelle Pham*/
void SortingAlgorithms::HeapSort(vector<int>& arr) 
{ //Minor modifications: Adarsh Shankar 6/19/20
	int n = arr.size();
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) { 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 
