#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int k;
	while(1){
		cin>>k;
		if(!k)
			return 0;
	    int n,m;
	    string a,b;
	    cin>>a>>b;
	    n=a.size(),m=b.size();
	    int dp[n][m],dp1[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(a[i]==b[j])
	            dp[i][j]=1+((i>0&&j>0)?dp[i-1][j-1]:0);
	            else
	            dp[i][j]=0;
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	        	dp1[i][j]=0;
	            cout<<dp[i][j]<<' ';
	        }
	        cout<<'\n';
	    }
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(dp[i][j]==k)
	    			dp1[i][j]=dp[i][j]+((i-dp[i][j]>=0&&j-dp[i][j]>=0)?dp1[i-dp[i][j]][j-dp[i][j]]:0);
	    		else if(dp[i][j]>k)
	    			dp1[i][j]=max(dp[i][j]+((i-dp[i][j]>=0&&j-dp[i][j]>=0)?dp1[i-dp[i][j]][j-dp[i][j]]:0),((i-1>=0&&j-1>=0)?dp[i-1][j-1]:0));
	    		else
	    			dp1[i][j]=max(((i>=1)?dp1[i-1][j]:0),((j>=1)?dp1[i][j-1]:0));
	    	}
	    }
	    int mx=0;
	    cout<<"*************\n";
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<dp1[i][j]<<' ';
	            mx=max(mx,dp1[i][j]);
	        }
	        cout<<'\n';
	    }
	    cout<<"*************\n";
	    cout<<mx<<'\n';
	}
	return 0;
}