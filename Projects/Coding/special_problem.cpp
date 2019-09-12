#include<iostream>
#include<vector>
using namespace std;
bool isSpecialProblemPresent(vector<int> page, int index){
  int i;
  for(i=0;i<page.size();i++){
    if(page.at(i) == index){
      return true;
    }
  }
  return false;
}

int main(){
  int n,k;
  cin>>n>>k;
  // cout<<n<<" "<<k<<endl;
  vector<int> num_prob;
  int i, temp;
  for(i=0;i<n;i++){
    cin>>temp;
    num_prob.push_back(temp);
  }
  int temp_quest, num_quest, j, tempCount;
  vector<vector<int> > book;
  for(i=0;i<n;i++){
    temp_quest = 1;
    num_quest = num_prob.at(i);
    while(num_quest - k>0){
      tempCount = k;
      vector<int> pages;
      while(tempCount>0){
        pages.push_back(temp_quest);
        temp_quest++;
        tempCount--;
      }
      book.push_back(pages);
      num_quest = num_quest - k;
    }
    if(num_quest-k <= 0){
      tempCount = num_quest;
      vector<int> pages;
      while(tempCount>0){
        pages.push_back(temp_quest);
        temp_quest++;
        tempCount--;
      }
      book.push_back(pages);
    }
  }
  int specialProblems = 0;
  for(i=0;i<book.size();i++){
    if(isSpecialProblemPresent(book.at(i), (i+1))){
      specialProblems++;
    }
  }
  cout<<specialProblems<<endl;
  // for(i=0;i<book.size();i++){
  //   // for(j=0;j<book.at(i).size();j++){
  //   //   cout<<book.at(i).at(j)<<" ";
  //   // }
  //   cout<<book.at(i).size()<<endl;
  // }

  return 0;
}
