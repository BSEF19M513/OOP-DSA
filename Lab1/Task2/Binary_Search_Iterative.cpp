// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
#include <iostream>
#include<fstream>
#include<sstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearchIter(long int arr[], int l, int r,long int x)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    // if we reach here, then element was
    // not present
    return -1;
}

int search(long int arr[], int n,long int x)
{
    return binarySearchIter(arr, 0, n - 1, x);
}

int count = 0;
long int *readDataFile()
{

    fstream file;
    string fileName;
    cout << "Enter the name of file: ";
    cin >> fileName;
    file.open(fileName.c_str());
    if (!file)
    {
        cout << "Error in File Opening.";
        exit(0);
    }

    string line1;
    string line2;
    while (getline(file, line1))
    {
        stringstream ss(line1);
        while (getline(ss, line2, ','))
        {
            count++;
        }
    }
    file.close();
    long int *arr = new long int[count];
    int i = 0;
    file.open(fileName.c_str());

    if (!file)
    {
        cout << "Error in File Opening.";
        exit(0);
    }
    while (getline(file, line1))
    {

        stringstream ss(line1);
        while (getline(ss, line2, ','))
        {
            stringstream sss(line2);
            sss >> arr[i];
            i++;
        }
    }
    return arr;
}

// Driver code
int main(void)
{
    time_t t1, t2;
    srand(time(0));
    long int *arr = readDataFile();
    long int x = 8637;
    time(&t1); 

    // Function call
    long int result = search(arr, count, x);
    time(&t2);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    cout << endl;
    double sort_time = t2 - t1;
    cout << "Time taken by sortArray: " << sort_time << " seconds" << endl
         << endl;
    return 0;
}
