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

bool isBeautiful(string s,int k){
	int n = s.size();
	if(k==1){
		fo(i,n-1){
			if(s[i]!=s[i+1]){
				return false;
			}
		}
	}
	
	int n1 = s.size()/k;
	fo(i,n1){
		fo(j,k){
			if(s[i]!=s[k+j] && (k+j)<n){
				return false;
			}
		}
	}
	
	int y = n%k;
	fo(i,y){
		if(s[i]!=s[i+(n-y)]){
			// cout<<<<endl;
			return false;
		}
	}
	return true;

}

int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	if(isBeautiful(s,k)){
    		cout<<n<<endl;
    		cout<<s<<endl;
    		continue;
    	}
    	// cout<<"fuck";
    	string temp = "";
    	fo(i,k){
    		temp.pb(s[i]);
    	}
    	int x = n/k;
    	bool flag = true;
    	if(n>2*k){
    		fo(i,k,2*k){
    			if(s[i]!=temp[i-k]){
    				flag = false;
    			}
    		}
    	}
    	if(flag){
    		string ans = "";
    		ans += temp;
    		flag = true;
    		string temp1 = "";
    		int idx1 = -1;
    		fo(i,n/k){
    			fo(j,k){
    				int idx = k*i;
    				if(s[j]!=s[idx]){
    					flag = false;
    					idx1 = idx;
    				}
    			}
    		}
    		if(!flag){
    			Fo(i,idx1,idx1+k){
    				temp1 += s[i];
    			}
    			fo(i,k){
    				if((temp1[i]-'0')>(s[i]-'0')){
    					break;
    				}
    			}
			}


    	}
    	string ans = "";
    	if(s[k-1]!='9'){
    		fo(i,k-1){
    			ans.pb(s[i]);
    		}
    		char x = (s[k-1]-'0'+1)+'0';
    		ans.pb(x);
    		string temp = ans;
    		int n1 = n/k;
    		Fo(i,1,n1){
    			ans += temp;
    		}
    		int y = n%k;
    		fo(i,y){
    			ans.pb(temp[i]);
    		}
    		cout<<ans.size()<<endl;
    		cout<<ans<<endl;
    	}else{
    		int j = k-1;
    		while(1){
    			if(s[j]!='9'){
    				break;
    			}
    			j--;
    		}
    		fo(i,j){
    			ans.pb(s[i]);
    		}
    		char x = (s[j]-'0'+1)+'0';
    		ans.pb(x);
    		Fo(i,j,k-1){
    			ans.pb('0');
    		}
    		string temp = ans;
    		int n1 = n/k;
    		Fo(i,1,n1){
    			ans += temp;
    		}
    		int y = n%k;
    		fo(i,y){
    			ans.pb(temp[i]);
    		}
    		cout<<ans.size()<<endl;
    		cout<<ans<<endl;
    	}
    }
}
