#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	vector<int> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new vector<int>[V];
	}
	void addEdge(int f,int s,bool bidir=1){
		adjList[f].push_back(s);
		if(bidir){
			adjList[s].push_back(f);
		}
	}
	void DFSHelper(int node,vector<bool> &visited,list<int> &ordering){
		visited[node] = true;
		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				DFSHelper(neighbour,visited,ordering);
			}
		}
		// At this point all the children of current node have been visited
		// So we can add current node to the list
		ordering.push_front(node);

	}
	void dfsTopologicalSort(){
		vector<bool> visited(V,0);
		list<int> ordering;
		for(int i=0;i<V;++i){
			if(!visited[i]){
				DFSHelper(i,visited,ordering);
			}
		}
		for(auto i:ordering){
			cout<<i<<" ";		
		}
	}

	void bfsTopologicalSort(){
		queue<int> q;
		vector<int> indegree(V,0);
		vector<bool> visited(V,0);
		// Initializing indegree of all nodes
		for(int i=0;i<V;++i){
			for(int v:adjList[i]){
				indegree[v]++;
			}
		}
		// Find out all nodes with 0 indegree
		for(int i=0;i<V;++i){
			if(indegree[i]==0){
				q.push(i);
			}
		}

		while(!q.empty()){
			auto node = q.front();
			q.pop();
			cout<<node<<"-> ";
			for(auto neighbour : adjList[node]){
				indegree[neighbour]--;
				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		}
	}

};

int main(){
	Graph g(6);
	g.addEdge(0,2,0);
	g.addEdge(1,2,0);
	g.addEdge(1,4,0);
	g.addEdge(2,3,0);
	g.addEdge(3,5,0);
	g.addEdge(4,5,0);
	
	g.dfsTopologicalSort();
	cout<<endl;
	g.bfsTopologicalSort();

}