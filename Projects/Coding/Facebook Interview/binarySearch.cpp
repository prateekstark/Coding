#include<iostream>
using namespace std;


int binarySearch(int arr[], int low, int high, int key){
    int i, j;
    int mid = (low+high)/2;
    if(high-low>1){
        if(arr[mid] > key){
            return binarySearch(arr, low, mid, key);
        }
        else if(arr[mid] < key){
            return binarySearch(arr, mid, high, key);
        }
        else{
            return mid;
        }
    }
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid+1] == key){
        return (mid+1);
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr, 0, n-1, key)<<endl;
    return 0;
}
