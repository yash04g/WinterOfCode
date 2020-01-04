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


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n;
        cin>>n;
        vi a(n-1);
        int maxi = 0;
        int mini = n+2;
        loop(i,0,n-1) cin>>a[i],maxi = max(maxi,a[i]),mini = min(a[i],mini);
        vi ans(n);
        if(maxi+1>n){
            cout<<-1<<endl;
            continue;
        }
        if(maxi==1 && mini==1){
            loop(i,1,n+1) cout<<i<<" ";
            continue;
        }
        int x = 0;
        vi sum(n-1);
        int s = 0;
        loop(i,0,n-1){
            s += a[i];
            sum[i] = s;
        }
        int minVal = 0;
        loop(i,0,n-1){
            if(sum[i]<minVal)
                minVal = sum[i];
        }
        x = 1-minVal;
        ans[0] = x;
        loop(i,0,n-1){
            ans[i+1] = sum[i]+x;
        }
        mii m1;
        loop(i,0,n){
            m1[ans[i]]++;
        }
        bool flag = true;
        loop(i,1,n+1){
            if(!m1[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            for(auto i:ans){
                cout<<i<<" ";
            }
        }else{
            cout<<-1<<endl;
        }






    }
}
