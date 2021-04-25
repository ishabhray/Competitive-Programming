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
ll fact[1001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=fact[r]*fact[n-r]%MOD;
        return fact[n]*fermat_inv(x)%MOD;
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

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        ii a[k];
        map<ii,int>pts;
        map<int,int>r,c;
        for(int i=0;i<k;i++){
            cin>>a[i].ff>>a[i].ss;
            pts[a[i]]++;
            r[a[i].ff]++;
            c[a[i].ss]++;
        }
        ll ans=0;
        int mx=0,my=0;
        vi ri,ci;
        for(auto a:r){
            if(a.ss>mx){
                mx=a.ss;
                ri.clear();
                ri.pb(a.ff);
            }
            else if(a.ss==mx)
                ri.pb(a.ff);
        }
        for(auto a:c){
            if(a.ss>my){
                my=a.ss;
                ci.clear();
                ci.pb(a.ff);
            }
            else if(a.ss==my)
                ci.pb(a.ff);
        }
        bool b=false;
        for(int i:ri){
            for(int j:ci){
                if(!pts[{i,j}]){
                    b=true;
                    break;
                }
            }
            if(b)
                break;
        }
        if(b)
            cout<<mx+my;
        else
            cout<<mx+my-1;
    }
}