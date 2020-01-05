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
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int time = 0;
        int cnta = 0;
        loop(i,0,n){
            if(s[i]=='A')
                cnta++;
        }
        if(cnta==0){
            cout<<0<<endl;
            continue;        
        }
        if(cnta==1 && s[n-1]=='A'){
            cout<<0<<endl;
            continue;  
        }
        loop(i,0,n-1){
            if(s[i] == 'A' && s[i+1] != 'A'){
                int temp = 0;
                int j = i+1;
                loop(j,i+1,n){
                    if(s[j] != 'P'){
                        break;
                    }
                    temp++;
                }
                i = j;
                time = max(time,temp);
            }
        }
        cout<<time<<endl;
    }
}
