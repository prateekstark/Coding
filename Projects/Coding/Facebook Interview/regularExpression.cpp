#include<iostream>
#include<string>
using namespace std;


bool isMatch(string a, string b){
    if(a.size() == 0){
        if(b.size() == 0){
            return 1;
        }
    }
    if(a.compare(b) == 0){
        return 1;
    }
    if(a.size() == 1 && b.size() == 1){
        if(b.at(0) == '.'){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(a.size() >= 1 && b.size() >= 2){
        char c1 = b.at(0);
        char c2 = b.at(1);
        if(c1 != '.'){
            if(c2 != '*'){
                return isMatch(a.substr(1, a.size()), b.substr(1, b.size()));
            }
            else{
                int index = 0;
                bool flag = 0;
                while(!flag && index < a.size()){
                    if(c1 != a.at(index)){
                        flag = 1;
                        break;
                    }
                    index++;
                }
                return isMatch(a.substr(index, a.size()), b.substr(2, b.size()));
            }
        }
        else{
            if(c2 != '*'){
                return isMatch(a.substr(1, a.size()), b.substr(1, b.size()));
            }
            else{
                int index = 0;
                bool flag = 0;
                while(!flag && index < a.size()){
                    if(a.at(0) != a.at(index)){
                        flag = 1;
                        break;
                    }
                    index++;
                }
                return isMatch(a.substr(index, a.size()), b.substr(2, b.size()));
            }
        }
    }
    return 0;
}








int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<isMatch(a, b)<<endl;
    return 0;
}
