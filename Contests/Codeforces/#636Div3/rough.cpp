#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long int
const int N = 1e5+5;

int32_t main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		vector<int> v(n+1);

		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}

		vector<int> sum(n/2+1,0);
		vector<int> high(n/2+1);
		vector<int> low(n/2+1);
		int minhigh=0,maxlow=2*k;
		for(int i=1;i<=n/2;i++)
		{
			sum[i] = v[i] + v[n-i+1];
			high[i] = max(v[i],v[n-i+1]) + k;
			maxlow = min(high[i],maxlow);
			low[i] = min(v[i],v[n-i+1]) + 1;
			minhigh = max(minhigh,low[i]);
		}

		vector<int> freq(2*k+1,0);

		for(int i=1;i<=n/2;i++)
		{
			if(sum[i]>=minhigh&&sum[i]<=maxlow)
			{
				freq[sum[i]]++;
			}
		}
		int ans = 0;
		cout<<minhigh<<"    "<<maxlow<<endl;
		for(int i=minhigh;i<=maxlow;i++)
		{
			ans = max(ans,freq[i]);
		}

		ans = n/2-ans;
		cout<<ans<<endl;




	}

}