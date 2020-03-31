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
const int N = 2e5+5;

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k==1){
            int freq[26];
            mset(freq,0);
            loop(i,0,n) freq[s[i]-'a']++;
            int maxi = 0;
            loop(i,0,26) maxi = max(maxi,freq[i]);
            int ans = n-maxi;
            cout<<ans<<endl;
            continue;
        }
        vector<string> s1;
        int x = n/k;
        int i = 0;
        map<string,int> m1;
        while(x--){
            string temp = "";
            loop(j,0,k){
                temp += s[i];
                i++;
            }
            s1.pb(temp); 
            m1[temp]++;
        }
        loop(i,0,s1.size()) cout<<s1[i]<<endl;
        string alpha;
        int mini = inf;
        map<int,int> m2;
        for(auto x:m1){
            string temp = x.ff;
            int p = temp.size();
            if(p&1){
                int mid = p/2;
                string pref = temp.substr(0,mid);
                string suff = temp.substr(mid+1);
                reverse(all(suff));
                int diff = 0;
                loop(i,0,pref.size()){
                    if(suff[i]!=pref[i]) diff++;
                }
                if(mini>diff*x.ss){
                    mini = diff*x.ss;
                    alpha = temp;
                }
            }else{
                int mid = p/2;
                string pref = temp.substr(0,mid);
                string suff = temp.substr(mid);
                reverse(all(suff));
                int diff = 0;
                loop(i,0,pref.size()){
                    if(suff[i]!=pref[i]) diff++;
                }
                if(mini>diff*x.ss){
                    mini = diff*x.ss;
                    alpha = temp;
                }
            }
        }
        int p = alpha.size();
        if(p&1){
            int mid = p/2;
            string pref = alpha.substr(0,mid);
            string suff = alpha.substr(mid+1);
            reverse(all(suff));
            string temp = pref;
            temp += alpha[mid];
            reverse(all(pref));
            temp += pref;
            alpha = temp;
        }else{
            int mid = p/2;
            string pref = alpha.substr(0,mid);
            string suff = alpha.substr(mid);
            reverse(all(suff));
            string temp = pref;
            reverse(all(pref));
            temp += pref;
            alpha = temp;
        }
        int cnt = 0;
        loop(i,0,s1.size()){
            string temp = s1[i];
            loop(j,0,temp.size()){
                if(temp[j]!=alpha[j]){
                    cnt++;
                }
            }
        }
        cout<<alpha<<endl;
        cout<<cnt<<endl;

    }
}
