#include<iostream>
#include<string>
using namespace std;
int maxInteger(string str){
    int result = 0;
    for(int i=0;i<str.size();i++){
        if((str.at(i) == '1') || (str.at(i) == '0') || result == 0 || result == 1){
            result = result + (str.at(i) - '0');
        }
        else{
            result = result*(str.at(i) - '0');
        }
    }
    return result;
}
int main(){
    string str;
    cin>>str;
    cout<<maxInteger(str)<<endl;
    return 0;
}
