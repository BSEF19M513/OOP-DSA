// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
int search(long int arr[], int n, long int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int count = 0;
long int *readDataFile()
{

    fstream file;
    string fileName ;
    cout << "Enter the name of file: ";
    cin >> fileName ;
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

int main(void)
{
    time_t t1, t2;
    srand(time(0));
    long int *arr = readDataFile();
    long int x = 10;

    time(&t1);

    int result = search(arr, count, x);
    time(&t2);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    cout << endl;
    double sort_time = t2 - t1;
    cout << "Time taken by sortArray: " << sort_time << " seconds" << endl
         << endl;
    delete[] arr;
    return 0;
}
