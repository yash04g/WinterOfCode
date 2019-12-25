#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pll pair<int,int>
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
const int N = 2e5+5;
int dp[N];
class node{
	int idx,skill;
	node *next,*prev;
};


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n,k;
    	cin>>n>>k;
    	node *head = new node;
    	node *last = NULL;
    	set<pair<int,node*> > s;
    	int x;
    	cin>>x;
    	head->idx = 1;
    	head->skill=x;
    	head->prev=last;
    	node *tail = head;
    	s.insert(mp(x,head));
    	for(int i=2;i<=n;++i){
        	int sk; cin>>sk;
        	node *cur = new node;
        	tail->next = cur;
        	cur->prev = tail;
        	cur->idx = i;
        	cur->skill = sk;
        	tail=cur;
        	s.insert(mp(sk,cur));
    	}
    	tail->next=NULL;
    	
 

    }
}
