#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
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
 
bool primes[100001];
vector<int> ans;
 
int __gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return __gcd(b, a % b);  
      
} 
void sieve()
{
    memset(primes, 0, sizeof(primes));
    for (int i = 2; i <= 100000; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i * 2; j <= 100000; j += i)
            {
                primes[j] = 1;
            }
            if (i > 1000)
            {
                ans.push_back(i);
            }
        }
    }
}
 
int ans1[500][500];
 
int32_t main()
{
    get_it_done();
    int t=1;
    // cin >> t;
    sieve();
    while(t--){
    memset(ans1, 0, sizeof(ans1));
    int r, c;
    cin >> r >> c;
    if (c == 1)
    {
        if (r == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 2; i <= r + 1; i++)
            {
                cout << i << " ";
            }
        }
        return 0;
    }
    if (r == 1)
    {
        if (c == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 2; i <= c + 1; i++)
            {
                cout << i << endl;
            }
        }
        return 0;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans1[i][j] = ans[0];
        }
    }
    for (int i = 0; i < r; i++)
    {
        ans1[i][0] = ans[1];
    }
    ans1[r - 1][0] = ans[2];
    for (int i = 1; i < c; i++)
    {
        ans1[r - 1][i] = ans[1];
    }
    int co = 2;
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans1[i][j] *= co;
        }
        co++;
    }
    set<int> s;
    int maxi = 0;
    for (int i = 0; i < c; i++)
    {
       int fo = ans1[0][i] * co;
        for (int j = 0; j < r; j++)
        {
            ans1[j][i] *= co;
            fo = __gcd(fo, ans1[j][i]);
        }
        maxi = max(fo, maxi);
        s.insert(fo);
        co++;
    }
    for (int i = 0; i < r; i++)
    {
        int fo = ans1[i][0];
        for (int j = 0; j < c; j++)
        {
            cout << ans1[i][j] << " ";
            fo = __gcd(fo, ans1[i][j]);
        }
        maxi = max(fo, maxi);
        s.insert(fo);
        cout << endl;
    }
    }
}