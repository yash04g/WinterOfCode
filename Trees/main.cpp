#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;

void printTreeDFS(TreeNode<int>* root){
	if(root==NULL) return;
	cout<<root->data<<" : ";
	for(int i = 0; i < root->children.size();++i){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTreeDFS(root->children[i]);
	}
}
TreeNode<int> *takeInputDFS(){
	int rootData;
	cin>>rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int> *child = takeInputDFS();
		root->children.push_back(child);
	}
	return root;
}
TreeNode<int>* takeInputBFS(){
	int rootData;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode<int>* parent = q.front();
		q.pop();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int data;
			cin>>data;
			TreeNode<int>* child = new TreeNode<int>(data);
			parent->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}
void printTreeBFS(TreeNode<int> *root){
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode<int>* parent = q.front();
		q.pop();
		cout<<parent->data<<" ";
		for(int i=0;i<parent->children.size();i++){
			q.push(parent->children[i]);
		}
		cout<<endl;
	}
}

int numNodes(TreeNode<int>* root){
	if(root==NULL) return 0;
	int ans = 1;
	for(int i=0;i<root->children.size();++i){
		ans += numNodes(root->children[i]);
	}
	return ans;
}

int height(TreeNode<int>* root) {
    if(!root) return 0;
    int maxi = 0;
    for(int i=0;i<root->children.size();i++){
        maxi = max(maxi,height(root->children[i]));
    }
    return 1+maxi;

}

void printNodesAtKLevel(TreeNode<int>* root,int k){
	if(root==NULL) return;
	if(k==0){
		cout<<root->data<<" ";
	}
	for(int i=0;i<root->children.size();i++){
		printNodesAtKLevel(root->children[i],k-1);
	}
}
void preOrder(TreeNode<int>* root) {
    if(root==NULL) return;
	
	cout<<root->data<<" ";

	for(int i=0;i<root->children.size();i++){
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int>* root) {
    if(root==NULL) return;
	
	for(int i=0;i<root->children.size();i++){
		postOrder(root->children[i]);
	}

	cout<<root->data<<" ";
}
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==NULL) return root;
    TreeNode<int>* maxi = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp){
            if(temp->data>maxi->data) maxi = temp;
        }
    }
    return maxi;
    
}

void deleteTree(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		deleteTree(root->children[i]);
	}
	delete root;
}

void helper(TreeNode<int> *root,int depth){
    if(root==NULL){
        return;
    }
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++){
        helper(root->children[i],depth+1);
    }
} 
void replaceWithDepthValue(TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    helper(root,0);
}

int main(){
	TreeNode<int> *root = takeInputBFS();
	printTreeBFS(root);
	cout<<numNodes(root)<<endl;
}