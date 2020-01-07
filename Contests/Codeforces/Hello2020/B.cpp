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
const int N = 1e6+5;
int freq[N];
int freq1[N];
 
bool checkAscent(vi a){
    int n = a.size();
    if(n==1) return false;
    // loop(i,0,n){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int i = 0;
    int j = n-1;
    vi diff;
    loop(i,1,n){
        diff.pb(a[i]-a[i-1]);
    }
    loop(i,0,diff.size()){
        if(diff[i]>0)
            return true;
    }
    return false;
}
 
int32_t main(){
    get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
        int n;
        cin>>n;
        vvi a;
        
        loop(i,0,n){
            // cout<<i<<endl;
            int q;
            cin>>q;
            vi b(q);
            loop(j,0,q){
                cin>>b[j];
            }
            a.pb(b);
        }
        // exit(0);
        int cnt1 = 0;
        map<vi,int> m;
        loop(i,0,n){
            int mini = 1e6+2;
            if(checkAscent(a[i])){
                    cnt1++;
                    m[a[i]]++;
            }else{
            for(auto x:a[i]){
                    mini = min(x,mini);
            }
                freq[mini]++;
            }
        }
        
        freq1[0] = freq[0];
        loop(i,1,1000001){
            freq1[i] = freq1[i-1]+freq[i];
        }
        int ans = 0;
        loop(i,0,n){
            if(m[a[i]]>0) 
                continue;
            int q = a[i].size();
            int maxima = -1;
            loop(j,0,q) maxima = max(maxima,a[i][j]);
            ans += freq1[maxima-1];
        }
        int res = ans+2ll*(n-cnt1)*cnt1+cnt1*cnt1;
        cout<<res<<endl;
    }
}