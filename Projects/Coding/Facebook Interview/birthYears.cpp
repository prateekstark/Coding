#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int count = 1, maxCount = 0, maxYear;
    for(i=0;i<n-1;i++){
        if(arr[i+1] != arr[i]){
            if(count > maxCount){
                maxCount = count;
                maxYear = arr[i];
            }
            count = 1;
        }
        count++;
    }
    if(count > maxCount){
        maxCount = count;
        maxYear = arr[n-1];
    }
    cout<<maxYear<<endl;
    return 0;
}
