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
    vector<int> v(sizeOfArray);
    generate(v.begin(), v.end(), std::rand);
    if(sorted) {
        std::sort (v.begin(), v.end());
    } else if(reverse)  {
        std::sort (v.begin(), v.end(), less<int>());
    }
    return v;
}
/*Time Check method for the Quick Sort
 * Less code written in main method*/
void QuickSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arrayTest) {
    auto start = chrono::high_resolution_clock::now(); //measure starting time
    /*Execute my Algorithm*/
    algorithms.QuickSort(arrayTest, 0, arrayTest.size()-1);
    std::sort (arrayTest.begin(), arrayTest.end());
    auto stop = chrono::high_resolution_clock::now(); //stop the time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //get the difference in MICROSECONDS
    cout << "Time took for Quick Sort: " << duration.count() << " microseconds" << endl; //print it
}
/* Time check for Insertion Sort*/
void InsertionSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arraytest)
{
    auto start = chrono::high_resolution_clock::now();
    algorithms.InsertionSort(arraytest);
     auto stop = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     cout << "Time took for Insertion Sort: " << duration.count() << " microseconds" << endl;
}
/* Time check for Shell Sort*/
void ShellSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arraytest)
{
    auto start = chrono::high_resolution_clock::now();
    algorithms.ShellSort(arraytest);
     auto stop = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     cout << "Time took for Shell Sort: " << duration.count() << " microseconds" << endl;
}
/* Time check for Heap Sort*/
void HeapSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arraytest)
{
    auto start = chrono::high_resolution_clock::now();
    algorithms.HeapSort(arraytest);
     auto stop = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     cout << "Time took for Heap Sort: " << duration.count() << " microseconds" << endl;
}
/* Time check for STD Sort*/
void stdSortAlgorithmTimeCheck(SortingAlgorithms algorithms, vector<int> arraytest)
{
    auto start = chrono::high_resolution_clock::now();
    sort(arraytest.begin(), arraytest.end());
     auto stop = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     cout << "Time took for std::Sort : " << duration.count() << " microseconds" << endl;
}
/* -------------------- TESTING DRIVER CODE: Adarsh Shankar 6/19/2020 ------------------------- */
int main(){
    /*Constants to Use for the Algorithms*/
    SortingAlgorithms algorithms;
    algorithms.readFromFile("./random.txt");
    vector<int> random, ascending, descending; //BIG DATA Arrays (10,000+ size)
    vector<int> r1,r2,r3,r4,r5,r6,r7; //Smaller sized array: Random
    vector<int> a1,a2,a3,a4,a5,a6,a7; //Smaller sized array: Ascending
    vector<int> d1,d2,d3,d4,d5,d6,d7; //Smaller sized array: Descending
    
	//Initializing random vectors
	r1 = generateVector(1000,0,0);
	r2 = generateVector(2500,0,0);
	r3 = generateVector(5000,0,0);
	r4 = generateVector(7500,0,0);
	r5 = generateVector(10000,0,0);
	r6 = generateVector(12500,0,0);
	r7 = generateVector(15000,0,0);
	//Initializing ascending vectors
	a1 = generateVector(1000,0,0);
	a2 = generateVector(2500,0,0);
	a3 = generateVector(5000,0,0);
	a4 = generateVector(7500,0,0);
	a5 = generateVector(10000,0,0);
	a6 = generateVector(12500,0,0);
	a7 = generateVector(15000,0,0);
	//Initializing descending vectors
	d1 = generateVector(1000,0,0);
	d2 = generateVector(2500,0,0);
	d3 = generateVector(5000,0,0);
	d4 = generateVector(7500,0,0);
	d5 = generateVector(10000,0,0);
	d6 = generateVector(12500,0,0);
	d7 = generateVector(15000,0,0);
    
    
    cout << "---- Quick Sort Testing ----" << endl;
    cout << "---- Random ----" << endl;
    cout << "Input size: 1000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r1);
    cout << "Input size: 2500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r2);
    cout << "Input size: 5000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r3);
    cout << "Input size: 7500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r4);
    cout << "Input size: 10000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r5);
    cout << "Input size: 125000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r6);
    cout << "Input size: 150000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, r7);
    cout << "---- Ascending ----" << endl;
    cout << "Input size: 1000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a1);
    cout << "Input size: 2500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a2);
    cout << "Input size: 5000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a3);
    cout << "Input size: 7500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a4);
    cout << "Input size: 10000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a5);
    cout << "Input size: 125000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a6);
    cout << "Input size: 150000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, a7);
    cout << "---- Descending ----" << endl;
    cout << "Input size: 1000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d1);
    cout << "Input size: 2500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d2);
    cout << "Input size: 5000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d3);
    cout << "Input size: 7500" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d4);
    cout << "Input size: 10000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d5);
    cout << "Input size: 125000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d6);
    cout << "Input size: 150000" << endl;
    QuickSortAlgorithmTimeCheck(algorithms, d7);
    
    cout << "---- Insertion Sort Testing ----" << endl;
    cout << "---- Random ----" << endl;
    cout << "Input size: 1000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r1);
    cout << "Input size: 2500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r2);
    cout << "Input size: 5000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r3);
    cout << "Input size: 7500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r4);
    cout << "Input size: 10000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r5);
    cout << "Input size: 125000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r6);
    cout << "Input size: 150000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, r7);
    cout << "---- Ascending ----" << endl;
    cout << "Input size: 1000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a1);
    cout << "Input size: 2500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a2);
    cout << "Input size: 5000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a3);
    cout << "Input size: 7500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a4);
    cout << "Input size: 10000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a5);
    cout << "Input size: 125000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a6);
    cout << "Input size: 150000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, a7);
    cout << "---- Descending ----" << endl;
    cout << "Input size: 1000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d1);
    cout << "Input size: 2500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d2);
    cout << "Input size: 5000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d3);
    cout << "Input size: 7500" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d4);
    cout << "Input size: 10000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d5);
    cout << "Input size: 125000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d6);
    cout << "Input size: 150000" << endl;
    InsertionSortAlgorithmTimeCheck(algorithms, d7);
    
    
    cout << "---- Shell Sort Testing ----" << endl;
    cout << "---- Random ----" << endl;
    cout << "Input size: 1000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r1);
    cout << "Input size: 2500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r2);
    cout << "Input size: 5000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r3);
    cout << "Input size: 7500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r4);
    cout << "Input size: 10000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r5);
    cout << "Input size: 125000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r6);
    cout << "Input size: 150000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, r7);
    cout << "---- Ascending ----" << endl;
    cout << "Input size: 1000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a1);
    cout << "Input size: 2500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a2);
    cout << "Input size: 5000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a3);
    cout << "Input size: 7500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a4);
    cout << "Input size: 10000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a5);
    cout << "Input size: 125000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a6);
    cout << "Input size: 150000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, a7);
    cout << "---- Descending ----" << endl;
    cout << "Input size: 1000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d1);
    cout << "Input size: 2500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d2);
    cout << "Input size: 5000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d3);
    cout << "Input size: 7500" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d4);
    cout << "Input size: 10000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d5);
    cout << "Input size: 125000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d6);
    cout << "Input size: 150000" << endl;
    ShellSortAlgorithmTimeCheck(algorithms, d7);
    
    
    cout << "---- Heap Sort Testing ----" << endl;
    cout << "---- Random ----" << endl;
    cout << "Input size: 1000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r1);
    cout << "Input size: 2500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r2);
    cout << "Input size: 5000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r3);
    cout << "Input size: 7500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r4);
    cout << "Input size: 10000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r5);
    cout << "Input size: 125000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r6);
    cout << "Input size: 150000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, r7);
    cout << "---- Ascending ----" << endl;
    cout << "Input size: 1000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a1);
    cout << "Input size: 2500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a2);
    cout << "Input size: 5000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a3);
    cout << "Input size: 7500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a4);
    cout << "Input size: 10000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a5);
    cout << "Input size: 125000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a6);
    cout << "Input size: 150000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, a7);
    cout << "---- Descending ----" << endl;
    cout << "Input size: 1000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d1);
    cout << "Input size: 2500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d2);
    cout << "Input size: 5000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d3);
    cout << "Input size: 7500" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d4);
    cout << "Input size: 10000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d5);
    cout << "Input size: 125000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d6);
    cout << "Input size: 150000" << endl;
    HeapSortAlgorithmTimeCheck(algorithms, d7);
    
    
    cout << "---- std::Sort Testing ----" << endl;
    cout << "---- Random ----" << endl;
    cout << "Input size: 1000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r1);
    cout << "Input size: 2500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r2);
    cout << "Input size: 5000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r3);
    cout << "Input size: 7500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r4);
    cout << "Input size: 10000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r5);
    cout << "Input size: 125000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r6);
    cout << "Input size: 150000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, r7);
    cout << "---- Ascending ----" << endl;
    cout << "Input size: 1000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a1);
    cout << "Input size: 2500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a2);
    cout << "Input size: 5000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a3);
    cout << "Input size: 7500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a4);
    cout << "Input size: 10000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a5);
    cout << "Input size: 125000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a6);
    cout << "Input size: 150000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, a7);
    cout << "---- Descending ----" << endl;
    cout << "Input size: 1000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d1);
    cout << "Input size: 2500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d2);
    cout << "Input size: 5000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d3);
    cout << "Input size: 7500" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d4);
    cout << "Input size: 10000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d5);
    cout << "Input size: 125000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d6);
    cout << "Input size: 150000" << endl;
    stdSortAlgorithmTimeCheck(algorithms, d7);
    
    return 0;
}


