#include<iostream>
using namespace std;

bool isValid(int arr[], int n){
    if(n == 1 || n == 2){
        return 1;
    }
    int val1, val2, val3;
    val1 = arr[0];
    val2 = arr[1];
    val3 = arr[2];
    int numSame;
    if(val1 == val2 || val1 == val3){
        numSame = val1;
    }
    else if(val2 == val3){
        numSame = val3;
    }
    else{
        return 0;
    }
    int tempCount = 0;
    for(int i=0;i<26;i++){
        if(arr[i] != 0){
            if(arr[i] - numSame > 1 || arr[i] - numSame < -1){
                return 0;
            }
            else if(arr[i] - numSame == 1 || arr[i] - numSame == -1){
                tempCount++;
            }
            if(tempCount>1){
                return 0;
            }
        }
    }
    return 1;
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    string inputString;
    cin>>inputString;
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i] = 0;
    }
    for(int i=0;i<inputString.size();i++){
        arr[inputString.at(i) - 'a']++;
    }
    printArray(arr, 26);
    if(isValid(arr, inputString.size())){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
