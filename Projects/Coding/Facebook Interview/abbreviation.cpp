#include<iostream>
#include<string>
using namespace std;

bool isUpperCase(char a){
    if(a - 'A' >= 0 && a - 'Z' <=0){
        return 1;
    }
    return 0;
}

char lowercase(char a){
    if(isUpperCase(a)){
        return (a - 'A' + 'a');
    }
    return a;
}

bool abbreviation(string a, string b){
    if(a.size() == 1 && b.size() == 1){
        if(a == b || a.at(0) == lowercase(b.at(0))){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(a.size() >= b.size()){
        char c1 = a.at(0);
        char c2 = b.at(0);
        string str1 = a.substr(1, a.size());
        string str2 = b.substr(1, b.size());
        if(c1 == c2 || c1 == lowercase(c2)){
            return abbreviation(str1, str2);
        }
        else{
            return abbreviation(str1, b);
        }
    }
    return 0;
}

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    if(abbreviation(a, b)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
