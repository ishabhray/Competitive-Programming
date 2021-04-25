#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)
                dp[0][0]=a[0][0];
            else if(i==0)
                dp[i][j]=dp[i][j-1]+a[i][j];
            else if(j==0)
                dp[i][j]=dp[i-1][j]+a[i][j];
            else
                dp[i][j]=a[i][j]+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
}