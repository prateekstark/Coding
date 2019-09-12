#include<iostream>
using namespace std;
int sumOfDigits(int n){
  int answer = 0;
  while(n>0){
    answer = answer + n%10;
    n = n/10;
  }
  return answer;
}
int main(){
  int testcases;
  cin>>testcases;
  while(testcases>0){
    int n, i=0;
    int index_of_N;
    int N;
    cin>>N;
    index_of_N = 0;
    int tempSum;
    int starter = 1;
    int tempLast;
    int tempRest, tempNum, tempSumLeft, tempS;
    // cout<<sumOfDigits(10);
    while(i<N){
      // cout<<"hello"<<endl;
      tempSum = sumOfDigits(starter);
      tempLast = starter%10;
      tempRest = starter/10;
      tempSumLeft = sumOfDigits(tempRest);
      tempS = tempSumLeft%10;
      if(tempS < 10 && tempRest!=0){
        i++;
        // starter = starter+10;
        tempNum = (tempRest*10) + (10-tempS);
      }
      starter = starter+10;

    }
    cout<<tempNum<<endl;
    testcases--;
  }
  return 0;
}
