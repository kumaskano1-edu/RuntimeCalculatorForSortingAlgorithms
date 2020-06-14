//
// Created by Kuma on 6/11/2020.
//
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#ifndef GROUPPROJECT_SORTINGALGORITHMS_H
#define GROUPPROJECT_SORTINGALGORITHMS_H
using namespace std;

class SortingAlgorithms {
    public:
        SortingAlgorithms();
        int partition(vector<int> &arr,  int startIn,  int endIn );
        vector<int> QuickSort(vector<int> &array, int startIn, int endIn);
};


#endif //GROUPPROJECT_SORTINGALGORITHMS_H
