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
		this->head = new Node(0);
		this->size = 0;
	}
	void insertNode(int newData){
		Node* newNode = new Node(newData);
		if(this->size == 0){
			this->head = newNode;
		}
		else{
			Node* tempNode = this->head;
			for(int i=0;i<(this->size)-1;i++){
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
		this->size++;
	}
	void viewList(){
		Node* tempNode = this->head;
		for(int i=0;i<this->size;i++){
			cout<<tempNode->data<<" ";
			tempNode = tempNode->next;
		}
		cout<<endl;

	}
};



void balanceList(LinkedList* list1, LinkedList* list2){

	while(list1->size > list2->size){
		list2->insertNode(0);
	}
	while(list1->size < list2->size){
		list1->insertNode(0);
	}
	return;
}




int main(){
	
	int n, m;
	cin>>n;
	int i, j, temp;
	LinkedList* myList1 = new LinkedList();
	LinkedList* myList2 = new LinkedList();
	for(i=0; i<n; i++){	
		cin>>temp;
		myList1->insertNode(temp);
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>temp;
		myList2->insertNode(temp);
	}
	LinkedList* answerList = new LinkedList();
	Node* tempNode1 = myList1->head;
	Node* tempNode2 = myList2->head;
	balanceList(myList1, myList2);
	int carry = 0;
	for(i=0;i<n;i++){
		temp = tempNode1->data + tempNode2->data + carry;
		if(temp/10 != 0){
			carry = temp/10;
		}
		else{
			carry = 0;
		}
		answerList->insertNode(temp%10);
		tempNode1 = tempNode1->next;
		tempNode2 = tempNode2->next;
	}


	if(carry != 0){
		answerList->insertNode(carry);

	}

	answerList->viewList();


	return 0;
}
