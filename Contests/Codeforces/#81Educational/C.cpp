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
const int N = 2e5+5;
int dp[N];

bool check(string s,string t){
    int i = 0;
    int j = 0;
    int m = s.size();
    int n = t.size();
    bool flag = true;
    while(i<m && j<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j!=n){
        flag = false;
    }
    return flag;
}

int32_t main(){
    // ddccvvaa
    // adcav
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        string s1,s2;
        cin>>s1>>s2;
        if(check(s1,s2)){
            cout<<1<<endl;
            continue;
        }	
        map<char,int> m1;
        loop(i,0,s1.size()){
            m1[s1[i]]++;
        }
        bool flag = 1;
        loop(i,0,s2.size()){
            if(m1[s2[i]]==0) flag = 0;
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        map<char,vi> m2;
        loop(i,0,s1.size()){
            m2[s1[i]].pb(i);
        }
        int cnt = 0;
        int idx = -1;
        // loop(i,0,s2.size()){
        //     if(idx==-1){
        //         auto v = m2[s2[i]];
        //         idx = v[0];
        //         deb(idx);
        //         cnt++;
        //     }else{
        //         int idx1 = -1;
        //         for(auto x:m2[s2[i]]){
        //             if(x>idx){
        //                 idx1 = x;
        //             }
        //         }
        //         if(idx1==-1){
        //             cnt++;
        //             auto v = m2[s2[i]];
        //             idx = v[0];
        //         }else{
        //             idx = idx1;
        //         }
        //         deb(idx);
        //         deb(idx1);
        //         deb(cnt);
        //     }
        // }
        loop(i,0,s2.size()){
            if(idx==-1){
                auto v = m2[s2[i]];
                idx = v[0];
                cnt++;
            }else{
                int idx1 = -1;
                for(auto x : m2[s2[i]]){
                    // deb(x);
                    if(x>idx){
                        idx1 = x;
                        break;
                    }
                }
                if(idx1==-1){
                    cnt++;
                    idx = m2[s2[i]][0];
                }else{
                    idx = idx1;
                }
            }
        }
        cout<<cnt<<endl;

    }
}
