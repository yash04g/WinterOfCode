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
	void printAdjList(){
		for(int i=0;i<V;++i){
			cout<<i<<"-> ";
			for(int vertex:adjList[i]){
				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src){
		queue<int> q;
		vector<bool> visited(V,0);
		q.push(src);
		visited[src] = 1;
		while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto neighbour:adjList[node]){
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
		vector<int> distance(V,INT_MAX);
		vector<int> parent(V,-1);

		q.push(src);
		distance[src] = 0;
		parent[src] = src;
		
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto neighbour:adjList[node]){
				if(distance[neighbour]==INT_MAX){
					q.push(neighbour);
					distance[neighbour] = distance[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		for(int i=0;i<V;++i){
			cout<<"Distance from "<<i<<" to "<<src<<" is "<<distance[i]<<endl;
			cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;
		}
	}
	void helper(int src,vector<bool> &visited){
		cout<<src<<" ";
		visited[src] = true;
		for(auto neighbour : adjList[src]){
			if(!visited[neighbour]){
				helper(neighbour,visited);
				visited[neighbour] = true;
			}
		}
	}
	void dfs(int src){
		vector<bool> visited(V,0);
		helper(src,visited);
		cout<<endl;
	}
	int connected_components(int src){
		vector<bool> visited(V,0);
		int cnt = 0;
		for(int i=0;i<V;++i){
			if(!visited[i]){
				helper(src,visited);
				cnt += 1;
			}
		}
		return cnt;
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
	bool isCyclicBFS(int src){
		vector<bool> visited(V,0);
		vector<int> parent(V,-1);
		queue<int> q;

		visited[src] = true;
		parent[src] = src;
		q.push(src);
		while(!q.empty()){
			auto node = q.front();
			q.pop();
			for(auto neighbour : adjList[node]){
				if(visited[neighbour] && parent[node]!=neighbour){
					return true;
				}else{
					visited[neighbour] = true;
					parent[node] = neighbour;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
	bool isCyclicHelper(int node,vector<bool> &visited,int parent){
		visited[node] = true;
		for(auto neighbour : adjList[node]){
			if(!visited[neighbour]){
				bool ans = isCyclicHelper(neighbour,visited,node);
				if(ans){
					return true;
				}
			}
			// If neighbour is already visited and is not the parent
			else if(neighbour!=parent){
				return true;
			}
		}
		return false;
	}
	bool isCyclicDFS(int src){
		vector<bool> visited(V,0);
		for(int i=0;i<V;i++){
			if(!visited[i]){
				bool ans = isCyclicHelper(i,visited,i);
				if(ans){
					return true;
				}
			}
		}
		return false;
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
	g.dfs(0);
	int ans = g.connected_components(0);
	cout<<endl<<ans<<endl;
	cout<<g.isCyclicBFS(0)<<endl;
	cout<<g.isCyclicDFS(0)<<endl;

}
