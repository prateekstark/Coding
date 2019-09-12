#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> computerAnswer(vector<string> charVector){
    int int1, int2, tempAnswer;
    int n = charVector.size();
    int temp;
    if(charVector.size() > 2){
        for(int i=0;i<n;i++){
            if(charVector.at(i) == "+"){
                int1 = stoi(charVector.at(i-2));
                int2 = stoi(charVector.at(i-1));
                tempAnswer = int1 + int2;
                charVector.at(i) = to_string(tempAnswer);
                charVector.erase(charVector.begin()+i-2, charVector.begin()+i);
                return computerAnswer(charVector);
            }

            else if(charVector.at(i) == "-"){
                int1 = stoi(charVector.at(i-2));
                int2 = stoi(charVector.at(i-1));
                tempAnswer = int1 - int2;
                charVector.at(i) = to_string(tempAnswer);
                charVector.erase(charVector.begin()+i-2, charVector.begin()+i);
                return computerAnswer(charVector);
            }

            else if(charVector.at(i) == "*"){
                int1 = stoi(charVector.at(i-2));
                int2 = stoi(charVector.at(i-1));
                tempAnswer = int1 * int2;
                charVector.at(i) = to_string(tempAnswer);
                charVector.erase(charVector.begin()+i-2, charVector.begin()+i);
                return computerAnswer(charVector);
            }

            else if(charVector.at(i) == "/"){
                int1 = stoi(charVector.at(i-2));
                int2 = stoi(charVector.at(i-1));
                tempAnswer = int1 / int2;
                charVector.at(i) = to_string(tempAnswer);
                charVector.erase(charVector.begin()+i-2, charVector.begin()+i);
                return computerAnswer(charVector);
            }
        }
    }
    return charVector;
}

int main(){
    int n;
    cin>>n;
    vector<string> charVector;
    string str;
    int i, j, k;
    for(i=0;i<n;i++){
        cin>>str;
        charVector.push_back(str);
    }
    cout<<computerAnswer(charVector).at(0)<<endl;
    return 0;
}
