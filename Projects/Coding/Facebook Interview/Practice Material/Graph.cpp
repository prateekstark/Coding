#include<iostream>
#include<map>
#include<vector>
using namespace std;





class Vertex{
public:
    int vertexID;
    vector<Vertex*> adjacencyList;
    Vertex(int n){
        this->vertexID = n;
    }
};

class Graph{
public:
    map<int, Vertex*> node;
    int numElements;
    Graph(int n){
        this->numElements = n;
        for(int i=0;i<n;i++){
            Vertex* v = new Vertex(i);
            node[i] = v;
        }
    }
    void insertEdge(int a, int b){
        Vertex* first_node = node.find(a)->second;
        Vertex* second_node = node.find(b)->second;
        int i, j;
        first_node->adjacencyList.push_back(second_node);
        second_node->adjacencyList.push_back(first_node);
    }

    void printLevelGraph(int startNodeID){
        Vertex* startNode = node.find(startNodeID)->second;
        vector<Vertex*> sliding_queue;
        vector<int> level;
        sliding_queue.push_back(startNode);
        level.push_back(0);
        bool color[this->numElements];
        int i, j;
        for(i=0;i<this->numElements;i++){
            color[i] = 0;
        }
        int presentLevel = 0;
        color[startNodeID] = 1;
        while(sliding_queue.size() != 0){
            Vertex* tempVertex = sliding_queue.at(sliding_queue.size() - 1);
            for(i=0;i<tempVertex->adjacencyList.size();i++){
                if(color[tempVertex->adjacencyList.at(i)->vertexID] == 0){
                    sliding_queue.insert(sliding_queue.begin(), tempVertex->adjacencyList.at(i));
                    level.insert(level.begin(), presentLevel+1);
                    color[tempVertex->adjacencyList.at(i)->vertexID] = 1;
                }
            }
            sliding_queue.pop_back();
            level.pop_back();
            cout<<tempVertex->vertexID<<" ";
            if(level.size() != 0){
                if(presentLevel != level.at(level.size() - 1)){
                    cout<<endl;
                    presentLevel = level.at(level.size() - 1);
                }
            }
        }
    }
    Vertex* farthestVertex(int startNodeID){
        Vertex* startNode = node.find(startNodeID)->second;
        vector<Vertex*> sliding_queue;
        bool color[this->numElements] = {0};
        sliding_queue.push_back(startNode);
        color[startNodeID] = 1;

        Vertex* tempVertex;
        while(sliding_queue.size() != 0){
            tempVertex = sliding_queue.at(sliding_queue.size() - 1);
            for(int i=0;i<tempVertex->adjacencyList.size();i++){
                if(color[tempVertex->adjacencyList.at(i)->vertexID] == 0){
                    sliding_queue.insert(sliding_queue.begin(), tempVertex->adjacencyList.at(i));
                    color[tempVertex->adjacencyList.at(i)->vertexID] = 1;
                }
            }
            sliding_queue.pop_back();
        }
        return tempVertex;
    }
    int graphDiameter(int startNodeID){
        Vertex* startNode = node.find(startNodeID)->second;
        Vertex* localFarNode = farthestVertex(startNodeID);
        vector<Vertex*> sliding_queue;
        vector<int> level;
        bool color[this->numElements] = {0};
        sliding_queue.push_back(localFarNode);
        level.push_back(0);
        int presentLevel = 0;
        Vertex* tempVertex;
        while(sliding_queue.size() != 0){
            tempVertex = sliding_queue.at(sliding_queue.size() - 1);
            for(int i=0;i<tempVertex->adjacencyList.size();i++){
                if(color[tempVertex->adjacencyList.at(i)->vertexID] == 0){
                    sliding_queue.insert(sliding_queue.begin(), tempVertex->adjacencyList.at(i));
                    level.insert(level.begin(), (presentLevel+1));
                    color[tempVertex->adjacencyList.at(i)->vertexID] = 1;
                }
            }
            sliding_queue.pop_back();
            level.pop_back();
            if(level.size() != 0){
                if(presentLevel != level.at(level.size() - 1)){
                    presentLevel = level.at(level.size() - 1);
                }
            }

        }
        return presentLevel;
    }
    void DepthFirstSearch(int startVertexID){
        Vertex* startNode = node.find(startVertexID)->second;
        vector<Vertex*> dynamic_stack;
        dynamic_stack.push_back(startNode);
        bool color[this->numElements] = {0};
        // color[startVertexID] = 1;
        bool flag = 0;
        Vertex* tempVertex;
        while(dynamic_stack.size() != 0){
            tempVertex = dynamic_stack.at(dynamic_stack.size() - 1);
            color[tempVertex->vertexID] = 1;
            flag = 0;
            for(int i=0;i<tempVertex->adjacencyList.size();i++){
                if(color[tempVertex->adjacencyList.at(i)->vertexID] == 0){
                    dynamic_stack.push_back(tempVertex->adjacencyList.at(i));
                    color[tempVertex->adjacencyList.at(i)->vertexID] = 1;
                    flag = 1;
                    break;
                }
            }
            cout<<tempVertex->vertexID<<" ";
            if(!flag){
                dynamic_stack.pop_back();
            }
        }
    }

};
int main(){
    int i, j, n;
    cin>>n;
    Graph* myGraph = new Graph(n);

    myGraph->insertEdge(1,0);
    myGraph->insertEdge(2,1);
    myGraph->insertEdge(2,3);
    myGraph->insertEdge(4,3);
    myGraph->insertEdge(5,4);
    myGraph->insertEdge(1,3);
    myGraph->insertEdge(2,4);
    myGraph->insertEdge(1,5);
    myGraph->insertEdge(6,3);
    myGraph->insertEdge(7,4);
    myGraph->insertEdge(8,0);
    myGraph->insertEdge(7,6);
    myGraph->insertEdge(8,2);
    myGraph->insertEdge(6,1);
    myGraph->insertEdge(6,5);
    myGraph->DepthFirstSearch(0);
    return 0;
}
