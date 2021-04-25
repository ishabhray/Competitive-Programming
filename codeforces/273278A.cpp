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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}
ll fact[100010];
ll finv[100010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
    }
}
ll n,sum[4*MAXN],suff[4*MAXN],pref[4*MAXN],seg[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        sum[v]=a[tl],suff[v]=max(0,a[tl]),pref[v]=suff[v],seg[v]=suff[v];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        sum[v]=sum[v*2]+sum[v*2+1];
        suff[v]=max(suff[2*v+1],sum[2*v+1]+suff[2*v]);
        pref[v]=max(pref[2*v],sum[2*v]+pref[2*v+1]);
        seg[v]=max({seg[2*v],seg[2*v+1],suff[2*v]+pref[2*v+1]});
    }
}

void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        sum[v]=new_val,suff[v]=max(0,new_val),pref[v]=suff[v],seg[v]=suff[v];
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        sum[v]=sum[v*2]+sum[v*2+1];
        suff[v]=max(suff[2*v+1],sum[2*v+1]+suff[2*v]);
        pref[v]=max(pref[2*v],sum[2*v]+pref[2*v+1]);
        seg[v]=max({seg[2*v],seg[2*v+1],suff[2*v]+pref[2*v+1]});
    }
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
        int m;
        cin>>n>>m;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        cout<<seg[1]<<'\n';
        for(int i=0;i<m;i++){
            int y,z;
            cin>>y>>z;
            update(1,1,n,y+1,z);
            cout<<seg[1]<<'\n';
        }
    }
}