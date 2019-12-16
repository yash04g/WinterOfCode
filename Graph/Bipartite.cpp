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
	bool isBipartite(int src){
		queue<int> q;
		vector<int> colors(V,-1);

		q.push(src);
		colors[src] = 0;

		bool ans = true;
		while(!q.empty() && ans){
			int u = q.front();
			q.pop();
			for(auto v:adjList[u]){
				if(colors[v]==-1){
					colors[v] = 1-colors[u];
					q.push(v);
				}
				else if(colors[v]!=-1){
					ans = false;
					break;
				}
			}
		}
		return ans;
	}
};
int main(){
	Graph g(4);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(0,1);
	g.addEdge(0,3);
	cout<<g.isBipartite(0)<<endl;

}