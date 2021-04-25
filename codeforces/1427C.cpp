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
        ll r,n;
        cin>>r>>n;
        ll t[n+1],x[n+1],y[n+1];
        t[0]=0,x[0]=1,y[0]=1;
        for(ll i=1;i<=n;i++)
            cin>>t[i]>>x[i]>>y[i];
        ll pre[n+1]={0};
        ll dp[n+1]={0};
        dp[0]=0,pre[0]=0;
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll mx=0;
            for(ll j=i-1;j>=0;j--){
                if(t[i]-t[j]>=2*r){
                    mx=max(mx,pre[j]+1);
                    break;
                }
                if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
                    if(dp[j]!=0||j==0)
                    mx=max(mx,dp[j]+1);
                }
            }
            dp[i]=mx;
            pre[i]=mx;
            pre[i]=max(pre[i-1],pre[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans;
    }
}