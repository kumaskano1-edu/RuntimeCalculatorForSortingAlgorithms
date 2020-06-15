//
// Created by Kuma on 6/11/2020.
//
#include "SortingAlgorithms.h"
#include <algorithm>
using namespace std;
SortingAlgorithms::SortingAlgorithms() {
    std::vector<std::vector<int> > fog(
            0,
            std::vector<int>(0)); // Defaults to zero initial value
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
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];
    std::swap(arr[mid], arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
            i++;

        while (i <= j && arr[j] > pivot)
            j--;

        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[i - 1], arr[left]);
    return i - 1;
}
/*Method for reading from the file and pushing them to vector within*/
void SortingAlgorithms::readFromFile(string fileName) {
    string line;
    int count = 0;
    ifstream reader(fileName);
    if(!reader.is_open()) {
        cout << "not exists file";
        return;
    }
    while(getline(reader, line)) { //untill the end of file, there will be a loop
        stringstream ss(line);
        vector<int> array;
        while(getline(ss, line, ',')) { //while the end of the line
            array.push_back(std::stoi(line)); //insert the num into the vector
        }
        count++;
        list.push_back(array);
    }
    reader.close();
}
/*Iterative Implementation of the Quick Sort
 * By: Kurmanbek*/
vector<int> SortingAlgorithms::QuickSort(vector<int> &array, int l, int h) {
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(array, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    return array;
}
