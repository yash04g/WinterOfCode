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
    // cin >> t;
    while (t--){
        int n,m;
        cin>>n;
        vi a(n);
        int sum1=0,sum2=0;
        mii m1,m2;
        loop(i,0,n) cin>>a[i],sum1+=a[i],m1[a[i]]++;
        cin>>m;
        vi b(m);
        loop(i,0,m) cin>>b[i],sum2+=b[i],m2[b[i]]++;
        if(sum1!=sum2){
            cout<<-1<<endl;
            continue;
        }
        int len = 0;
        int i=0,j=0;
        sum1=0,sum2=0;
        int last1=-1,last2=-1;
        while(i<n && j<m){
            if(last1!=i){
                sum1 += a[i];
            }
            if(last2!=j){
                sum2 += b[j];
            }
            if(sum1==sum2){
                len++;
                last1=i;
                last2=j;
                i++;
                j++;
                
            }else if(sum1<sum2){
                last2 = j;
                i++;
            }else{
                last1 = i;
                j++;
            }
        }
        cout<<len<<endl;





    }
}
