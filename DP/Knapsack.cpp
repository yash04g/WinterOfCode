#include<bits/stdc++.h>
using namespace std;

int knapsack(int* values, int* weights,int maxWeight,int n){
    int dp[2][10005]={-1};
    for(int i=0;i<=maxWeight;i++){
        dp[0][i] = 0;
    }
    int flag = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            dp[flag][j] = dp[flag^1][j];
            if(weights[i-1]<=j){
                dp[flag][j] = max(dp[flag][j],values[i-1]+dp[flag^1][j-weights[i-1]]);
            }
        }
        flag = flag^1;
    }
    return dp[flag^1][maxWeight];
}

int main(){
	
	int val[] = {5,4,8,6};
	int wt[] = {1,2,3,5};

	int W = 5;
	int n = 4;

	cout << knapsack(val,wt,W,n)<<endl;
}
