#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll maxi = pow(10,n);
        ll a;
        cin>>a;
        ll sum = 2*maxi+a;
        cout<<sum<<endl;
        ll b;
        cin>>b;
        ll c = maxi-b;
        cout<<c<<endl;
        ll d;
        cin>>d;
        ll e = maxi-d;
        cout<<e<<endl;
        ll flag;
        cin>>flag;
        if(flag==-1){
            exit(0);    
        }
    }
}