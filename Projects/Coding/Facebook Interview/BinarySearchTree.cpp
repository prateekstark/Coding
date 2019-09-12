#include<iostream>

using namespace std;
class Node{
public:
    int nodeID;
    int nodeData;
    Node(int nodeID, int nodeData){
        this->nodeID = nodeID;
        this->nodeData = nodeData;
    }
};

class BinarySearchTree{
public:
    Node* root;
    BinarySearchTree(){
        root = new Node(0, 0);
    }
    BinarySearchTree(Node* newRoot){
        this->root = newRoot;
    }
    Node* findNode(int nodeData){
        if(root->nodeData == nodeData){
            return root;
        }
        if(root == NULL){
            return NULL;
        }
        BinarySearchTree* tempTree = new BinarySearchTree(root->left);
        if(tempTree->findNode(nodeData) != NULL){
            return tempTree->findNode(nodeData);
        }
        tempTree new BinarySearchTree(root->right);
        return tempTree->findNode(nodeData);
    }
}



int main(){


    return 0;
}
