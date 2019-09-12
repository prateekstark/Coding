#include<iostream>
#include<string>
using namespace std;








string convertToRoman(int n){
    string answer = "";
    if(n/1000 != 0){
        answer = "M" + convertToRoman(n - 1000);
    }
    else if(n/500 != 0){
        answer = "D" + convertToRoman(n - 500);
    }
    else if(n/100 != 0){
        answer = "C" + convertToRoman(n - 100);
    }
    else if(n/50 != 0){
        answer = "L" + convertToRoman(n - 50);
    }
    else if(n/10 != 0){
        answer = "X" + convertToRoman(n - 10);
    }
    else if(n/5 != 0){
        answer = "V" + convertToRoman(n - 5);
    }
    else if(n/1 != 0){
        answer = "I" + convertToRoman(n - 1);
    }
    return answer;
}





int main(){
    int n;
    cin>>n;
    cout<<convertToRoman(n)<<endl;
    return 0;
}
