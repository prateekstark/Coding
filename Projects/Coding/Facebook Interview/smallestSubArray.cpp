#include<iostream>
using namespace std;
int sumArray(int arr[], int i, int j){
    int tempSum = 0;
    for(int a=i;a<j+1;a++){
        tempSum = tempSum + arr[a];
    }
    return tempSum;
}

int main(){
    int n;
    cin>>n;
    int i, j, k;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(sumArray(arr, j, j+i) > k){
                cout<<(i+1)<<endl;
                return 0;
            }

        }
    }
    cout<<"Not Possible"<<endl;

    return 0;
}
