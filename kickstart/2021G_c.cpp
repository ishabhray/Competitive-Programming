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
#define MAXN 300005
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
vl dp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    cin>>te;
    for(int T=1;T<=te;T++){
        ll n,k;
        cin>>n>>k;
        dp.assign(k+5,1e9);
        dp[0]=0;
        ll a[n+1],pre[n+1]={0};
        for(int i=0;i<n;i++) cin>>a[i+1];
        for(int i=1;i<=n;i++) pre[i]+=a[i]+pre[i-1];
        ll ans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(pre[i-1]-pre[j-1]<=k)
                dp[pre[i-1]-pre[j-1]]=min(dp[pre[i-1]-pre[j-1]],i-j);
            }
            for(int j=i;j<=n;j++){
                if(pre[j]-pre[i-1]<=k) ans=min(ans,j-i+1+dp[k-pre[j]+pre[i-1]]);
            }
        }
        if(ans==1e9) ans=-1;
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}