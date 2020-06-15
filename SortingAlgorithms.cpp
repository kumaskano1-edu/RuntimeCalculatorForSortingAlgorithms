//
// Created by Kuma on 6/11/2020.
//
#include "SortingAlgorithms.h"
#include <algorithm>
using namespace std;
SortingAlgorithms::SortingAlgorithms() {
    std::vector<std::vector<int> > fog(
            3,
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
    string line;
    int count = 0;
    ifstream reader(fileName);
    if(!reader.is_open()) {
        cout << "not exists file";
        return;
    }
    vector<int> array;
    while(getline(reader, line)) { //untill the end of file, there will be a loop
        stringstream ss(line);
        vector<int> array = list.at(0);
        while(getline(ss, line, ',')) { //while the end of the line
            array.push_back(std::stoi(line)); //insert the num into the vector
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
