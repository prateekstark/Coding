#include<iostream>
using namespace std;


int findMax(int arr[], int n){
    int tempMax = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > tempMax){
            tempMax = arr[i];
        }
    }
    return tempMax;
}


int longestSubsequence(int arr[], int n){
    int tempArr[n];
    for(int i=0;i<n;i++){
        tempArr[i] = 1;
    }
    int tempMax = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(tempArr[i] < tempArr[j] + 1){
                    tempArr[i] = tempArr[j] + 1;
                }
            }
        }
    }

    return findMax(tempArr, n);
}



int main(){
    int n;
    cin>>n;
    int i, j;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestSubsequence(arr, n)<<endl;
    return 0;
}
