#include<iostream>
#include<string>
using namespace std;
int convertToDecimal(string romanString){
    int answer = 0;
    for(int i=0;i<romanString.size();i++){
        if(romanString.at(i) == 'M'){
            answer = answer + 1000;
        }
        if(romanString.at(i) == 'D'){
            answer = answer + 500;
        }
        if(romanString.at(i) == 'C'){
            answer = answer + 100;
        }
        if(romanString.at(i) == 'L'){
            answer = answer + 50;
        }
        if(romanString.at(i) == 'X'){
            answer = answer + 10;
        }
        if(romanString.at(i) == 'V'){
            answer = answer + 5;
        }
        if(romanString.at(i) == 'I'){
            answer = answer + 1;
        }
    }
    return answer;
}
int main(){
    string romanString;
    cin>>romanString;
    cout<<convertToDecimal(romanString)<<endl;
}
