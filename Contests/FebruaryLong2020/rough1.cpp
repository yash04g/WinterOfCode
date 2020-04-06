#include <bits/stdc++.h>
using namespace std;
#define ll long long
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int N = 1e5+5;
ll n;
ll dp[N][4];
ll arr[N];
ll ans = 0;

void solve(){
    dp[0][arr[0]] = 1ll;
    if(arr[0]!=2ll) ans += 1ll;
	for(ll i=1ll;i<n;++i){
        for(ll j=0;j<4ll;++j){
			dp[i][(j*arr[i])%4ll] += dp[i-1][j];
        }
        dp[i][arr[i]] += 1ll;
		for(ll j=0ll;j<4ll;++j){
			if(j==2ll) continue;
            ans += dp[i][j];
        }
    }
}

int32_t main(){
    get_it_done();
    ll q=1;
    cin >> q;
    while (q--){
    	ans = 0;
    	for(ll i=0ll;i<n;++i) for(ll j=0ll;j<4ll;j++) dp[i][j] = 0ll;
        cin>>n;
        for(ll i=0ll;i<n;++i){
            cin>>arr[i];
            arr[i] = (arr[i]%4ll+4ll);
            arr[i] %= 4ll;
        }
		solve();
        cout<<ans<<endl;
        
    }
}
