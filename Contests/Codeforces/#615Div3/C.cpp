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
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N];
map<int,int> m;

void factorize(int n){ 
    int count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n /=2;    // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count){
        m[2] = count;
    } 
  
    // check for all the possible numbers that can  
    // divide it 
    for (int i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            m[i] = count;
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
        m[n] = 1;
} 

int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        m.clear();
        factorize(n);
        // cout<<m.size()<<endl;
        if(m.size()==1){
            bool flag = 1;
            int num1 = 1;
            for(auto x:m){
                if(x.second<=5){
                    flag = false;
                }
                num1 = x.ff;
            }
            int num2 = num1*num1;
            int num3 = n/(num2*num1);
            if(flag){
                cout<<"YES"<<endl;
                cout<<num1<<" "<<num2<<" "<<num3<<endl;

            }else{
                cout<<"NO"<<endl;
            }
        }else if(m.size()==2){
            int num1 = 1;
            int num2 = 1;
            int num3 = 1;
            for(auto x:m){
                if(num1==1){
                    num1 = x.ff;
                }else{
                    num2 = x.ff;
                }
            }
            num3 = n/(num1*num2);
            if(num3==num1 || num3==num2 || num3==1){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
                cout<<num1<<" "<<num2<<" "<<num3<<endl;
            }
        }else{
            cout<<"YES"<<endl;
            int num1 = 1;
            int num2 = 1;
            int num3 = 1;
            for(auto x:m){
                if(num1==1){
                    num1 = x.ff;
                }else{
                    if(num2==1){
                        num2 = x.ff;
                    }else{
                        break;
                    }
                }
            }
            num3 = n/(num2*num1);
            cout<<num1<<" "<<num2<<" "<<num3<<endl;

        }


    }
}
