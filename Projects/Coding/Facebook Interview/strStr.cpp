#include<iostream>
#include<string>
using namespace std;


int strStr(string needle, string haystack){
    if(needle.size() == 0 || haystack.size() == 0){
        return -1;
    }
    bool found = 0;

    for(int i=0;i<haystack.size();i++){
        if(haystack.at(i) == needle.at(0)){
            found = 1;
            for(int j=0;j<needle.size();j++){
                if(haystack.at(i+j) != needle.at(j)){
                    found = 0;
                    break;
                }
            }
        }
        if(found){
            return i;
        }
    }

    return -1;
}

int main(){
    string needle;
    string haystack;
    cin>>haystack;
    cin>>needle;
    cout<<strStr(needle, haystack)<<endl;
    return 0;
}
