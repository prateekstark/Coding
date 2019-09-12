#include<iostream>
#include<string>
using namespace std;

int numWays(string code){
    if(code.size() == 1){
        return 1;
    }
    else if(code.size() == 2){
        if(stoi(code) > 26){
            return 1;
        }
        else{
            return 2;
        }
    }
    string bit1 = code.substr(0,1);
    string part1 = code.substr(1, code.size());
    string bit2 = code.substr(0, 2);
    string part2 = code.substr(2, code.size());
    if(stoi(bit2) <= 26){
        return numWays(part1) + numWays(part2);
    }
    return numWays(part1);
}

int main(){
    string code;
    cin>>code;
    cout<<numWays(code)<<endl;
    return 0;
}
