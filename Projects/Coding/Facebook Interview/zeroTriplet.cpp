#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n, i, j, k;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
