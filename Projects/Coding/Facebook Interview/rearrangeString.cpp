#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

string insertChar(string inputString, char &inputChar){
    string outputString = "";
    int flag = 0;
    for(int i=0;i<inputString.size();i++){
        if(int(inputChar) < int(inputString.at(i))){
            outputString = outputString + inputChar;
            flag = 1;
        }
        outputString = outputString + inputString.at(i);
        if(i == (inputString.size() - 1) && flag == 0){
            outputString = outputString + inputChar;
        }
    }
    return outputString;
}

int main(){
    string inputString;
    string outputString = "";
    cin>>inputString;
    int x = 0;
    if(inputString.size() > 0){
        outputString = outputString + inputString.at(0);
    }
    else{
        cerr<<"Empty Input"<<endl;
    }
    int sum = 0;
    for(int i=1;i<inputString.size();i++){
        if(inputString.at(i) == '1' || inputString.at(i) == '2' || inputString.at(i) == '3' || inputString.at(i) == '4' || inputString.at(i) == '5' || inputString.at(i) == '6' || inputString.at(i) == '7' || inputString.at(i) == '8' || inputString.at(i) == '9' || inputString.at(i) == '0'){
            x = inputString[i] - '0';
            sum = x + sum;
        }
        else{
            outputString = insertChar(outputString, inputString.at(i));
        }
    }
    outputString = outputString + to_string(sum);
    cout<<outputString<<endl;
    return 0;
}
