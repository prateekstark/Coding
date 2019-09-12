#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int NodeID;
    Node* left;
    Node* right;
    Node(int n){
        this->left = NULL;
        this->right = NULL;
        this->NodeID = n;
    }
};

class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        this->root = new Node(1);
    }
    BinaryTree(Node* newRoot){
        this->root = newRoot;
    }
    Node* findNode(int nodeID){
        if(root->NodeID == nodeID){
            return root;
        }
        BinaryTree* tempTree = new BinaryTree(root->left);
        if(tempTree->findNode(nodeID) != NULL){
            return tempTree->findNode(nodeID);
        }
        tempTree = new BinaryTree(root->right);
        if(tempTree->findNode(nodeID) != NULL){
            return tempTree->findNode(nodeID);
        }
        return NULL;
    }

    void insertNodeLeft(int newNodeID, int parentID){
        Node* parentNode = this->findNode(parentID);
        if(parentNode->left == NULL){
            Node* newNode = new Node(newNodeID);
            parentNode->left = newNode;
        }
        else{
            cerr<<"Left Node busy!"<<endl;
        }
    }
    void insertNodeRight(int newNodeID, int parentID){
        Node* parentNode = this->findNode(parentID);
        if(parentNode->right == NULL){
            Node* newNode = new Node(newNodeID);
            parentNode->right = newNode;
        }
        else{
            cerr<<"Right Node busy!"<<endl;
        }
    }

    int findMinDepth(){
        if(this->root->left == NULL || this->root->right == NULL){
            return 0;
        }
        else if(this->root->left == NULL && this->root->right != NULL){
            BinaryTree* tempTreeRight = new BinaryTree(this->root->right);
            return (tempTreeRight->findMinDepth() + 1);
        }
        else(this->root->right != NULL && this->root->right == NULL){
            BinaryTree* tempTreeLeft = new BinaryTree(this->root->left);
            return (tempTreeLeft->findMinDepth() + 1);
        }
        BinaryTree* tempTreeLeft = new BinaryTree(this->root->left);
        BinaryTree* tempTreeRight = new BinaryTree(this->root->right);
        return min((tempTreeLeft->findMinDepth()) + 1, (tempTreeRight->findMinDepth()) + 1);
    }
};

int main(){
    BinaryTree* myTree = new BinaryTree();
    myTree->insertNodeLeft(2, 1);
    myTree->insertNodeRight(3, 1);
    myTree->insertNodeLeft(4, 2);
    myTree->insertNodeRight(5, 2);
    cout<<(myTree->findMinDepth()) + 1<<endl;
    return 0;
}
