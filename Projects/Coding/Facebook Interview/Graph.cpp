#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int nodeID;
    vector<Node*> adjacencyList;
    Node(int n){
        this->nodeID = n;
    }
};

class Graph{
public:
    Node* startNode;
    int graphSize;

    Graph(){
        startNode = new Node(0);
        graphSize = 1;
    }

    Node* findNodeByBFS(int myNodeID){
        if(startNode->nodeID == myNodeID){
            return startNode;
        }
        vector<Node*> sliding_queue;
        sliding_queue.push_back(startNode);
        Node* tempNode;
        bool color[graphSize] = {0};
        while(sliding_queue.size() != 0){
            tempNode = sliding_queue.at(sliding_queue.size() - 1);
            for(int i=0;i<tempNode->adjacencyList.size();i++){
                if(!color[tempNode->adjacencyList.at(i)->nodeID]){
                    if(tempNode->adjacencyList.at(i)->nodeID == myNodeID){
                        return tempNode->adjacencyList.at(i);
                    }
                    sliding_queue.insert(sliding_queue.begin(), tempNode->adjacencyList.at(i));
                    color[tempNode->adjacencyList.at(i)->nodeID] = 1;
                }
            }
            sliding_queue.pop_back();
        }
        return NULL;
    }
    Node* findNodeByDFS(int myNodeID){
        if(startNode->nodeID = myNodeID){
            return startNode;
        }
        vector<Node*> dfs_stack;
        dfs_stack.push_back(startNode);
        Node* tempNode;
        bool color[graphSize] = {0};
        bool flag = 0;
        color[startNode->nodeID] = 1;
        while(dfs_stack.size() != 0){
            flag = 0;
            tempNode = dfs_stack.at(dfs_stack.size() - 1);
            for(int i=0;i<tempNode->adjacencyList.size();i++){
                if(!color[tempNode->adjacencyList.at(i)->nodeID]){
                    if(tempNode->adjacencyList.at(i)->nodeID == myNodeID){
                        return tempNode->adjacencyList.at(i);
                    }
                    dfs_stack.push_back(tempNode->adjacencyList.at(i));
                    color[tempNode->adjacencyList.at(i)->nodeID] = 1;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                dfs_stack.pop_back();
            }
        }
    }

    void addEdge(int a, int b){
        Node* first_node = findNodeByDFS(a);
        Node* second_node = findNodeByDFS(b);
        if(second_node == NULL){
            second_node = new Node(b);
            graphSize++;
        }
        if(first_node == NULL){
            first_node = new Node(a);
            graphSize++;
        }
        first_node->adjacencyList.push_back(second_node);
        second_node->adjacencyList.push_back(first_node);
    }

    void BFSTraversal(){
        vector<Node*> sliding_queue;
        vector<int> level;
        sliding_queue.push_back(startNode);
        level.push_back(0);
        Node* tempNode;
        int presentLevel = 0;
        bool color[graphSize] = {0};
        while(sliding_queue.size() != 0){
            tempNode = sliding_queue.at(sliding_queue.size() - 1);
            for(int i=0;i<tempNode->adjacencyList.size();i++){
                if(!color[tempNode->adjacencyList.at(i)->nodeID]){
                    sliding_queue.insert(sliding_queue.begin(), tempNode->adjacencyList.at(i));
                    level.insert(level.begin(), presentLevel + 1);
                    color[tempNode->adjacencyList.at(i)->nodeID] = 1;
                }
            }
            sliding_queue.pop_back();
            level.pop_back();
            cout<<tempNode->nodeID<<" ";
            if(level.size() != 0){
                if(presentLevel != level.at(level.size() - 1)){
                    presentLevel = level.at(level.size() - 1);
                }
            }
        }
        cout<<endl;
    }

    void DFSTraversal(){
        vector<Node*> dfs_stack;
        dfs_stack.push_back(startNode);
        int color[graphSize] = {0};
        Node* tempNode;
        bool flag = 0;
        color[0] = 1;
        while(dfs_stack.size() != 0){
            tempNode = dfs_stack.at(dfs_stack.size() - 1);
            cout<<tempNode->nodeID<<" ";
            flag = 0;
            for(int i=0;i<tempNode->adjacencyList.size();i++){
                if(color[tempNode->adjacencyList.at(i)->nodeID] == 0){
                    dfs_stack.push_back(tempNode->adjacencyList.at(i));
                    color[tempNode->adjacencyList.at(i)->nodeID] = 1;
                    flag = 1;
                }
            }
            if(!flag){
                dfs_stack.pop_back();
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph* myGraph = new Graph();
    myGraph->addEdge(0, 1);
    myGraph->addEdge(1, 2);
    myGraph->addEdge(0, 2);
    myGraph->addEdge(1, 3);
    myGraph->addEdge(3, 4);
    myGraph->addEdge(5, 1);
    myGraph->addEdge(6, 2);
    myGraph->addEdge(9, 7);
    myGraph->addEdge(6, 7);
    myGraph->addEdge(9, 3);
    myGraph->addEdge(8, 1);
    myGraph->addEdge(10, 0);
    myGraph->BFSTraversal();
    myGraph->DFSTraversal();
    return 0;
}
