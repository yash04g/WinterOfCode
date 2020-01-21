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
#define mset(a,i) memset(a,i,sizeof(a))
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
#define sp(x,y) fixed<<setprecision(y)<<x

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
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vi a(4*n);
        loop(i,0,4*n) cin>>a[i];
        sort(all(a));
        set<int> s;
        bool check = 1;
        int l = 0;
        int r = 4*n-1;
        while(l<=r){
            bool check1 = (a[l]==a[l+1]);
            bool check2 = (a[r]==a[r-1]);
            int area = a[l]*a[r];
            s.insert(area);
            check &= (check1&check2);
            if(!check || s.size()>1) break;
            l += 2;
            r -= 2;
        }
        if(check && s.size()==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }
}
