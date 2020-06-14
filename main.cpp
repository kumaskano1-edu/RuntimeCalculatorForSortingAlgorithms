#include <iostream>
#include <vector>
#include <chrono>
#include "SortingAlgorithms.h"
using namespace std;
vector<int> generateVector(int sizeOfArray) {
    std::vector<int> v(sizeOfArray);
    std::generate(v.begin(), v.end(), std::rand);
    return v;
}
/*Function for Printing the Vector
 * @Params: vector of type Integer*/
void PrintVector(vector<int> given) {
    for (std::vector<int>::const_iterator i = given.begin(); i != given.end(); ++i)
        std::cout << *i << ' ';
}
/*Time Check method for the Quick Sort
 * Less code written in main method*/
void QuickSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arrayTest) {
    auto start = chrono::high_resolution_clock::now(); //measure starting time
    /*Execute my Algorithm*/
    algorithms.QuickSort(arrayTest, 0, arrayTest.size()-1);
    auto stop = chrono::high_resolution_clock::now(); //stop the time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //get the difference in MICROSECONDS
    cout << "Time took for Quick Sort: " << duration.count() << endl; //print it
}
int main(){
    /*Constants to Use for the Algorithms*/
    SortingAlgorithms algorithms;
    vector<int> arrayTest = generateVector(100000);
    /*QUICK SORT ALGORITHM TIME CHECK*/


}
