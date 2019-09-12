#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    int n, i, j, k;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int count = 0;
    cin>>k;
    int tempDiff;
    vector<vector<int> > answer;
    for(i=0;i<n-1;i++){
        vector<int> tuple;
        for(j=i+1;j<n;j++){
            tempDiff = arr[i] - arr[j];
            if(tempDiff == k || tempDiff == (-1*k)){
                tuple.push_back(arr[i]);
                tuple.push_back(arr[j]);
                cout<<"("<<arr[i]<<", "<<arr[j]<<")"<<" ";
                count++;
            }
        }
        answer.push_back(tuple);
    }
    cout<<endl<<"count = "<<count<<endl;
    
    return 0;


}
