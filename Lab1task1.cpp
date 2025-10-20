#include <iostream>
using namespace std;

int  linear_search(int arr[], int n, int x,int &comp) 
{   comp = 0;
    for (int i = 0; i < n; i++)
    {
     comp ++;
      if (arr[i] == x) 
      return i;   
    }
        return -1;

}

int main()
 {
   int size[] = { 10, 100, 500, 1000, 5000};
   for ( int i = 0 ; i < 5 ; i++)
   {
    int n = size [i];
    int *arr = new int [n];
    for (int i = 0 ; i< n ; i++)
        arr [i]=i+1;

        int comp = 0 ;
        int x = -1;
        linear_search(arr,n,x,comp );
        cout << " array size : "<< n;
        cout << " | total comparisons : "<< comp << endl;
        delete [] arr;

    }
return 0;
}

