#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include"node.h"
using namespace std;

void printLL(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node *takeInput1(){
	int data;
	cin>>data;
	Node *head = NULL;
	while(data!=-1){
		Node *newNode = new Node(data);
		if(head==NULL){
			head = newNode;
		}else{
			Node *temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cin>>data;
	}
	return head;
}

Node *takeInput2(){
	int data;
	cin>>data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data!=-1){
		Node *newNode = new Node(data);
		if(head==NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}

int length(Node *head) {
    if(head==NULL) return 0;
    return 1+length(head->next);
}

Node* insertNodeRec(Node *head, int i, int data){
    if(head==NULL || i<0) return head;
    if(i==0){
        Node *newNode = new Node(data);
        newNode->next = head;
        head=newNode;
    }
    head->next = insertNodeRec(head->next,i-1,data);
    return head;
}

Node* deleteNodeRec(Node *head, int i) {
    if(head==NULL || i<0) return head;
    if(i==0){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head->next = deleteNodeRec(head->next,i-1);
    return head;
}



int main(){
	Node *head = takeInput2();
	printLL(head);

}