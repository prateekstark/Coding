#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void quickSort(int arr[], int low, int high){
    if(high>low){
        int pivot = arr[low];
        int pivotIndex = low;
        int i;
        for(i=low+1;i<=high;i++){
            if(arr[i] < pivot){
                arr[pivotIndex] = arr[i];
                arr[i] = pivot;
                pivotIndex = i;
            }
        }
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex+1, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
