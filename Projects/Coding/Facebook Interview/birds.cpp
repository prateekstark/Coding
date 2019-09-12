#include<iostream>
using namespace std;

int sumArray(int arr, int n, int m){
    int result = 0;
    for(int i=n;i<m;i++){
        result = result + arr[i%n];
    }
    return result;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j;
    int m;
    cin>>m;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int tempSum = sumArray(arr, 0, m);
    for(i=0;i<n;i++){
        if(sumArray(arr, i, i + m) > tempSum){
            tempSum = sumArray(arr, i, i + m);
        }
    }
    cout<<tempSum<<endl;
    return 0;
}
