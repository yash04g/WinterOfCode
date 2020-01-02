#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];
int dist[100][100];
 
void floydWarshall(int V){
    int i, j, k;
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n;
    	cin >> n;
    	fo(i,n){
        	string s;
        	cin >> s;
        	fo(j,n){
            	if(s[j] == '0'){
                	dist[i][j] = inf;
            	}
            	else{
                	dist[i][j] = 1;
            	}
        	}
        	dist[i][i] = 0;
    	}
    	int m;
    	cin >> m;
    	int p[m];
    	fo(i,m){
        	cin >> p[i];
        	p[i]--;
    	}
    	floydWarshall(n);
    	vi v;
    	v.push_back(p[0]);
    	int curr = p[0];
    	Fo(i,1,m-1){
        	if (dist[curr][p[i]] + dist[p[i]][p[i + 1]] > dist[curr][p[i + 1]]){
            	curr = p[i];
            	v.push_back(p[i]);
        	}
    	}
    	v.push_back(p[m - 1]);
    	cout << v.size() << endl;
    	for (auto i : v){
        	cout << i + 1 << " ";
    	}
    }
}
