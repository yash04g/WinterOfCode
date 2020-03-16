#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class TrieNode{
public:
	char data;
	TrieNode **children;
	bool isTerminal;
	TrieNode(char data){
		this->data = data;
		children = new TrieNode*[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		isTerminal = 0;
	}
};
class Trie{
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode* root,string word){
		if(word.size()==0){
			root->isTerminal = 1;
			return;
		}
		int idx = word[0]-'a';
		TrieNode *child = root->children[idx];
		if(child==NULL){
			child = new TrieNode(word[0]);
			root->children[idx] = child;
		}
		insertWord(child,word.substr(1));
	}

	void insertWord(string word){
		insertWord(root,word);
	}

	bool searchWord(TrieNode* root,string word){
		if(word.size()==0){
			return root->isTerminal;
		}
		int idx = word[0]-'a';
		TrieNode *child = root->children[idx];
		if(child==NULL){
			return false;
		}
		return searchWord(child,word.substr(1));
	}
	bool searchWord(string word){
		return searchWord(root,word);
	}
	void removeWord(TrieNode* root,string word){
		if(word.size()==0){
			root->isTerminal = 0;
			return;
		}
		int idx = word[0]-'a';
		TrieNode *child = root->children[idx];
		if(!child) return;
		removeWord(child,word.substr(1));
		// If the child is useless it must be removed
		if(root->isTerminal==0){
			for(int i=0;i<26;i++){
				if(child->children[i]!=NULL) return;
			}
			delete child;
			root->children[idx] = NULL;
		}

	}
	void removeWord(string word){
		removeWord(root,word);
	}
};