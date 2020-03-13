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

Node *midLL(Node *head){
	if(head==NULL || head->next==NULL) return head;
	Node *slow = head;
	Node *fast = head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node *merge(Node *head1,Node *head2){
	if(!head1) return head2;
	if(!head2) return head1;
	Node *head = NULL;
    Node *tail = NULL;
	if(head1->data > head2->data){
	head = head2;
	tail = head2;
	head2 = head2->next;
    }else{
		head = head1;
        tail = head1;
        head1 = head1->next;
	}
    while(head1!=NULL && head2!=NULL){
		if(head1->data > head2->data){
			tail->next = head2;
			head2 = head2->next;
            tail = tail->next;
        }else{
			tail->next = head1;
			head1 = head1->next;
            tail = tail->next;
        }
    }
	if(!head1) tail->next = head2;
	else tail->next = head1;
	return head;
}

Node *mergeSort(Node *head){
	if(head==NULL || head->next==NULL) return head;
	Node* mid = midLL(head);
    Node* head1 = head;
    Node* head2 = mid->next;
    mid->next = NULL;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    Node* fhead = merge(head1,head2);
    return fhead;
}

int main(){
	Node *head = takeInput2();
	printLL(head);
	head = mergeSort(head);
	printLL(head);
}