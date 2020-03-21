#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

template<typename T>

class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};