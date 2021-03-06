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

bool compare(pii a,pii b){
    return a.ss<b.ss;
}


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vpii pts;
        loop(i,0,n){
            int x,y;
            cin>>x>>y;
            pii temp = make_pair(x,y);
            pts.push_back(temp);
        }
        sort(all(pts));
        string ans="";
        int curx=0,cury=0;
        bool flag = 1;
        loop(i,0,n){
            if(pts[i].first<curx || pts[i].second<cury){
                flag = 0;
                break;
            }
            else{
                string str;
                for(int j=0; j<(pts[i].second-cury); j++){
                    str += 'U';
                }
                for(int j=0; j<(pts[i].first-curx); j++){
                    str += 'R';
                }
                sort(all(str));
                ans += str;
            }
            curx = pts[i].first;
            cury = pts[i].second;
        }
        if(flag){
            cout<<"YES"<<endl<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
