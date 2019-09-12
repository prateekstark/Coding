#include<iostream>
using namespace std;

int findKth(vector<int> input, int k){
    if(k>input.size() && k < 1){
        return -1;
    }
    if(input.size() == 1){
        return input.at(0);
    }

    int selectedValue = input.at(0);
    vector<int> S, B;
    for(int i=1;i<input.size();i++){
        if(input.at(i) <= selectedValue){
            S.push_back(input.at(i));
        }
        else{
            B.push_back(input.at(i));
        }
    }
    if(S.size() < K - 1){
        return findKth(B, k-S.size()-1);
    }
    if(S.size() >= K){
        return findKth(S, k);
    }
    return selectedValue;
}



int main(){
    int n;
    vector<int> input;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        input.push_back(temp);
    }
    cout<<findKth(input, k);
    return 0;
}
