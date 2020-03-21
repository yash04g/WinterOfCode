#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *takeInputDFS(){
	int data;
	cin>>data;
	if(data == -1) return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	BinaryTreeNode<int>* leftChild = takeInputDFS();
	BinaryTreeNode<int>* rightChild = takeInputDFS();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

void printDFS(BinaryTreeNode<int>* root){
	if(root==NULL) return;
	cout<<root->data;
	printDFS(root->left);
	printDFS(root->right);
}

BinaryTreeNode<int> *takeInputBFS(){
	int data;
	cin>>data;
	if(data==-1) return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode<int>* par = q.front();
		q.pop();
		cin>>data;
		if(data!=-1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(data);
			par->left = leftChild;
			q.push(leftChild);
		}
		cin>>data;
		if(data!=-1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(data);
			par->right = rightChild;
			q.push(rightChild);
		}
	}
	return root;
}

void printBFS(BinaryTreeNode<int>* root){
	if(root==NULL) return;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode<int>* par = q.front();
		q.pop();
		cout<<par->data<<" ";
		if(par->left){
			q.push(par->left);
		}
		if(par->right){
			q.push(par->right);
		}
	}
}
int height(BinaryTreeNode<int> *root) {
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}


int main(){
	BinaryTreeNode<int> *root = takeInputBFS();
	printDFS(root);
}
