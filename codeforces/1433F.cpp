#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    while(te--){
        int n,m,k;
        cin>>n>>m>>k;
        int a[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        int dp[n][k];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            int dp1[k][m/2+1];
            memset(dp1,-1,sizeof(dp1));
            dp1[0][0]=0;
            for(int j=0;j<m;j++){
                int dp2[k][m/2+1];
                for(int x=0;x<k;x++)
                    for(int y=0;y<=m/2;y++)
                        dp2[x][y]=dp1[x][y];
                for(int x=0;x<k;x++){
                    for(int y=0;y<m/2;y++){
                        if(dp1[x][y]==-1)
                            continue;
                        dp2[(x+a[i][j])%k][y+1]=max(dp2[(x+a[i][j])%k][y+1],dp1[x][y]+a[i][j]);
                    }
                }
                for(int x=0;x<k;x++)
                    for(int y=0;y<=m/2;y++)
                        dp1[x][y]=dp2[x][y];
            }
            for(int j=0;j<k;j++){
                for(int x=0;x<=m/2;x++)
                dp[i][j]=max(dp[i][j],dp1[j][x]);
            }
        }
        int dp1[n][k];
        memset(dp1,-1,sizeof(dp1));
        for(int i=0;i<k;i++)
            dp1[0][i]=dp[0][i];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<k;j++){
                if(dp1[i][j]==-1)
                    continue;
                for(int x=0;x<k;x++){
                    if(dp[i+1][x]==-1)
                        continue;
                    dp1[i+1][(x+j)%k]=max(dp1[i+1][(x+j)%k],dp1[i][j]+dp[i+1][x]);
                }
            }
        }
        cout<<dp1[n-1][0]<<'\n';
    }
}