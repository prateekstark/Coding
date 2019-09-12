#include<iostream>
#include<list>
#include<vector>
using namespace std;


class Node{
public:
    int nodeID;
    vector<Node*> children;

    Node(int n){
        nodeID = n;
    }

    bool isChild(int n){
        int i;
        for(i=0;i<this->children.size();i++){
            if(this->children.at(i)->nodeID == n){
                return true;
            }
        }
        return false;
    }

    void showChildren(){
        for(int i=0;i<this->children.size();i++){
            cout<<this->children.at(i)->nodeID<<" ";
        }
        cout<<endl;
    }

    void insertChild(int n){
        Node* newNode = new Node(n);
        if(this->isChild(n)){
            cerr<<"Child already exists!"<<endl;
        }
        else{
            this->children.push_back(newNode);
        }
    }

};

class tree{
public:
    Node* root;

    tree(){
        root = new Node(0);
    }

    tree(Node* newRoot){
        this->root = newRoot;
    }

    bool isPresent(int n){
        if(root->nodeID != n){
            for(int i=0;i<root->children.size();i++){
                tree* tempTree = new tree(root->children.at(i));
                if(tempTree->isPresent(n)){
                    return true;
                }
            }
            return false;
        }
        return true;
    }

    Node* findNode(int n){
        if(root->nodeID != n){
            for(int i=0;i<root->children.size();i++){
                tree* tempTree = new tree(root->children.at(i));
                if(tempTree->findNode(n) != NULL){
                    return tempTree->root;
                }
                return NULL;
            }
        }
        return root;
    }

    void insertNode(int parentID, int childID){
        Node* parentNode = findNode(parentID);
        if(!this->isPresent(childID)){
            if(parentNode != NULL){
                parentNode->insertChild(childID);
            }
            else{
                cerr<<"Parent not present"<<endl;
            }
        }
        else{
            cerr<<"Node already present"<<endl;
        }
    }

    int getHeight(){
        Node* tempNode = root;
        int height;
        if(tempNode->children.size() == 0){
            height = 0;
        }

        else{
            tree* tempTree = new tree(tempNode->children.at(0));
            int max = tempTree->getHeight();
            for(int i=1;i<tempNode->children.size();i++){
                tempTree = new tree(tempNode->children.at(i));
                if(max<tempTree->getHeight()){
                    max = tempTree->getHeight();
                }
            }
            height = max+1;
        }
        return height;
    }


};





int main(){
    tree* myTree = new tree();
    myTree->insertNode(0,1);
    myTree->insertNode(0,2);
    myTree->insertNode(1,3);
    myTree->insertNode(1,2);

    cout<<myTree->getHeight()<<endl;
    return 0;
}
