#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
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
int visited[N];
int n;

int solve(int idx){
	if(idx >= n)
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	if(!visited[idx])
		ans = solve(idx + 1);
	else
		ans = 1 + min(solve(idx + 2), solve(idx + 3));
	return ans;
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	
    	cin>>n;
    	vi a(n);
    	int m[N];
    	int m2[N];
    	int m3[N];
    	memset(m,0,sizeof(m));
    	memset(m2,0,sizeof(m2));
    	memset(m3,0,sizeof(m3));
    	set<int> s;
    	loop(i,0,n) cin>>a[i],m[a[i]]++,s.insert(a[i]),m2[a[i]]++,m3[a[i]]++;
    	sort(all(a));
    	// Maxima
    	for(auto x:s){
    		// cout<<x<<endl;
    		if(m[x]==1){
    			continue;
    		}
    		else if(m[x]==2){
    			if(m[x-1]==0){
    				m[x-1]++;
    				m[x]--;
    			}else if(m[x+1]==0){
    				m[x+1]++;
    				m[x]--;
    			}
    		}else{
    			if(m[x-1]==0){
    				m[x-1]++;
    				m[x]--;
    			}
    			if(m[x+1]==0){
    				m[x+1]++;
    				m[x]--;
    			}
    		}
    	}
    	int maxi = 0;
    	loop(i,0,N){
    		// cout<<m[i]<<" ";
    		if(m[i]>0){
    			maxi += 1;
    		}
    	}
    	// cout<<maxi<<endl;
    	//MINIMA

    	// bool flag = true;
    	// for(auto x:s){
    	// 	if(m2[x]==0){
    	// 		continue;
    	// 	}
    	// 	if(m2[x-1]>0){
    	// 		m2[x-1] += m2[x];
    	// 		m2[x] = 0;
    	// 	}
    	// 	else if(m2[x+1]>0){
    	// 		m2[x+1] += m2[x];
    	// 		m2[x] = 0;
    	// 	}
    	// 	else{
    	// 		if(m2[x+2]>0){
    	// 			if(x==1){
    	// 				m2[x+1] += (m2[x]+m2[x+2]);
    	// 				m2[x] = 0;
    	// 				m2[x+2] = 0;
    	// 			}else{
    	// 				if(m3[x-1]>0){
    	// 					continue;
    	// 				}else{
    	// 					m2[x+1] += (m2[x]+m2[x+2]);
    	// 					m2[x] = 0;
    	// 					m2[x+2] = 0;
    	// 				}
    	// 			}
    	// 		}
    	// 	}
    	// }
    	int mini = solve(0);
    	// loop(i,0,N){
    	// 	// cout<<m2[i]<<endl;
    	// 	if(m2[i]>0){
    	// 		mini += 1;
    	// 	}
    	// }
    	cout<<mini<<" "<<maxi<<endl;


    }
}
