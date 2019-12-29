#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb  push_back
#define ppb pop_back
#define mp  make_pair
#define SIZE 200005
pll gift[SIZE];
vll give;
vll take;
vll both;
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;++i){
		ll e;
		cin>>e;
		gift[e].second=i;
		gift[i].first=e;
	}
	for(ll i=1;i<=n;++i){
		if(gift[i].first==0&&gift[i].second==0)
			both.pb(i);
		else if(gift[i].first==0){
			give.pb(i);
		}
		else if(gift[i].second==0){
			take.pb(i);
		}
	}
	ll i=0;
	if(both.size()>1){
		while(i<both.size()-1){
			gift[both[i]].first=both[i+1];
			i++;
		}
		gift[both[both.size()-1]].first=both[0];
		i=0;
	}
	else if(both.size()==1){
		gift[both[0]].first=take[0];
		gift[give[0]].first=both[0];
		i=1;
	}
	while(i<give.size()){
			gift[give[i]].first=take[i];
			i++;
	}
	// cout<<endl;
	for(ll i=1;i<=n;++i){
		cout<<gift[i].first<<" ";
	}
 
}