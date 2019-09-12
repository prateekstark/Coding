#include<iostream>
#include<vector>
using namespace std;
bool isPresent(vector<int> unique, int n){
  int i;
  for(i=0;i<unique.size();i++){
    if(n==unique.at(i)){
      return true;
    }
  }
  return false;
}
int main(){
  int n,i,j;
  cin>>n;
  int arr[n];

  vector<int> unique;
  for(i=0;i<n;i++){
    cin>>arr[i];
    if(!isPresent(unique,arr[i])){
      unique.push_back(arr[i]);
    }
  }
  // for(i=0;i<unique.size();i++){
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  int count = 0;
  vector<int> temp_vector;
  // int arr_temp[unique.size()];
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(arr[j] == arr[i] && arr[j] != -1){
        count++;
        arr[j] = -1;
        arr[i] = -1;
        break;
      }
    }
  }
  cout<<count<<endl;

}
