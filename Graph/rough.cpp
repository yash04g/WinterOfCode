#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<int>* adjList;
public:
	Graph(int v){
		V= v;
		adjList = new vector<int>[V];
	}
	void addEdge(int u,int v,bool bidir=1){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAdjList(){
		for(int i=0;i<V;++i){
			cout<<i<<"-> ";
			for(auto node:adjList[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src){
		queue<int> q;
		vector<bool> visited(V,0);

		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto neighbour : adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
		cout<<endl;
	}
	void sssp_bfs(int src){
		
		queue<int> q;
		vector<int> dist(V,1e9);
		vector<int> parent(V,-1);
		
		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto neighbour : adjList[node]){
				if(dist[neighbour]==1e9){
					q.push(neighbour);
					dist[neighbour] = dist[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		for(int i=0;i<V;++i){
			cout<<"Distance from "<<i<<" to "<<src<<" is "<<dist[i]<<endl;
			cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;
		}
	}
	
};
int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(4,0);
	g.addEdge(4,2);
	g.addEdge(2,3);
	g.addEdge(5,3);
	g.addEdge(4,3);
	g.printAdjList();
	g.bfs(0);
	g.sssp_bfs(0);
}