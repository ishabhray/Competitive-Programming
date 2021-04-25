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
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size(),m=s2.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/
    int i=n,j=m;
    while(i>0&&j>0){
        if(dp[i-1][j]!=dp[i][j]&&dp[i][j-1]!=dp[i][j])
            ans=s1[i-1]+ans,i--,j--;
        else if(dp[i-1][j]==dp[i][j])
            i--;
        else
            j--;
    }
    cout<<ans;
}