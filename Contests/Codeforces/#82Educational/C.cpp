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
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
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
const int N = 26;
set<int> s1[N];
vi adjList[N];
int32_t main(){
    get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        loop(i,0,26){
            s1[i].clear();
            adjList[i].clear();
        }
        string s;
        cin>>s;
        int n = s.size();
        if(n==1){
            string ans = "";
            ans += s[0];
            loop(i,0,26){
                if((i+'a')==s[0]){
                    continue;
                }else{
                    char c = i+'a';
                    ans+= c;
                }
            }
            cout<<"YES"<<endl<<ans<<endl;
            continue;
        }
        loop(i,0,n-1){
            s1[s[i]-'a'].insert(s[i+1]-'a');
            s1[s[i+1]-'a'].insert(s[i]-'a');
        }
        int cnt = 0;
        vi ans;
        bool flag = 1;
        set<int> s2;
        loop(i,0,n){
            s2.insert(s[i]);
        }
        loop(i,0,26){
            if(s1[i].size()==1){
                // cout<<i<<endl;
                ans.pb(i);
                cnt++;
            }
            if(s1[i].size()>2){
                flag = 0;
            }
        }
        int req = s2.size();
        // deb(s1['t'-'a'].size(),('t'-'a'));
        // deb(s1['x'-'a'].size(),('x'-'a'));
        // deb(s1['y'-'a'].size(),('y'-'a'));
        // deb(s1['z'-'a'].size(),('z'-'a'));
        if(cnt==2 && flag){
            // cout<<s<<endl;
            cout<<"YES"<<endl;
            map<char,bool> m;
            char st = ans[0]+'a';
            char en = ans[1]+'a';
            m[st] = 1;
            m[en] = 1;
            string ans = "";
            ans += st;
            int temp = req-2;
            while(temp--){
                ans += ' ';
            }
            ans += en;
            req -= 2;
            int i = 1;
            int j = i+req;
            char prev = st; 
            while(i<j){
                for(auto x:s1[prev-'a']){
                    if(m[x+'a']){
                        continue;
                    }else{
                        char curr = 'a'+x;
                        ans[i] = curr;
                        m[curr] = 1;
                        prev = curr;
                        i++;
                    }
                }
            }
            loop(i,0,26){
                if(s2.find(i+'a')==s2.end()){
                    char c = i+'a';
                    ans += c;
                }
            }
            cout<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }





    }
}
