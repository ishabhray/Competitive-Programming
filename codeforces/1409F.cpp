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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}


int n,k;
string s,t;
int dp[201][201][201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>k>>s>>t;
    for(int i=0;i<=200;i++)
        for(int j=0;j<=200;j++)
            for(int c=0;c<=200;c++)
                dp[i][j][c]=INT_MIN;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            for(int c=0;c<=n;c++){
                if(dp[i][j][c]<0)
                    continue;
                //cout<<i<<' '<<j<<' '<<c<<' '<<dp[i][j][c]<<'\n';
                dp[i+1][j][c+(s[i]==t[0])]=max(dp[i+1][j][c+(s[i]==t[0])],dp[i][j][c]+((s[i]==t[1])?c:0));
                dp[i+1][j+1][c+1]=max(dp[i+1][j+1][c+1],dp[i][j][c]+((t[0]==t[1])?c:0));
                dp[i+1][j+1][c+(t[0]==t[1])]=max(dp[i+1][j+1][c+(t[0]==t[1])],dp[i][j][c]+c);
            }
        }
    }
    ll ans=0;
    for(int j=0;j<=k;j++){
        for(int c=0;c<=n;c++){
            ans=max(ans,dp[n][j][c]);
        }
    }
    cout<<ans;
}