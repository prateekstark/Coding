#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    int size_1, size_2;
    cin>>size_1;
    int i,j;
    int arr1[size_1];
    for(i=0;i<size_1;i++){
        cin>>arr1[i];
    }
    cin>>size_2;
    int arr2[size_2];
    for(i=0;i<size_2;i++){
        cin>>arr2[i];
    }
    vector<int> answer;
    int pointer = 0;
    for(i=0;i<size_1;i++){
        for(j=pointer;j<size_2;j++){
            if(arr1[i]==arr2[j]){
                answer.push_back(arr1[i]);
                pointer = j+1;
            }
        }
    }
    printVector(answer);
}
