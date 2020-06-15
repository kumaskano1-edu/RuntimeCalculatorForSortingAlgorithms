//
// Created by Group 7 on 6/11/2020.
//
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#ifndef GROUPPROJECT_SORTINGALGORITHMS_H
#define GROUPPROJECT_SORTINGALGORITHMS_H
using namespace std;

class SortingAlgorithms {
    vector<vector<int>> list;
    public:
        SortingAlgorithms();
        vector<vector<int>> getList();
        void readFromFile(string fileName);
        int partition(vector<int> &arr,  int startIn,  int endIn );
        vector<int> QuickSort(vector<int> &array, int startIn, int endIn);
        vector<int>InsertionSort(vector<int> &array);
};


#endif //GROUPPROJECT_SORTINGALGORITHMS_H
