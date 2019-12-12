#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

	int V;
	map<T,vector<T> > adjList;
public:
	Graph(){
	
	}
	void addEdge(T u,T v,bool bidir=1){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAdjList(){
		for(auto i:adjList){
			cout<<i.first<<"-> ";
			for(auto vertex:i.second){
				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(4,1);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.printAdjList();

}