#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define ff first
#define ss second
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



int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<" "<<1<<endl;
            continue;
        }
        int a=1,b=1;
        rloop(i,sqrt(n),1){
            if(n%i==0){
                int a = n/i;
                int b = i;
                if(gcd(a,b)==1ll){
                    cout<<a<<" "<<b<<endl;
                    break;
                }
            }
        }


    }
}
