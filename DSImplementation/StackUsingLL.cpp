#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

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
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class Stack{
    Node *head;
    int sz;
    public:
    Stack(){
        head = NULL;
        sz = 0;
    }
    void push(int x){
        Node *newNode = new Node(x);
        if(!head){
            head = newNode;
            head->next = NULL;
        }else{
            newNode->next = head;
            head = newNode;
        }
        sz++;
        return;
    }
    int pop(){
        if(isEmpty()) return 0;
        sz--;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        int num = temp->data;
        delete temp;
        return num;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        return sz==0;
    }
    int top(){
        return head->data;
    }    
};


void solve(){
    Stack st;
    st.push(10);    
    st.push(20);
    st.push(30);
    cout<<st.pop()<<endl;
    cout<<st.size()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;    
    cout<<st.isEmpty()<<endl;
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
}

int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
