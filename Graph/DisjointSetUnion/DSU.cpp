#include<iostream>
#include<vector>
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
		parent[a] = parent[parent[a]]; // Optional
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
		size[r_b] += size[r_a];
	}
	else{
		parent[r_b] = r_a;
		size[r_a] += size[r_b];
	}
}

int main(){
	int n; // Number of Nodes none of which are connected
	cin>>n;
	vector<int> parent(n+1);
	vector<int> size(n+1);
	initialize(parent,size,n);
	union_Nodes(1,2,parent,size);
	union_Nodes(2,3,parent,size);
	union_Nodes(3,4,parent,size);
	union_Nodes(6,7,parent,size);
	cout<<connected(1,4,parent)<<" "<<connected(5,6,parent)<<endl;
	cout<<Find_Parent(3,parent)<<endl;

	// for(int i=1;i<=n;i++){
	// 	cout<<"Node is "<<parent[i]<<" Size is "<<size[i]<<endl;
	// }

}