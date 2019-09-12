#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int label;
    vector<Node*> adjacencyList;
    Node(int n){
        this->label = n;
    }
};


class Graph{
public:
    Node* startNode;
    Graph(){
        this->startNode = new Node(0);
    }
    Graph(Node* newNode){
        this->startNode = newNode;
    }
    void joinNode(Node* node1, Node* node2){
        node1->adjacencyList.push_back(node2);
        node2->adjacencyList.push_back(node1);
    }
    Node* cloneGraph(){
        Node* myNode =
    }

}

























int main(){

}
