#include<iostream>
using namespace std;




int main(){
    int n;
    cin>>n;
    int arr[n];
    int i, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int sc = 0;
    int e = 0;
    int max = 0;
    for(i=0;i<n-1;i++){
        if(i==e){
            sc++;
            e = max;
        }
    }
    cout<<sc<<endl;



    return 0;
}
