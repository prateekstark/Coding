#include<iostream>
using namespace std;

int wayout(int N){
    if(N == 1){
        return 1;
    }
    if(N == 2){
        return 1;
    }
    if(N == 3){
        return 2;
    }
    if(N == 4){
        return 3;
    }
    if(N == 5){
        return 5;
    }
    return (wayout(N-1) + wayout(N-3) + wayout(N-5));
}


int main(){
    int N;
    cin>>N;
    cout<<wayout(N)<<endl;
    return 0;
}
