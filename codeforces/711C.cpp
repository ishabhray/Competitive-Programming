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
#define MAX 1e18
int MOD=1e9+7;

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

ll dp[105][105][105],n,m,k,c[105],cost[105][105];
ll ans=-1;

ll solve(ll i,ll pre,ll cnt)
{
    //cout<<i<<' '<<pre<<' '<<cnt<<'\n';
    if(dp[i][pre][cnt]!=-1)
        return dp[i][pre][cnt];
    if(i==0&&cnt==0)
        return dp[i][pre][cnt]=0;
    else if(!i)
        return dp[i][pre][cnt]=MAX;
    ll ans=MAX;
    if(i==n){
        if(c[i]){
            ans=solve(i-1,c[i],cnt-1);
        }
        else{
            for(int j=1;j<=m;j++)
                ans=min(ans,cost[i][j]+solve(i-1,j,cnt-1));
        }
        return dp[i][pre][cnt]=ans;
    }
    if(c[i]==pre)
        ans=solve(i-1,pre,cnt);
    else if(c[i])
        ans=solve(i-1,c[i],cnt-1);
    else{
        for(int j=1;j<=m;j++){
            if(j==pre)
                ans=min(ans,cost[i][j]+solve(i-1,pre,cnt));
            else
                ans=min(ans,cost[i][j]+solve(i-1,j,cnt-1));
        }
    }
    return dp[i][pre][cnt]=ans;
}

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
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>c[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>cost[i][j];
        memset(dp,-1,sizeof(dp));
        ll ans=MAX;
        ans=min(ans,solve(n,-1,k));
        cout<<((ans<MAX)?ans:-1);
    }
}