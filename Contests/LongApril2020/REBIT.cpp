// Reference => https://www.geeksforgeeks.org/expression-tree/
// YASH GUPTA
// DELHI TECHNOLOGICAL UNIVERSITY
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
const int m = 998244353;
string s;
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
    Triplet ans = extendedEuclid(a,m);
    return (ans.x+m)%m; 
}

class Node{
public:
    Node *left;
    Node *right;
    char c;
    Node(){
        left = NULL;
        right = NULL;
    }
};

stack<Node*> build(){
    stack<Node*> s1;
    loop(i,0,s.size()){
        if(s[i] != ')'){
            Node *newNode = new Node;
            newNode->c = s[i];
            s1.push(newNode);
        }
        else{
            Node *t1 = s1.top();
            // deb(t1->c); 
            s1.pop();
            Node *t = s1.top();
            // deb(t->c);
            s1.pop();
            Node *t2 = s1.top(); 
            // deb(t2->c);
            s1.pop();
            // deb((s1.top())->c);
            s1.pop();
            t->left = t2;
            t->right = t1;
            s1.push(t);
        }
    }
    return s1;
}

vi solve(Node *root){
    vi dp;
    if(!(root->left) && !(root->right)){
        int val = mmI(4);
        dp.pb(val);
        dp.pb(val);
        dp.pb(val);
        dp.pb(val);
        return dp;
    }
    vi leftChild = solve(root->left);
    vi rightChild = solve(root->right);
    int val0 = 0;
    int val1 = 0;
    int vala = 0;
    int valA = 0;
    if(root->c=='^'){
        val0 += (leftChild[0]*rightChild[0])%m;
        val0 %= m;
        val0 += (leftChild[1]*rightChild[1])%m;
        val0 %= m;
        val0 += (leftChild[2]*rightChild[2])%m;
        val0 %= m;
        val0 += (leftChild[3]*rightChild[3])%m;
        val0 %= m;
        val1 += (leftChild[0]*rightChild[1])%m;
        val1 %= m;
        val1 += (leftChild[1]*rightChild[0])%m;
        val1 %= m;
        val1 += (leftChild[2]*rightChild[3])%m;
        val1 %= m;
        val1 += (leftChild[3]*rightChild[2])%m;
        val1 %= m;
        vala += (leftChild[0]*rightChild[2])%m;
        vala %= m;
        vala += (leftChild[2]*rightChild[0])%m;
        vala %= m;
        vala += (leftChild[3]*rightChild[1])%m;
        vala %= m;
        vala += (leftChild[1]*rightChild[3])%m;
        vala %= m;
        valA += (leftChild[0]*rightChild[3])%m;
        valA %= m;
        valA += (leftChild[3]*rightChild[0])%m;
        valA %= m;
        valA += (leftChild[2]*rightChild[1])%m;
        valA %= m;
        valA += (leftChild[1]*rightChild[2])%m;
        valA %= m;
    }else if(root->c=='|'){
        val0 += (leftChild[0]*rightChild[0])%m;
        val0 %= m;
        val1 += (leftChild[1]*rightChild[1])%m;
        val1 %= m;
        val1 += (leftChild[1]*rightChild[2])%m;
        val1 %= m;
        val1 += (leftChild[2]*rightChild[1])%m;
        val1 %= m;
        val1 += (leftChild[1]*rightChild[3])%m;
        val1 %= m;
        val1 += (leftChild[3]*rightChild[1])%m;
        val1 %= m;
        val1 += (leftChild[0]*rightChild[1])%m;
        val1 %= m;
        val1 += (leftChild[1]*rightChild[0])%m;
        val1 %= m;
        val1 += (leftChild[2]*rightChild[3])%m;
        val1 %= m;
        val1 += (leftChild[3]*rightChild[2])%m;
        val1 %= m;
        vala += (leftChild[0]*rightChild[2])%m;
        vala %= m;
        vala += (leftChild[2]*rightChild[0])%m;
        vala %= m;
        vala += (leftChild[2]*rightChild[2])%m;
        vala %= m;
        valA += (leftChild[0]*rightChild[3])%m;
        valA %= m;
        valA += (leftChild[3]*rightChild[0])%m;
        valA %= m;
        valA += (leftChild[3]*rightChild[3])%m; 
        valA %= m;
    }else{
        val0 += (leftChild[0]*rightChild[0])%m; 
        val0 %= m;
        val0 += (leftChild[0]*rightChild[1])%m;
        val0 %= m;
        val0 += (leftChild[1]*rightChild[0])%m;
        val0 %= m;
        val0 += (leftChild[0]*rightChild[2])%m;
        val0 %= m;
        val0 += (leftChild[2]*rightChild[0])%m;
        val0 %= m;
        val0 += (leftChild[3]*rightChild[0])%m;
        val0 %= m;
        val0 += (leftChild[0]*rightChild[3])%m;
        val0 %= m;
        val0 += (leftChild[2]*rightChild[3])%m;
        val0 %= m;
        val0 += (leftChild[3]*rightChild[2])%m;
        val0 %= m;
        val1 += (leftChild[1]*rightChild[1])%m;
        val1 %= m;
        vala += (leftChild[1]*rightChild[2])%m;
        vala %= m;
        vala += (leftChild[2]*rightChild[1])%m;
        vala %= m;
        vala += (leftChild[2]*rightChild[2])%m;
        vala %= m;
        valA += (leftChild[1]*rightChild[3])%m;
        valA %= m;
        valA += (leftChild[3]*rightChild[1])%m;
        valA %= m;
        valA += (leftChild[3]*rightChild[3])%m;
        valA %= m;
    }
    dp.pb(val0);
    dp.pb(val1);
    dp.pb(vala);
    dp.pb(valA);
    return dp;
}

int32_t main(){
    get_it_done();
    int q=1;
    cin >> q;
    while (q--){
        cin>>s;
        stack<Node*> tree = build();
        Node* root = tree.top();
        tree.pop();
        vi dp = solve(root);
        loop(i,0,4){
            if(i==3){
                cout<<dp[3]<<endl;
                break;
            }
            cout<<dp[i]<<" ";
        }
    }
}
