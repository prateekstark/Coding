#include<iostream>
using namespace std;
class Node{
public:
    char data;
    Node* left, right;
    Node(char n){
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};



class BinaryTree{
public:
    Node* root;
    BinaryTree(char c){
        root = new Node(c);
    }
    BinaryTree(Node* newRoot){
        this->root = newRoot;
    }
    Node* findNode(char c){
        if(root->data == c){
            return root;
        }
        else if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        if(root->left != NULL){
            BinaryTree* newTree = new BinaryTree(this->left);
            return newTree->findNode(c);
        }
        BinaryTree* newTree = new BinaryTree(this->right);
        return newTree->findNode(c);
    }
    void* insertNodeLeft(char parentID, char newNodeID){
        Node* newParentNode = this->findNode(parentID);
        if(newParentNode == NULL){
            cerr<<"Parent does not exist"<<endl;
            return;
        }
        Node* newNode = new Node(newNodeID);
        newParentNode->left = newNode;
        return;
    }
    void* insertNodeRight(char parentID, char newNodeID){
        Node* newParentNode = this->findNode(parentID);
        if(newParentNode == NULL){
            cerr<<"Parent does not exist"<<endl;
            return;
        }
        Node* newNode = new Node(newNodeID);
        newParentNode->right = newNode;
        return;
    }
};



int main(){

}
