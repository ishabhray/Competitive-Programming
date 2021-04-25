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

ll dp[5005][5005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n],b[n],c[n];
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];
        int adj[n];
        for(int i=0;i<n;i++)
            adj[i]=i;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[v]=max(adj[v],u);
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=5000;j++)
                dp[i][j]=-1e9;
        dp[0][k]=0;
        for(int i=0;i<n;i++){
            vi v;
            for(int j=0;j<n;j++)
                if(adj[j]==i)
                    v.pb(c[j]);
            sort(all(v),greater<int>());
            for(int j=0;j<=5000;j++){
                if(j>=a[i]&&dp[i][j]>=0){
                    dp[i+1][j+b[i]]=max(dp[i+1][j+b[i]],dp[i][j]);
                }
            }
            for(int k:v){
                for(int j=1;j<=5000;j++){
                    if(dp[i+1][j]>=0){
                        dp[i+1][j-1]=max(dp[i+1][j-1],dp[i+1][j]+k);
                    }
                }
            }
        }
        int mx=-1;
        for(int i=0;i<=5000;i++)
            mx=max(mx,dp[n][i]);
        cout<<mx;
    }
}