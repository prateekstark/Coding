#include<iostream>
using namespace std;

class Node{
    int NodeID;
    Node* left;
    Node* right;
    Node(int n){
        this->NodeID = n;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
    Node* root;

    BinaryTree(Node* newRoot){
        this->root = newRoot;
    }
    vector<int> BFS(int graphSize){
        vector<Node*> sliding_queue;
        int arr[graphSize];
        sliding_queue.push_back(this->root);
        Node* tempNode;
        while(sliding_queue.size() != 0){
            tempNode = sliding_queue.at(0);
            if(tempNode->left != NULL){
                sliding_queue.push_back(tempNode->left);
            }

        }if(tempNode->right != NULL){
            sliding_queue.push_back(tempNode->right);
        }
    }

    void printTreeByLevel(){
        vector<Node*> nodeList;
        nodeList.push_back()
        if(this->root->left != NULL || this->root->right =! NULL){
            cout
        }

    }
};




int main(){





    return 0;
}
