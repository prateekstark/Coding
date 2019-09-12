#include<iostream>
#include<vector>
using namespace std;

int findMinimum(vector<int> v, int n, int m){
    int min, i;
    min = v.at(n);
    for(i=n;i<=m;i++){
        if(min > v.at(i)){
            min = v.at(i);
        }
    }
    return min;
}


int main(){
    int n;
    cin>>n;
    int i, j, temp;
    vector<int> histogram;
    for(i=0;i<n;i++){
        cin>>temp;
        histogram.push_back(temp);
    }
    int max = 0;
    int tempMin;
    int tempArea;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            tempArea = findMinimum(histogram, j, j+i)*(i+1);
            if(max < tempArea){
                max = tempArea;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
