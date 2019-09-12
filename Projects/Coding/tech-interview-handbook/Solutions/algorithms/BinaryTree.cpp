#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int NodeID;
    Node* left;
    Node* right;
    Node* parent;
    Node(){
        NodeID = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(int n){
        NodeID = n;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    bool isLeaf(){
        if(left == NULL && right == NULL){
            return true;
        }
        return false;
    }

    void showChildren(){
        if(this->left != NULL){
            cout<<"left: "<<left->NodeID<<endl;
        }
        if(this->right != NULL){
            cout<<"right: "<<right->NodeID<<endl;
        }
    }

};

class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        root = new Node();
    }

    BinaryTree(Node* newRoot){
        root = newRoot;
    }

    bool isPresent(int n){
        BinaryTree* tempTree;
        if(root->NodeID != n){
            if(this->root->left != NULL){
                tempTree = new BinaryTree(this->root->left);
                if(tempTree->isPresent(n)){
                    return true;
                }
            }
            if(this->root->right != NULL){
                tempTree = new BinaryTree(this->root->right);
                if(tempTree->isPresent(n)){
                    return true;
                }
            }
            return false;
        }
        return true;
    }

    Node* findNode(int n){
        BinaryTree* tempTree;
        if(this->root->NodeID != n){
            if(this->root->left != NULL){
                tempTree = new BinaryTree(root->left);
                if(tempTree->findNode(n) != NULL){
                    return tempTree->findNode(n);
                }
            }
            if(this->root->right != NULL){
                tempTree = new BinaryTree(root->right);
                if(tempTree->findNode(n) != NULL){
                    return tempTree->findNode(n);
                }
            }
            return NULL;
        }
        return this->root;
    }

    void insertNodeLeft(int parentID, int newNodeID){
        Node* tempNode = findNode(parentID);
        if(tempNode->left == NULL){
            Node* newNode = new Node(newNodeID);
            tempNode->left = newNode;
            newNode->parent = tempNode;
        }
        else{
            cerr<<tempNode->NodeID<<" "<<"Left node not free"<<endl;
        }
    }

    void insertNodeRight(int parentID, int newNodeID){
        Node* tempNode = findNode(parentID);
        if(tempNode->right == NULL){
            Node* newNode = new Node(newNodeID);
            tempNode->right = newNode;
            newNode->parent = tempNode;
        }
        else{
            cerr<<tempNode->NodeID<<" "<<"Right node not free"<<endl;
        }
    }

    void printTreeByLevel(){
        vector<Node*> traverse;
        vector<int> level;
        int currentLevel;
        vector<int> particularLevel;
        Node* tempNode = root;
        traverse.push_back(tempNode);
        level.push_back(0);
        currentLevel = 1;
        cout<<"Level "<<level.at(0)<<": "<<tempNode->NodeID<<endl;
        while(traverse.size() != 0){
            tempNode = *traverse.begin();
            currentLevel = level.at(0);
            if(tempNode->left != NULL){
                traverse.push_back(tempNode->left);
                level.push_back(currentLevel+1);
                particularLevel.push_back(tempNode->left->NodeID);
            }
            if(tempNode->right != NULL){
                traverse.push_back(tempNode->right);
                level.push_back(currentLevel+1);
                particularLevel.push_back(tempNode->right->NodeID);
            }
            traverse.erase(traverse.begin());
            level.erase(level.begin());
            if(level.size() > 0){
                if(currentLevel != level.at(0)){
                    cout<<endl;
                    cout<<"Level "<<level.at(0)<<": ";
                    printVector(particularLevel);
                    while(particularLevel.size() != 0){
                        particularLevel.pop_back();
                    }
                }
            }
        }

    }
};

void printVector(vector<int> myVector){
    for(int i=0;i<myVector.size();i++){
        cout<<myVector.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    BinaryTree* myTree = new BinaryTree();
    myTree->insertNodeLeft(0,1);
    myTree->insertNodeRight(0,2);
    myTree->insertNodeLeft(1,3);
    myTree->insertNodeRight(1,4);
    myTree->insertNodeLeft(2,5);
    myTree->insertNodeRight(2,6);
    myTree->printTreeByLevel();
    return 0;
}
