#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int n){
        this->data = n;
        this->next = NULL;
    }

};

class LinkedList{
public:
    Node* head;
    int size;
    LinkedList(){
        this->head = NULL;
        this->size = 0;
    }

    void insertNode(int data){
        Node* newNode = new Node(data);
        if(this->size == 0){
            this->head = newNode;
        }
        else{
            Node* tempNode = this->head;
            while(tempNode->next != NULL){
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
        size++;
    }
    void deleteNode(int i){
        if(i > size-1){
            cerr<<"Index out of bound"<<endl;
        }
        else{
            if(i == 0){
                head = head->next;
                return;
            }
            Node* prevNode = this->head;
            Node* tempNode = prevNode->next;
            for(int j=0;j<i-1;j++){
                prevNode = prevNode->next;
                tempNode = prevNode->next;
            }
            prevNode->next = tempNode->next;
        }
        return;
    }

    void printList(){
        Node* tempNode = this->head;
        while(tempNode != NULL){
            cout<<tempNode->data<<" ";
            tempNode = tempNode->next;
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    int temp;
    LinkedList* myList = new LinkedList();
    for(int i=0;i<n;i++){
        cin>>temp;
        myList->insertNode(temp);
    }
    myList->printList();
    myList->deleteNode(4);
    myList->printList();
    return 0;
}
