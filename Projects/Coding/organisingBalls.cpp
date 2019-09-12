#include<iostream>
#include<vector>
using namespace std;

int sumRow(vector<vector<int> > myVector, int rowNum){
    int i;
    int tempSum = 0;
    for(i=0;i<myVector.size();i++){
        tempSum = tempSum + myVector.at(rowNum).at(i);
    }
    return tempSum;
}

int sumColumn(vector<vector<int> > arr, int columnNum){
    int i;
    int tempSum = 0;
    for(i=0;i<arr.size();i++){
        // cout<<arr.at(i).at(columnNum)<<endl;
        tempSum = tempSum + arr.at(i).at(columnNum);
    }
    return tempSum;
}

void printMatrix(vector<vector<int> > input){

}

int main(){
    int n;
    int i,j;
    int testcases;
    cin>>testcases;
    while(testcases>0){
        cin>>n;
        vector<vector<int> > myVector;
        int temp;
        for(i=0;i<n;i++){
            vector<int> tempVector;
            for(j=0;j<n;j++){
                cin>>temp;
                tempVector.push_back(temp);
            }
            myVector.push_back(tempVector);
        }
        int flag=0;
        for(i=0;i<n;i++){
            int t1 = sumColumn(myVector,i);
            int t2 = sumRow(myVector,i);
            if(t1!=t2){
                flag=1;
            }
        }
        if(flag==1){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<"Possible"<<endl;
        }
    testcases--;
    }
    return 0;
}