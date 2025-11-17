#include<iostream>
using namespace std;
 int linear_search(int arr[], int n , int x , int &comp){
    comp = 0;
    for (int i = 0 ; i<n ;i++)
    {
        comp++;
        if (arr[i] == x)
        return i;
    }
    return -1 ;

 }