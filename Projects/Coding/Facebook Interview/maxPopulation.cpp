#include<iostream>
using namespace std;

int finMin(int arr[], int n){
    int i, min = arr[0];
    for(i=0;i<n;i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}
int findMax(int arr[], int n){
    int i, max = arr[0];
    for(i=0;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    cin>>n;
    int birthYear[n], deathYear[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>birthYear[i];
    }
    for(i=0;i<n;i++){
        cin>>deathYear[i];
    }
    int minBirth = finMin(birthYear, n);
    int minDeath = finMin(deathYear, n);
    int maxDeath = finMin(deathYear, n);
    int arr[maxDeath-minBirth] = {};
    for(i=0;i<n;i++){
        for(j=0;j<deathYear[i]-birthYear[i];i++){
            arr[birthYear[i]-minBirth+j]++;
        }
    }
    int tempMax = arr[0], tempCount;
    for(i=0;i<n;i++){
        if(arr[i] > tempMax){
            tempMax = arr[i];
            tempCount = i;
        }
    }
    int maxYear = tempCount + minBirth;
    cout<<maxYear<<endl;
    return 0;
}
