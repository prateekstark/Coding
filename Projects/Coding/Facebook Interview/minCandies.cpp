#include<iostream>
using namespace std;
int sum(int arr[], int n){
    int temp = 0;
    for(int i=0;i<n;i++){
        temp = temp + arr[i];
    }
    return temp;
}

int minCandies(int arr[], int n){
    int candies[n];
    int i, j;
    for(i=0;i<n;i++){
        candies[i] = 1;
    }
    for(i=0;i<n-1;i++){
        if(arr[i] < arr[i+1]){
            candies[i+1] = candies[i] + 1;
        }
    }
    return sum(candies, n);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minCandies(arr, n)<<endl;
    return 0;
}
