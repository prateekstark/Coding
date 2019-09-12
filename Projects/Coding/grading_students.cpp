#include<iostream>
using namespace std;
int roundOff(int marks){
  if(marks >= 38){
    if((marks)%5 >= 3){
      return ((marks/5)+1)*5;
    }
  }
  return marks;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  int i;
  for(i=0;i<n;i++){
    cin>>arr[i];
    arr[i] = roundOff(arr[i]);
    cout<<arr[i]<<endl;
  }
  return 0;
}
