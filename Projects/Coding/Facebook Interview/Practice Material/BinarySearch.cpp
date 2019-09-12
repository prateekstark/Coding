#include<iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key){
    if(low == high){
        if(arr[low] == key){
            return low;
        }
        else{
            return -1;
        }
    }

    else if((high - low) == 1){
        if(arr[low] == key){
            return low;
        }
        else if(arr[high] == key){
            return high;
        }
        else{
            return -1;
        }
    }

    int mid = (low+high)/2;
    if(arr[mid] == key){
        return mid;
    }

    else if(arr[mid] < key){
        return BinarySearch(arr, mid, high, key);
    }

    else if(arr[mid] > key){
        return BinarySearch(arr, low, mid, key);
    }

    return -1;
}


int main(){
    int n;
    cin>>n;
    int i;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<BinarySearch(arr, 0, n-1, key)<<endl;
    return 0;
}
