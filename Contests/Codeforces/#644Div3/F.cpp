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

int match(string s1,string s2){
    int cnt = 0;
    int m = s1.size();
        loop(k,0,m){
            if(s1[k]!=s2[k]) cnt++;
        }
    return cnt;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string s[n];
    loop(i,0,n){
        cin>>s[i];
    }
    if(m==1){
        cout<<"z"<<endl;
        return;
    }
    bool flag = 1;
    vector<pair<string,string> > a;
    loop(i,0,n-1){
        loop(j,i+1,n){
            string s1 = s[i];
            string s2 = s[j];
            int cnt = 0;
            loop(k,0,m){
                if(s1[k]!=s2[k]) cnt++;
            }
            if(cnt>2){
                cout<<-1<<endl;
                return;
            }
            if(cnt==2){
                flag = 0;
                a.pb(mp(s1,s2));
            }
        }
    }
    if(flag){
        cout<<s[0]<<endl;
        return;
    }else{
        flag = 0;
            loop(i,0,a.size()){
                string temp1="";
                string temp2="";
                string s1 = a[i].ff;
                string s2 = a[i].ss;
                int cn = 0;
                loop(j,0,m){
                    if(s1[j]!=s2[j]){
                        if(cn==1){
                            temp1 += s2[j];
                            temp2 += s1[j];
                        }else{
                            temp1 += s1[j];
                            temp2 += s2[j];
                            cn++;
                        }
                    }else{
                        temp1 += s1[j];
                        temp2 += s2[j];
                    }
                }
                int state = 1;
                loop(j,0,n){
                    string curr = s[j];
                    int cnt = match(s[j],temp1);
                    if(cnt>1){
                        state = 0;
                        break;
                    }
                }
                if(state == 1){
                    cout<<temp1<<endl;
                    return;
                }
                state = 1;
                loop(j,0,n){
                    string curr = s[j];
                    int cnt = match(s[j],temp2);
                    if(cnt>1){
                        state = 0;
                        break;
                    }
                }
                if(state == 1){
                    cout<<temp2<<endl;
                    return;
                }

            }
            cout<<-1<<endl;
            return;
    }




}

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        solve();        
    }
}
