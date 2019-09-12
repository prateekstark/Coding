#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int findMinIndex(vector<int> v){
    int index = 0;
    for(int i=0;i<v.size();i++){
        if(v[index] > v[i]){
            index = i;
        }
    }
    return index;
}

int findSecondMinIndex(vector<int> v){
    vector<int> tempVector(v);
    int minIndex2 = findMinIndex(v);
    tempVector.erase(tempVector.begin() + minIndex2);
    int minIndex1 = findMinIndex(tempVector);
    if(minIndex1 < minIndex2){
        return minIndex1;
    }
    return (minIndex1 + 1);
}

int findFullCost(vector<vector<int> > cost, vector<int> indexVector){
    int answer = 0;
    for(int i=0;i<indexVector.size();i++){
        answer = answer + cost[i][indexVector[i]];
    }
    return answer;
}

int foo(vector<vector<int> > a, int index){
    if(a.size() == 0){
        // a[0][findMinIndex(a[0])];
        return 0;
    }
    return a[(a.size()-1)][index] + min(foo(a.erase(a.end()), (index+1)%3), foo(a.erase(a.end()), (index+2)%3));
}

int minPrice(vector<vector<int>> cost){
    int numBlocks = cost.size();
    // int tempIndex1 = findMinIndex(cost[0]);
    // int tempIndex2;
    // vector<int> indexVector;
    // indexVector.push_back(tempIndex1);
    // for(int i=1;i<numBlocks;i++){
    //     // tempCost = tempCost + findcost.at(i)
    //     tempIndex2 = findMinIndex(cost[i]);
    //     if(tempIndex1 != tempIndex2){
    //         indexVector.push_back(tempIndex2);
    //         tempIndex1 = tempIndex2;
    //     }
    //     else{
    //         indexVector.push_back(findSecondMinIndex(cost[i]));
    //     }
    // }
    // int a1 = findFullCost(cost, indexVector);
    // indexVector.clear();
    // tempIndex1 = findSecondMinIndex(cost[0]);
    // indexVector.push_back(tempIndex1);
    // for(int i=1;i<numBlocks;i++){
    //     tempIndex2 = findMinIndex(cost[i]);
    //     if(tempIndex1 != tempIndex2){
    //         indexVector.push_back(tempIndex2);
    //         tempIndex1 = tempIndex2;
    //     }
    //     else{
    //         indexVector.push_back(findSecondMinIndex(cost[i]));
    //     }
    // }
    // int a2 = findFullCost(cost, indexVector);
    // return min(a1, a2);

}

int main()
