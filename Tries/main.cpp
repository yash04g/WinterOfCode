#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include "Trie.h"
using namespace std;
int main(){
	Trie t;
	t.insertWord("down");
	t.insertWord("don");
	t.insertWord("damn");
	t.insertWord("dexter");
	t.removeWord("don");
	cout<<t.searchWord("down")<<endl;
	cout<<t.searchWord("don")<<endl;
	cout<<t.searchWord("damn")<<endl;
}