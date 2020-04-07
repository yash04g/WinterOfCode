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
int m = 998244353;
class Triplet{
public:
    int x;
    int y;
    int g;
};

Triplet extendedEuclid(int a,int b){
    if(b==0){
        Triplet ans;
        ans.g = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet temp = extendedEuclid(b,a%b);
    Triplet ans;
    ans.g = temp.g;
    ans.x = temp.y;
    ans.y = temp.x - (a/b)*temp.y;
    return ans;
}
int mmI(int a){
    deb(m);
    Triplet ans = extendedEuclid(a,m);
    return (ans.x+m)%m; 
}
int dp[4];

// int solve(string s){
//     int n = s.size();
//     // stack to store integer values. 
//     stack <int> values; 
      
//     // stack to store operators. 
//     stack <char> ops; 
      
//     loop(i,0,n){   
//         // Current token is an opening  
//         // brace, push it to 'ops' 
//         if(tokens[i] == '('){ 
//             ops.push(tokens[i]); 
//         } 
          
//         // Current token is a number, push  
//         // it to stack for numbers. 
//         else if(s[i]=='#'){ 
//             int val = 0; 
//             values.push(s[i]);
//         } 
//         else if(tokens[i] == ')') { 
//             while(!ops.empty() && ops.top() != '('){ 
//                 int val2 = values.top(); 
//                 values.pop(); 
                  
//                 int val1 = values.top(); 
//                 values.pop(); 
                  
//                 char op = ops.top(); 
//                 ops.pop(); 
                  
//                 values.push(applyOp(val1, val2, op)); 
//             } 
              
//             // pop opening brace. 
//             if(!ops.empty()) 
//                ops.pop(); 
//         } 
          
//         // Current token is an operator. 
//         else
//         { 
//             // While top of 'ops' has same or greater  
//             // precedence to current token, which 
//             // is an operator. Apply operator on top  
//             // of 'ops' to top two elements in values stack. 
//             while(!ops.empty() && precedence(ops.top()) 
//                                 >= precedence(tokens[i])){ 
//                 int val2 = values.top(); 
//                 values.pop(); 
                  
//                 int val1 = values.top(); 
//                 values.pop(); 
                  
//                 char op = ops.top(); 
//                 ops.pop(); 
                  
//                 values.push(applyOp(val1, val2, op)); 
//             } 
              
//             // Push current token to 'ops'. 
//             ops.push(tokens[i]); 
//         } 
//     } 
      
//     // Entire expression has been parsed at this 
//     // point, apply remaining ops to remaining 
//     // values. 
//     while(!ops.empty()){ 
//         int val2 = values.top(); 
//         values.pop(); 
                  
//         int val1 = values.top(); 
//         values.pop(); 
                  
//         char op = ops.top(); 
//         ops.pop(); 
                  
//         values.push(applyOp(val1, val2, op)); 
//     } 
      
//     // Top of 'values' contains result, return it. 
//     return values.top(); 
// }

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        string s;
        cin>>s;
        int n = s.size();
        if(n==1){
            int ans = 1*mmI(16);
            cout<<ans<<" "<<ans<<" "<<ans<<" "<<ans<<endl;
            continue;
        }
        // cout<<solve(s);       
        
    }
}
