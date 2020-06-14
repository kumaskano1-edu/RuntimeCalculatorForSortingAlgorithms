//
// Created by Kuma on 6/11/2020.
//
#include "SortingAlgorithms.h"
#include <algorithm>
using namespace std;
SortingAlgorithms::SortingAlgorithms() {

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
/*Iterative Implementation of the Quick Sort*/
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
