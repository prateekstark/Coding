#include<iostream>
#include<algorithm>
using namespace std;

int findReducedLength(int arr[], int n, int key){
    int slow, fast;
    slow = 0;
    int temp;

    for(fast=0;fast<n;fast++){
        if(arr[fast] != key){
            temp = arr[slow];
            arr[slow] = arr[fast];
            arr[fast] = temp;
        }
        if(arr[slow] != key){
            slow++;
        }
    }
    return slow;
}


void findPermutation()











int  main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    // cout<<findReducedLength(arr, n, 2)<<endl;
    vector<vector<int> > uniquePermutations;
    vector<int> tempList;
    bool used[n] = {0};
    return 0;
}
