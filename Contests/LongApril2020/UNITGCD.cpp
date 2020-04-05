#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// #define int long long
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
#define pii pair<int,int>
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
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 3e5+5;

int main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<endl<<1<<" "<<1<<endl;
            continue;
        }
        vvi ans;
        vi temp;
        temp.pb(1);
        temp.pb(2);
        if(n&1){
            temp.pb(n);
            n -= 1;
        }
        ans.pb(temp);
        for(int i=3;i<=n;i+=2){
            vi temp;
            temp.pb(i);
            temp.pb(i+1);
            ans.pb(temp);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].size()<<" ";
            for(int j=0;j<ans[i].size();j++){
                if(j==(ans[i].size()-1)){
                    cout<<ans[i][j]<<endl;
                }else{
                    cout<<ans[i][j]<<" ";
                }
            }
        }
    }
    return 0;
}
