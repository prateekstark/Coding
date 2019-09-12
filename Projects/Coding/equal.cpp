#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int> myVector){
    int i, temp;
    temp = myVector.at(0);
    for(i=0;i<myVector.size();i++){
        if(temp<myVector.at(i)){
            temp = myVector.at(i);
        }
    }
    return temp;
}

vector<int> removeMax(vector<int> inp, int temp){
    int i;
    // temp;
    vector<int> tempResult;
    int flag = 0;
    for(i=0;i<inp.size();i++){
        if(temp == inp.at(i) && flag==0){
            flag = 1;
            continue;
        }
        tempResult.push_back(inp.at(i));
    }
    return tempResult;
}

void printVector(vector<int> myVector){
    for(int i=0;i<myVector.size();i++){
        cout<<myVector.at(i)<<" ";
    }
}


vector<int> executeLastCondition(vector<int> inp, int max){
    int val = inp.at(0);
    int diff = max - val;
    if(diff > 0){    
        if(diff == 5){
            vector<int> tempVector;
            for(int i = 0; i < inp.size(); i++){
                tempVector.push_back((inp.at(i))+5);
            }
            tempVector.push_back(max);
            return tempVector;
        }
        else if(diff > 5){
            vector<int> tempVector;
            for(int i = 0; i < inp.size(); i++){
                tempVector.push_back((inp.at(i))+5);
            }
            return executeLastCondition(tempVector, max);
        }
        else{
            if(diff == 4){
                vector<int> tempVector;
                for(int i = 0; i < inp.size(); i++){
                    tempVector.push_back((inp.at(i))+4);
                }
                tempVector.push_back(max);
                return tempVector;
            }
            if(diff == 3){
                vector<int> tempVector;
                for(int i = 0; i < inp.size(); i++){
                    tempVector.push_back((inp.at(i))+3);
                }
                tempVector.push_back(max);
                return tempVector;
            }
            if(diff == 2){
                vector<int> tempVector;
                for(int i = 0; i < inp.size(); i++){
                    tempVector.push_back((inp.at(i))+2);
                }
                tempVector.push_back(max);
                return tempVector;
            }
            if(diff == 1){
                vector<int> tempVector;
                for(int i = 0; i < inp.size(); i++){
                    tempVector.push_back((inp.at(i))+1);
                }
                tempVector.push_back(max);
                return tempVector;
            }
        }
    }
    vector<int> tempVector = inp;
    tempVector.push_back(max);
    return tempVector;
}


vector<int> finalConditionRun(vector<int> input){
    int tempMax = findMax(input);
    vector<int> tempVector = removeMax(input, tempMax);
    return executeLastCondition(tempVector, tempMax);
}










vector<int> getCorrectedVector(vector<int> inp){

}







int main(){
    int testcases, t, n, i, j;
    // cin>>testcases;
    // while(testcases>0){   
    cin>>n;
    vector<int> myVector;
    int temp;

    for(i=0;i<n;i++){
        cin>>temp;
        myVector.push_back(temp);
    }
    // printVector(myVector);
    // return 0;
    vector<int> resultVector = finalConditionRun(myVector);
    printVector(resultVector);



    // testcases--;
    // }
    return 0;
}
//finished the input part...