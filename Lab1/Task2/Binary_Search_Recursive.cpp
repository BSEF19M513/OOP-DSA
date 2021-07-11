// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
#include <iostream>
#include<fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
// A recursive binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearchRecr(long int arr[], int l, int r,long int x)
{
    int mid;
    if (r >= l)
    {
        mid = l + (r - l) / 2;
    }
    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
        return mid;
    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
        return binarySearchRecr(arr, l, mid - 1, x);
    // Else the element can only be present
    // in right subarray
    return binarySearchRecr(arr, mid + 1, r, x);
}

int search(long int arr[], int n,long int x)
{
    return binarySearchRecr(arr, 0, n - 1, x);
}


int count = 0;
long int *readDataFile()
{

    fstream file;
    string file_Name;
    cout << "Enter name of file: ";
    cin >> file_Name;
    file.open(file_Name.c_str());
    if (!file)
    {
        cout << "Error in file Opening.";
        exit(0);  //exit(0)
    }

    string line1;
    string line2;
    while (getline(file, line1))
    {
        stringstream ss(line1);   //read the whole line1
        while (getline(ss, line2, ','))  // 
        {
            count++;
        }
    }
    file.close();
    long int *arr = new long int[count];
    int i = 0;
    file.open(file_Name.c_str());

    if (!file)
    {
        cout << "Error in file Opening.";
        exit(0);  //exit(0)
    }
    while (getline(file, line1))
    {

        stringstream ss(line1);   //
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
    long int x = 10;
    time(&t1); //Again using variable t1
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
