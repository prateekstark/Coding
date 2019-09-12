#include<iostream>
#include<vector>
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

    void levelTraversal(){
        vector<Node*> sliding_queue;
        sliding_queue.push_back(this->root);
        vector<int> level;
        level.push_back(0);
        Node* tempNode;
        int tempLevel;
        int presentLevel = 0;
        while(sliding_queue.size() != 0){
            tempNode = sliding_queue.at(sliding_queue.size() - 1);
            tempLevel = level.at(level.size() - 1);
            if(tempNode->left != NULL){
                sliding_queue.insert(sliding_queue.begin(), tempNode->left);
                level.insert(level.begin(), tempLevel + 1);
            }
            if(tempNode->right != NULL){
                sliding_queue.insert(sliding_queue.begin(), tempNode->right);
                level.insert(level.begin(), tempLevel + 1);
            }
            cout<<tempNode->data<<" ";
            sliding_queue.pop_back();
            level.pop_back();
            if(level.size() != 0){    
                if(presentLevel != level.at(level.size() - 1)){
                    presentLevel = level.at(level.size() - 1);
                    cout<<endl;
                }
            }
        }
    }
};



int main(){
    BinaryTree* myTree = new BinaryTree();
    myTree->root->data = 3;
    Node* node1 = new Node(9);
    Node* node2 = new Node(20);
    Node* node3 = new Node(15);
    Node* node4 = new Node(7);
    myTree->root->left = node1;
    myTree->root->right = node2;
    myTree->root->right->left = node3;
    myTree->root->right->right = node4;
    myTree->levelTraversal();
    return 0;
}
