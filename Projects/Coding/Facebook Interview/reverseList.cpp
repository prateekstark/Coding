#include<iostream>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int n){
		this->data = n;
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

	void insertNode(int n){
		Node* newNode = new Node(n);
		if(this->size == 0){
			this->head = newNode;
		}
		else{
			Node* tempNode = this->head;
			for(int i=0;i<this->size-1;i++){
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
		this->size = this->size + 1;
		return;
	}

	int deleteLast(){
		Node* tempNode = this->head;
		int lastData = 0;
		if(this->size > 0){
			if(this->size == 1){
				lastData = this->head->data;
				this->head = NULL;
			}
			else{
				while(tempNode->next->next != NULL){
					tempNode = tempNode->next;
				}
				lastData = tempNode->next->data;
				tempNode->next = NULL;
			}
			this->size--;
		}
		return lastData;
	}

	int deleteFront(){
		Node* tempNode = this->head;
		int lastData = this->head->data;
		if(this->size > 0){
			if(this->size == 1){
				this->head = NULL;
			}
			else{
				this->head = tempNode->next;
			}
			this->size--;
		}
		return lastData;
	}

	void viewList(){
		Node* tempNode = this->head;
		while(tempNode != NULL){
			cout<<tempNode->data<<" ";
			tempNode = tempNode->next;
		}
		cout<<endl;
	}
};

int main(){
	int n, m;
	cin>>n;
	int i, j, temp;
	LinkedList* myList = new LinkedList();
	LinkedList* answerList = new LinkedList();
	for(i=0;i<n;i++){
		cin>>temp;
		myList->insertNode(temp);
	}

	cin>>n;
	cin>>m;

	for(int i=0;i<n;i++){
		answerList->insertNode(myList->deleteFront());
	}
	LinkedList* tempList = new LinkedList();
	for(int i=n;i<=m;i++){
		tempList->insertNode(myList->deleteFront());
	}
	while(tempList->size != 0){
		answerList->insertNode(tempList->deleteLast());
	}
	while(myList->size != 0){
		answerList->insertNode(myList->deleteFront());	
	}
	answerList->viewList();
	return 0;
}
