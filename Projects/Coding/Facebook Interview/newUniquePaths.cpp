#include<iostream>
#include<vector>
using namespace std;

int numWays(vector<vector<int> > grid, int x, int y){
    int i, j;
    if(x == 0 && y == 0){
        return 1;
    }
    else if(x == 0){
        if(grid.at(x).at(y-1) != 1){
            return numWays(grid, x, y-1);
        }
        else{
            return 0;
        }
    }
    else if(y == 0){
        if(grid.at(x-1).at(y) != 1){
            return numWays(grid, x-1, y);
        }
        else{
            return 0;
        }
    }
    else{
        if(grid.at(x-1).at(y) == 1 && grid.at(x).at(y-1) == 0){
            return numWays(grid, x, y-1);
        }
        else if(grid.at(x-1).at(y) == 0 && grid.at(x).at(y-1) == 1){
            return numWays(grid, x-1, y);
        }
    }
    return numWays(grid, x-1, y) + numWays(grid, x, y-1);
}

void printGrid(vector<vector<int> > grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(0).size();j++){
            cout<<grid.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int m, n;
    cin>>m;
    cin>>n;
    int i, j;
    int temp;
    vector<vector<int> > grid;
    for(i=0;i<m;i++){
        vector<int> tempVector;
        for(j=0;j<n;j++){
            cin>>temp;
            tempVector.push_back(temp);
        }
        grid.push_back(tempVector);
    }
    printGrid(grid);
    cout<<numWays(grid, m-1, n-1)<<endl;
    return 0;
}
