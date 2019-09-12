#include<iostream>
using namespace std;
void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int* arr, int l, int m, int h){
    int arr1[m-l+1];
    int arr2[h-m];
    int i, j, k;
    for(i=0;i<m-l+1;i++){
        arr1[i] = arr[l+i];
    }
    for(j=0;j<h-m;j++){
        arr2[j] = arr[m+j+1];
    }
    k = 0;
    j = 0;
    for(i=l;i<h+1;i++){
        if(k<m-l+1 && j<h-m){
            if(arr1[k] <= arr2[j]){
                arr[i] = arr1[k];
                k++;
            }
            else if(arr1[k] > arr2[j]){
                arr[i] = arr2[j];
                j++;
            }
        }
        else if(k == m-l+1){
            arr[i] = arr2[j];
            j++;
        }
        else if(j == h-m){
            arr[i] = arr1[k];
            k++;
        }
    }
    return;
}

void mergeSort(int *arr, int low, int high){
    if(low == high){
        return;
    }
    if(high - low == 1){
        if(arr[high] < arr[low]){
            int temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
            return;
        }
        else{
            return;
        }
    }
    int mid = low + ((high-low)/2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
    return;
}


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
