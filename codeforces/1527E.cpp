#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll int
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
ll t[4*MAXN],lazy[4*MAXN],dp[MAXN];
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v]=dp[tl],lazy[v]=0;
    else{
        ll tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=min(t[v*2],t[v*2+1]);
        lazy[v]=0;
    }
}
void push(ll v,ll l,ll r){
    ll tm=(l+r)/2;
    t[2*v]+=lazy[v];
    t[2*v+1]+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 1e18;
    if(l==tl&&r==tr)
        return t[v];
    push(v,tl,tr);
    ll tm=(tl+tr)/2;
    return min(sum(2*v,tl,tm,l,min(r,tm)),sum(2*v+1,tm+1,tr,max(l,tm+1),r));
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]+=new_val;
        lazy[v]+=new_val;
    }
    else{
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,k;
        cin>>n>>k;
        int a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        int last[n+5];
        for(int c=1;c<=k;c++){
            memset(last,-1,sizeof(last));
            for(int i=1;i<=n;i++){
                if(last[a[i]]!=-1) update(1,1,n,1,last[a[i]]-1,i-last[a[i]]);
                if(i!=1){
                    if(c==1) dp[i]=dp[i-1]+((last[a[i]]!=-1)?i-last[a[i]]:0);
                    else{
                        dp[i]=sum(1,1,n,1,i-1);
                    }
                }
                last[a[i]]=i;
            }
            // for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
            // cout<<'\n';
            // for(int i=1;i<=n;i++){
            //     int s=sum(1,1,n,i,i);
            //     update(1,1,n,i,i,dp[i]-s);
            // }
            // for(int i=1;i<=n;i++) cout<<sum(1,1,n,i,i)<<' ';
            // cout<<'\n';
            build(1,1,n);
        }
        cout<<dp[n]<<'\n';
    }
}