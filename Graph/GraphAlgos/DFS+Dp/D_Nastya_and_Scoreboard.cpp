// https://codeforces.com/contest/1341/problem/D

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
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
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
const int N = 2005;
string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n;
int changes[N][10];
int dp[2005][2005][10];
string ans = "";

int solve(int idx,int k,int num){
    if(idx ==n){
        if(k==0){
            return dp[idx][k][num] = 1;
        }
        return dp[idx][k][num] = 0;
    }
    if(k<0){
        return dp[idx][k][num] = 0;
    }
 
    if(dp[idx][k][num] != -1) 
        return dp[idx][k][num];
    int ans = 0;
    rloop(i,9,0){
        int cnt = changes[idx][i];
        if(cnt!=-1 && cnt<=k){
            ans |= solve(idx+1,k-cnt,i);
        }
    }
    return dp[idx][k][num] = ans;
}
void compute(int idx,int k){
    if(idx==n)
        return;
    rloop(i,9,0){
        int cnt = changes[idx][i];
        if(cnt!=-1 && k-cnt>=0 && dp[idx+1][k-cnt][i]==1){
            char dig = i+'0';
            // deb(dig);
            ans += dig;
            compute(idx+1,k-cnt);
            return;
        }
    }
}

int32_t main(){
    get_it_done();
    int q=1;
    // cin >> q;
    while (q--){
        int k;
        cin>>n>>k;
        mset(changes,0);
        loop(i,0,n){
            string s;
            cin>>s;
            loop(j,0,10){
                string to = digits[j];
                bool flag = 1;
                int cnt = 0;
                loop(k,0,7){
                    if(s[k]=='1' && to[k]=='0'){
                        flag = 0;
                        break;
                    }else if(s[k]=='0' && to[k]=='1'){
                        cnt++;
                    }
                }
                if(flag){
                    changes[i][j] = cnt;
                }else{
                    changes[i][j] = -1;
                }
            }
        }
        mset(dp,-1);
        int flag = solve(0,k,0);
        compute(0,k);
        if(flag==1){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}
