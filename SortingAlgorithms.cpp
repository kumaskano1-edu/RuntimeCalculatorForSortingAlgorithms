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
    sstring line;
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
    
/* Heap Sort
    by Michelle Pham*/
vector<int> SortingAlgorithms::HeapSort(vector<int>& array)
{
    int size = array.size();

    //build heap
    for (int i = size / 2 - 1, i >= 0; i--)
        heapify(array, size, i);

    //
    for (int i = size - 1; i > 0; i--)
    {
        //move root to end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        //call heapify on heap
        heapify(0, array, i);
    }
}

/*Heapify */
void SortingAlgorithms::heapify(vector<int>& array, int size, int i)
{
    int largest = i;        //largest is root
    int left = 2 * i + 1;
    int right = 2 * i + 1;

    //if left child is larger than root
    if (left < size && array[left] > array[largest])
        largest = left;

    //if right child is larger that root
    if (right < size && array[right] > array[largest])
        largest = right;

    //if largest is not root
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        //heapify affected subtree
        heapify(array, size, largest);
    }
}