/* ----------------- SAMPLE OUTPUT --------------------
---- Quick Sort Testing ----
---- Random ----
Input size: 1000
Time took for Quick Sort: 0 microseconds
Input size: 2500
Time took for Quick Sort: 999 microseconds
Input size: 5000
Time took for Quick Sort: 1998 microseconds
Input size: 7500
Time took for Quick Sort: 3004 microseconds
Input size: 10000
Time took for Quick Sort: 4003 microseconds
Input size: 125000
Time took for Quick Sort: 5996 microseconds
Input size: 150000
Time took for Quick Sort: 8000 microseconds
---- Ascending ----
Input size: 1000
Time took for Quick Sort: 0 microseconds
Input size: 2500
Time took for Quick Sort: 1995 microseconds
Input size: 5000
Time took for Quick Sort: 2999 microseconds
Input size: 7500
Time took for Quick Sort: 4002 microseconds
Input size: 10000
Time took for Quick Sort: 5000 microseconds
Input size: 125000
Time took for Quick Sort: 6000 microseconds
Input size: 150000
Time took for Quick Sort: 7997 microseconds
---- Descending ----
Input size: 1000
Time took for Quick Sort: 0 microseconds
Input size: 2500
Time took for Quick Sort: 999 microseconds
Input size: 5000
Time took for Quick Sort: 1998 microseconds
Input size: 7500
Time took for Quick Sort: 3997 microseconds
Input size: 10000
Time took for Quick Sort: 4998 microseconds
Input size: 125000
Time took for Quick Sort: 5996 microseconds
Input size: 150000
Time took for Quick Sort: 7999 microseconds
---- Insertion Sort Testing ----
---- Random ----
Input size: 1000
Time took for Insertion Sort: 2999 microseconds
Input size: 2500
Time took for Insertion Sort: 15999 microseconds
Input size: 5000
Time took for Insertion Sort: 66001 microseconds
Input size: 7500
Time took for Insertion Sort: 147998 microseconds
Input size: 10000
Time took for Insertion Sort: 259075 microseconds
Input size: 125000
Time took for Insertion Sort: 394998 microseconds
Input size: 150000
Time took for Insertion Sort: 569999 microseconds
---- Ascending ----
Input size: 1000
Time took for Insertion Sort: 2072 microseconds
Input size: 2500
Time took for Insertion Sort: 15073 microseconds
Input size: 5000
Time took for Insertion Sort: 63071 microseconds
Input size: 7500
Time took for Insertion Sort: 157004 microseconds
Input size: 10000
Time took for Insertion Sort: 272070 microseconds
Input size: 125000
Time took for Insertion Sort: 402997 microseconds
Input size: 150000
Time took for Insertion Sort: 575068 microseconds
---- Descending ----
Input size: 1000
Time took for Insertion Sort: 1997 microseconds
Input size: 2500
Time took for Insertion Sort: 15997 microseconds
Input size: 5000
Time took for Insertion Sort: 63076 microseconds
Input size: 7500
Time took for Insertion Sort: 140998 microseconds
Input size: 10000
Time took for Insertion Sort: 255996 microseconds
Input size: 125000
Time took for Insertion Sort: 401998 microseconds
Input size: 150000
Time took for Insertion Sort: 603991 microseconds
---- Shell Sort Testing ----
---- Random ----
Input size: 1000
Time took for Shell Sort: 0 microseconds
Input size: 2500
Time took for Shell Sort: 1000 microseconds
Input size: 5000
Time took for Shell Sort: 1999 microseconds
Input size: 7500
Time took for Shell Sort: 2996 microseconds
Input size: 10000
Time took for Shell Sort: 3999 microseconds
Input size: 125000
Time took for Shell Sort: 5999 microseconds
Input size: 150000
Time took for Shell Sort: 6004 microseconds
---- Ascending ----
Input size: 1000
Time took for Shell Sort: 999 microseconds
Input size: 2500
Time took for Shell Sort: 1067 microseconds
Input size: 5000
Time took for Shell Sort: 1999 microseconds
Input size: 7500
Time took for Shell Sort: 3069 microseconds
Input size: 10000
Time took for Shell Sort: 3998 microseconds
Input size: 125000
Time took for Shell Sort: 6000 microseconds
Input size: 150000
Time took for Shell Sort: 7002 microseconds
---- Descending ----
Input size: 1000
Time took for Shell Sort: 997 microseconds
Input size: 2500
Time took for Shell Sort: 1000 microseconds
Input size: 5000
Time took for Shell Sort: 1998 microseconds
Input size: 7500
Time took for Shell Sort: 2998 microseconds
Input size: 10000
Time took for Shell Sort: 5001 microseconds
Input size: 125000
Time took for Shell Sort: 5996 microseconds
Input size: 150000
Time took for Shell Sort: 7067 microseconds
---- Heap Sort Testing ----
---- Random ----
Input size: 1000
Time took for Heap Sort: 998 microseconds
Input size: 2500
Time took for Heap Sort: 1000 microseconds
Input size: 5000
Time took for Heap Sort: 1999 microseconds
Input size: 7500
Time took for Heap Sort: 3996 microseconds
Input size: 10000
Time took for Heap Sort: 5999 microseconds
Input size: 125000
Time took for Heap Sort: 7004 microseconds
Input size: 150000
Time took for Heap Sort: 7999 microseconds
---- Ascending ----
Input size: 1000
Time took for Heap Sort: 0 microseconds
Input size: 2500
Time took for Heap Sort: 998 microseconds
Input size: 5000
Time took for Heap Sort: 3000 microseconds
Input size: 7500
Time took for Heap Sort: 4001 microseconds
Input size: 10000
Time took for Heap Sort: 5072 microseconds
Input size: 125000
Time took for Heap Sort: 6002 microseconds
Input size: 150000
Time took for Heap Sort: 7068 microseconds
---- Descending ----
Input size: 1000
Time took for Heap Sort: 996 microseconds
Input size: 2500
Time took for Heap Sort: 1071 microseconds
Input size: 5000
Time took for Heap Sort: 2928 microseconds
Input size: 7500
Time took for Heap Sort: 4071 microseconds
Input size: 10000
Time took for Heap Sort: 4995 microseconds
Input size: 125000
Time took for Heap Sort: 7075 microseconds
Input size: 150000
Time took for Heap Sort: 8995 microseconds
---- std::Sort Testing ----
---- Random ----
Input size: 1000
Time took for std::Sort : 0 microseconds
Input size: 2500
Time took for std::Sort : 0 microseconds
Input size: 5000
Time took for std::Sort : 1004 microseconds
Input size: 7500
Time took for std::Sort : 1997 microseconds
Input size: 10000
Time took for std::Sort : 3003 microseconds
Input size: 125000
Time took for std::Sort : 4003 microseconds
Input size: 150000
Time took for std::Sort : 5001 microseconds
---- Ascending ----
Input size: 1000
Time took for std::Sort : 0 microseconds
Input size: 2500
Time took for std::Sort : 0 microseconds
Input size: 5000
Time took for std::Sort : 2004 microseconds
Input size: 7500
Time took for std::Sort : 1996 microseconds
Input size: 10000
Time took for std::Sort : 2995 microseconds
Input size: 125000
Time took for std::Sort : 3006 microseconds
Input size: 150000
Time took for std::Sort : 4995 microseconds
---- Descending ----
Input size: 1000
Time took for std::Sort : 0 microseconds
Input size: 2500
Time took for std::Sort : 0 microseconds
Input size: 5000
Time took for std::Sort : 998 microseconds
Input size: 7500
Time took for std::Sort : 2001 microseconds
Input size: 10000
Time took for std::Sort : 4001 microseconds
Input size: 125000
Time took for std::Sort : 4007 microseconds
Input size: 150000
Time took for std::Sort : 4073 microseconds

--------------------------------
Process exited after 5.324 seconds with return value 0
Press any key to continue . . .
*/
