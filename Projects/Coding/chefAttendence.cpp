#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
  int testcases;
  cin>>testcases;
  while(testcases>0){


    int D;
    cin>>D;
    string actualAttendence;
    cin>>actualAttendence;
    char present = 'P';
    char absent = 'A';
    int num_attendence = 0;
    int i;
    // cout<<actualAttendence<<endl;
    // return 0;
    if(actualAttendence.size()>0 && actualAttendence.at(0) == present){
      num_attendence++;
    }
    if(actualAttendence.size()>1 && actualAttendence.at(1) == present){
      num_attendence++;
    }
    if(actualAttendence.size()>(D-1) && actualAttendence.at(D-1) == present){
      num_attendence++;
    }
    if(actualAttendence.size()>(D-2) && actualAttendence.at(D-2) == present){
      num_attendence++;
    }
    for(i=2;i<D-2;i++){
      if(actualAttendence.at(i-2) == present || actualAttendence.at(i-1) == present || actualAttendence.at(i+2) == present || actualAttendence.at(i+1) == present || actualAttendence.at(i) == present){
        num_attendence++;
      }
    }
    // cout<<num_attendence<<endl;
    // cout<<D<<endl;
    float percentage;
    percentage = (float)num_attendence/(float)D;
    // cout<<percentage<<endl;
    if(percentage>=0.75){
      cout<<"1"<<endl;
    }
    else{
      cout<<"-1"<<endl;
    }
    testcases--;
  }
}
