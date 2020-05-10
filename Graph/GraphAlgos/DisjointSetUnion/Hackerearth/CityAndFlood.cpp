#include<iostream>
#include<vector>
#include<set>
using namespace std;
void initialize(vector<int> &parent,vector<int> &size,int n){
	for(int i=1;i<=n;i++){
		parent[i] = i;
		size[i] = 1;
	}
}
int Find_Parent(int a,vector<int>& parent){
	// a is the node whose parent is to be calculated
	while(parent[a]!=a){
		a = parent[a];
	}
	return a;
}
bool connected(int a,int b,vector<int>&parent){
	if(Find_Parent(a,parent)==Find_Parent(b,parent)){
		return true;
	}
	else{
		return false;
	}
}
void union_Nodes(int a,int b,vector<int>& parent,vector<int>& size){
	if(connected(a,b,parent)){
		return;
	}
	int r_a = Find_Parent(a,parent);
	int r_b = Find_Parent(b,parent);
	if(size[r_a]<size[r_b]){
		parent[r_a] = r_b;
		size[r_b] = size[r_b] + size[r_a];
	}
	else{
		parent[r_b] = r_a;
		size[r_a] = size[r_b] + size[r_a];
	}
}

int main(){
	int n;
	cin>>n;
	int NumUnions;
	cin>>NumUnions;
	vector<int> parent(n+1);
	vector<int> size(n+1);
	initialize(parent,size,n);
	for(int j=0;j<NumUnions;j++){
		int f,s;
		cin>>f>>s;
		union_Nodes(f,s,parent,size);
	}
	set<int> input;
	for(int i=1;i<=n;i++){
		input.insert(Find_Parent(i,parent));
	}
	cout<<input.size()<<endl;
}