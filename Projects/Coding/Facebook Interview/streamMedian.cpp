#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
public:
    vector<int> myQueue;
    int searchLessThanOrEqual(int low, int high, int key){
        if(high - low > 1){
            int mid = low + ((high-low)/2);
            if(this->myQueue.at(mid) > key){
                return searchLessThanOrEqual(low, mid, key);
            }
            else{
                return searchLessThanOrEqual(mid, high, key);
            }
        }
        if(high - low == 1){
            if(this->myQueue.at(high) > key){
                return low+1;
            }
        }
        return high+1;
    }
    void insertElement(int n){
        int index;
        if(myQueue.size() > 1){
            if(n < myQueue.at(0)){
                myQueue.insert(myQueue.begin(), n);
            }
            else if(n >= myQueue.at(myQueue.size() - 1)){
                myQueue.push_back(n);
            }
            else{
                index = searchLessThanOrEqual(0, this->myQueue.size() - 1, n);
                this->myQueue.insert(this->myQueue.begin() + index, n);
            }
        }
        else if(myQueue.size() == 0){
            myQueue.push_back(n);
        }
        else{
            if(n > myQueue.at(0)){
                myQueue.push_back(n);
            }
            else{
            myQueue.insert(myQueue.begin(), n);
            }
        }
        // printVector();
        // cout<<index<<endl;

    }
    int getMedian(){
        int size = this->myQueue.size();
        if(size%2 == 1){
            return this->myQueue.at((size - 1)/2);
        }
        return (this->myQueue.at(size/2) + this->myQueue.at((size/2)-1))/2;
    }
    void printVector(){
        for(int i=0;i<this->myQueue.size();i++){
            cout<<myQueue.at(i)<<" ";
        }
        cout<<endl;
    }
};

int main(){
    PriorityQueue* myList = new PriorityQueue();
    int n;
    cin>>n;
    int temp;
    int i;
    for(i=0;i<n;i++){
        cin>>temp;
        myList->insertElement(temp);
        // myList->printVector();
        cout<<myList->getMedian()<<endl;

    }
    return 0;
}
