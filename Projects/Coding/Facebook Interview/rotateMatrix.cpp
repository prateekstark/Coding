#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int> > matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int> > rotateMatrix(vector<vector<int> > matrix){
    vector<vector<int> > rotatedMatrix;
    for(int i=0;i<matrix.size();i++){
        vector<int> tempVector;
        for(int j=0;j<matrix.size();j++){
            tempVector.insert(tempVector.begin(), matrix.at(j).at(i));
        }
        rotatedMatrix.push_back(tempVector);
    }
    return rotatedMatrix;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > matrix;
    int i,j;
    int temp;
    for(i=0;i<n;i++){
        vector<int> tempVector;
        for(j=0;j<n;j++){
            cin>>temp;
            tempVector.push_back(temp);
        }
        matrix.push_back(tempVector);
    }
    printMatrix(rotateMatrix(matrix));
}
