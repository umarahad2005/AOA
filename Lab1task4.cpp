#include <iostream>
using namespace std;

void nested_loops(int n, long long &operations)
{
    operations = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            operations++; 
        }
    }
}

int main()
{
    int size[] = {10, 100, 500, 1000, 5000};

    for (int i = 0; i < 5; i++)
    {
        int n = size[i];
        int *arr = new int[n];

        for (int j = 0; j < n; j++)
            arr[j] = j + 1;

        long long ops = 0;

        nested_loops(n, ops);

        cout << "Array size: " << n;
        cout << " | Total operations (nested loops): " << ops << endl;

        delete[] arr;
    }

    return 0;
}
