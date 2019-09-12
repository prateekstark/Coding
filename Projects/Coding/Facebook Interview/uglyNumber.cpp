#include<iostream>
#include<algorithm>
using namespace std;
int uglyNumber(int n){
    int arr[n];
    arr[0] = 1;
    int index2 = 0;
    int index3 = 0;
    int index5 = 0;
    int factor2 = 2;
    int factor3 = 3;
    int factor5 = 5;
    for(int i=1;i<n;i++){
        arr[i] = min(factor2, min(factor5, factor3));
        if(factor2 == arr[i]){
            index2++;
            factor2 = 2*arr[index2];
        }
        if(factor3 == arr[i]){
            index3++;
            factor3 = 3*arr[index3];
        }
        if(factor5 == arr[i]){
            index5++;
            factor5 = 5*arr[index5];
        }
    }
    return arr[n-1];
}
int main(){
    int n;
    cin>>n;
    cout<<uglyNumber(n)<<endl;
    return 0;
}
