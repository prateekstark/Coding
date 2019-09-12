#include<iostream>
#include<string>
using namespace std;

string nextTerm(string presentTerm){
    int tempCount = 0;
    string answer = "";
    for(int i=0;i<presentTerm.size();i++){
        // cout<<"i am here"<<endl;
        tempCount++;
        if((i+1) < presentTerm.size()){
            if(presentTerm.at(i) != presentTerm.at(i+1)){
                answer = answer + to_string(tempCount) + presentTerm.at(i);
                tempCount = 0;
            }
        }
        else{
            answer = answer + to_string(tempCount) + presentTerm.at(i);
        }

    }
    return answer;
}


int main(){
    int n;
    cin>>n;
    string tempTerm = "1";
    while(n>1){
        tempTerm = nextTerm(tempTerm);
        n--;
    }
    cout<<tempTerm<<endl;
    return 0;
}
