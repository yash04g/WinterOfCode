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
#define mii map<int,int>
#define mci map<char,int>  
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
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];
int n;
string s1,s2;
map<char,vi> m1;
map<char,vi> m2;
vpii ans;

void solve(char ch1,char ch2){
    int sz = min(m1[ch1].size(),m2[ch2].size());
    while(sz>0){
        int i = m1[ch1].back();
        m1[ch1].pop_back();
        int j = m2[ch2].back();
        m2[ch2].pop_back();
        sz--;
        ans.pb(mp(i,j));
    }
}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        cin>>n;
        cin>>s1>>s2;
        loop(i,0,n){
            m1[s1[i]].pb(i+1);
            m2[s2[i]].pb(i+1);
        }
        for(char ch='a';ch<='z';ch++)
            solve(ch, ch);
        for(char ch='a';ch<='z';ch++)
            solve('?', ch);
        for(char ch='a';ch<='z';ch++)
            solve(ch, '?');
        for(char ch='a';ch<='z';ch++)
            solve('?', '?');
        cout<<ans.size()<<endl;
        for(auto x:ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
}
