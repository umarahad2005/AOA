#include <iostream>
#include <vector>
using namespace std;

int comparisonCount = 0; 

int merge_sort(vector<int>& parcels, int left, int right){
    if(left >= right){
        return 0;
    }
    int mid = left + (right - left) / 2;
    merge_sort(parcels, left, mid);
    merge_sort(parcels, mid + 1, right);
    vector<int> temp;
    int i = left, j = mid + 1;
    while(i <= mid && j <= right){
        comparisonCount++; 
        if(parcels[i] <= parcels[j]){
            temp.push_back(parcels[i]);
            i++;
        }else{
            temp.push_back(parcels[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(parcels[i]);
        i++;
    }
    while(j <= right){
        temp.push_back(parcels[j]);
        j++;
    }
    for(int k = left; k <= right; k++){
        parcels[k] = temp[k - left];
    }
    return 0;

}
int main(){
    cout<<"welcome to the world of programming that use the merge sort as a divide and conquer algorithm"<<endl;
    cout<<"kindly enter the number of total parcel : ";
    int n;
    cin>>n;
    vector<int> parcels(n);
    for(int i=0; i<n; i++){
        cout<<"now enter the tracking id of the parcel " <<i+1<<" : ";
        cin>>parcels[i];
    }
    merge_sort(parcels, 0, n - 1);
    cout<<"the sorted tracking id of the parcels are : "<<endl;
    for(int i=0; i<n; i++){
        cout<<parcels[i]<<" ";
    }
    cout<<endl;
    cout<<"Total number of comparisons: "<<comparisonCount<<endl;
}
