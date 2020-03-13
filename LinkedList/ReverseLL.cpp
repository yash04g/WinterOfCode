#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include"node.h"
using namespace std;

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

void printLL(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

Node *reverseLL(Node *head){
	if(head==NULL || head->next==NULL) return head;
	Node *tail = head->next;
	Node* newHead = reverseLL(head->next);
	tail->next = head;
	head->next = NULL;
	return newHead;
}

Node *reverseLLIterative(Node* head){
	if(head==NULL || head->next==NULL) return head;
	Node *curr = head;
	Node *prev = NULL;
	Node *nextNode = head;
	while(curr!=NULL){
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	return prev;
}

int main(){
	Node *head = takeInput2();
	printLL(head);
	head = reverseLLIterative(head);
	printLL(head);

}