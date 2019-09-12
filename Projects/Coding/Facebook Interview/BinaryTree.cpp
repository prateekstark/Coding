#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int n){
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        this->root = new Node(0);
    }
    BinaryTree(Node* newRoot){
        this->root = newRoot;
    }
    Node* findNode(int n){
        if(root == NULL){
            return NULL;
        }
        if(root->data == n){
            return root;
        }
        BinaryTree* tempTree = new BinaryTree(root->left);
        if(tempTree->findNode(n) != NULL){
            return tempTree->findNode(n);
        }
        tempTree = new BinaryTree(root->right);
        if(tempTree->findNode(n) != NULL){
            return tempTree->findNode(n);
        }
        return NULL;
    }
    void insertNodeLeft(int parentNodeID, int childNodeID){
        Node* parentNode = findNode(parentNodeID);
        if(parentNode->left == NULL){
            Node* newNode = new Node(childNodeID);
            parentNode->left = newNode;
        }
        else{
            cerr<<"Node already present"<<endl;
        }
    }
    void insertNodeRight(int parentNodeID, int childNodeID){
        Node* parentNode = findNode(parentNodeID);
        if(parentNode->right == NULL){
            Node* newNode = new Node(childNodeID);
            parentNode->right = newNode;
        }
        else{
            cerr<<"Node already present"<<endl;
        }
    }
    void printInorderTraversal(){
        if(root == NULL){
            return;
        }
        BinaryTree* tempTree = new BinaryTree(root->left);
        tempTree->printInorderTraversal();
        cout<<root->data<<" ";
        tempTree = new BinaryTree(root->right);
        tempTree->printInorderTraversal();
    }

    void printPreOrderTraversal(){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        BinaryTree* tempTree = new BinaryTree(root->left);
        tempTree->printPreOrderTraversal();
        tempTree = new BinaryTree(root->right);
        tempTree->printPreOrderTraversal();
    }

    void postOrderTraversal(){
        if(root == NULL){
            return;
        }
        BinaryTree* tempTree = new BinaryTree(root->left);
        tempTree->postOrderTraversal();
        tempTree = new BinaryTree(root->right);
        tempTree->postOrderTraversal();
        cout<<root->data<<" ";
    }
    bool isMirror(Node* root1, Node* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        if(root1 != NULL && root2 != NULL){
            if(root1->data == root2->data){
                return (isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
            }
        }
        return false;
    }
    bool isTreeSymmetric(){
        if(root == NULL){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};


bool areTreeSame(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data == root2->data){
        return areTreeSame(root1->left, root2->left) && areTreeSame(root1->right, root2->right);
    }
    return false;
}


int main(){
    int n;
    BinaryTree* myTree = new BinaryTree();
    myTree->root->left = new Node(2);
    myTree->root->right = new Node(2);
    myTree->root->left->left = new Node(1);
    myTree->root->left->right = new Node(4);
    myTree->root->right->left = new Node(4);
    myTree->root->right->right = new Node(1);
    myTree->insertNodeLeft(2, 5);
    myTree->printInorderTraversal();
    cout<<endl<<myTree->isTreeSymmetric()<<endl;
    return 0;
}
