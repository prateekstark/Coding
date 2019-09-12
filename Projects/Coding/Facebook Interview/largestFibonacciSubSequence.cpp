#include<iostream>
#include<vector>
using namespace std;

bool searchVector(vector<int> sequence, int value){
    for(int i=0;i<sequence.size();i++){
        if(value==sequence.at(i)){
            return true;
        }
    }
    return false;
}

vector<int> makeFibonnacci(){
    vector<int> fibonacciSequence;
    int t1 = 1;
    int t2 = 1;
    int temp;
    fibonacciSequence.push_back(1);
    fibonacciSequence.push_back(1);
    for(int i=0;i<47;i++){
        temp = t1+t2;
        t1 = t2;
        t2 = temp;
        fibonacciSequence.push_back(temp);
    }
    return fibonacciSequence;
}

void viewVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int i,j;
    cin>>n;
    int arr[n];
    vector<int> fibSequence = makeFibonnacci();
    vector<int> finalSubsequence;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(searchVector(fibSequence, arr[i])){
            finalSubsequence.push_back(arr[i]);
        }
    }
    viewVector(finalSubsequence);
}
