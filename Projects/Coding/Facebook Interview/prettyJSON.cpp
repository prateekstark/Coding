#include<iostream>
#include<string>
using namespace std;



string giveIndent(int indentValue){
    string answer = "";
    for(int i=0;i<indentValue;i++){
        answer = answer + "\t";
    }
}



string makeJSONpretty(string inputString){
    string outputString = "";
    int indentValue = 0;
    for(int i=0;i<inputString.size();i++){
        if(inputString.at(i) == '{' || inputString.at(i) == '['){
            indentValue++;
            outputString = '\n' + "{" + '\n' + giveIndent(indentValue);
        }
        else if(inputString.at(i) == '}' || inputString.at(i) == ']'){
            indentValue--;
            outputString = '\n' + "{" + '\n' + giveIndent(indentValue);
        }
        else if(inputString.at(i) == ','){
            outputString = outputString + '\n' + giveIndent(indentValue);
        }
        else{
            outputString = outputString + inputString.at(i);
        }

    }
    return outputString;
}



int main(){
    string inputString;
    cin>>inputString;
    string outputString = makeJSONpretty(inputString);
    cout<<outputString<<endl;
    return 0;
}
