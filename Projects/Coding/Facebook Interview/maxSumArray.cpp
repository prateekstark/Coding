#include<iostream>
#include<vector>
using namespace std;

int sumArray(int arr[], int i, int j){
    int maxSum = 0;
    for(int a=i;a<j+1;a++){
        maxSum = maxSum + arr[a];
    }
    return maxSum;
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j, k;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> answer;
    int maxSum = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(maxSum < sumArray(arr, j, j+i)){
                maxSum = sumArray(arr, j, j+i);
                answer.clear();
                for(k=j;k<j+i+1;k++){
                    answer.push_back(arr[k]);
                }
            }
        }
    }
    printVector(answer);
    return 0;
}
