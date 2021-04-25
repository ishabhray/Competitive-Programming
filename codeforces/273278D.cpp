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
int n,t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=max(t[v*2],t[v*2+1]);
    }
}
int find(int v,int tl,int tr,int x,int l){
    if(t[v]<x)
        return 1e6;
    if(tl==tr)
        return tl;
    int tm=(tl+tr)/2;
    if(l==tl){
        if(t[2*v]<x)
            return find(2*v+1,tm+1,tr,x,tm+1);
        else
            return find(2*v,tl,tm,x,tl);
    }
    else if(l<=tm){
        return min(find(2*v+1,tm+1,tr,x,tm+1),find(2*v,tl,tm,x,l));
    }
    else
        return find(2*v+1,tm+1,tr,x,l);
}

void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=max(t[2*v],t[2*v+1]);
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
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(x==1){
                int y,z;
                cin>>y>>z;
                update(1,1,n,y+1,z);
            }
            if(x==2){
                int y,z;
                cin>>y>>z;
                int r=find(1,1,n,y,z+1);
                if(r==1e6)
                    r=0;
                cout<<r-1<<'\n';
            }
        }
    }
}