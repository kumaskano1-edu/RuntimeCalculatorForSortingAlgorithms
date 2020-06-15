#include <iostream>
#include <vector>
#include <chrono>
#include "SortingAlgorithms.h"
using namespace std;
/*Function for Printing the Vector
 * @Params: vector of type Integer*/
void PrintVector(vector<int> given) {
    for (std::vector<int>::const_iterator i = given.begin(); i != given.end(); ++i)
        std::cout << *i << ',';
}
/*Function for generating different arrays with given size and preferences
 * Parameters: sizeOfarray = size of the array
 *             sorted = means you want to generate already sorted array
 *             reverse = if sorted is true and reverse is true. Method will generate reversely sorted vector*/
vector<int> generateVector(int sizeOfArray, bool sorted, bool reverse) {
    std::vector<int> v(sizeOfArray);
    std::generate(v.begin(), v.end(), std::rand);
    if(sorted) {
        std::sort (v.begin(), v.end());
    } else if(reverse)  {
        std::sort (v.begin(), v.end(), less<int>());
    }
    PrintVector(v);
    return v;
}
/*Time Check method for the Quick Sort
 * Less code written in main method*/
void QuickSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arrayTest) {
    auto start = chrono::high_resolution_clock::now(); //measure starting time
    /*Execute my Algorithm*/
    //algorithms.QuickSort(arrayTest, 0, arrayTest.size()-1);
    std::sort (arrayTest.begin(), arrayTest.end());
    auto stop = chrono::high_resolution_clock::now(); //stop the time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //get the difference in MICROSECONDS
    cout << "Time took for Quick Sort: " << duration.count() << " microseconds" << endl; //print it
}
/*The Method for reading teh array from the file*/
int main(){
    /*Constants to Use for the Algorithms*/
    SortingAlgorithms algorithms;
    algorithms.readFromFile("C:\\Users\\Kuma\\CLionProjects\\GroupProject\\ascending.txt");
    vector<int> loss = algorithms.getList()[0];
    QuickSortAlgorithmTimeCheck(algorithms, loss);
}
