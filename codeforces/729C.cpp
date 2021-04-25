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
ll fact[100005];
ll finv[100005];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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

    ll n,k,s,t;
    cin>>n>>k>>s>>t;
    pll car[n];
    for(ll i=0;i<n;i++)
        cin>>car[i].ss>>car[i].ff;
    ll g[k];
    for(ll i=0;i<k;i++)
        cin>>g[i];
    sort(g,g+k);
    //sort(car,car+n);
    vl v;
    v.pb(g[0]);
    for(ll i=1;i<k;i++)
        v.pb(g[i]-g[i-1]);
    v.pb(s-g[k-1]);
    sort(all(v));
    ll tacc=max(0,2*s-t);
    //tnorm=t-tacc;
    ll l=v.back(),r=v.back()*2,mfr;
    while(l<=r){
        ll mid=(l+r)/2;
        ll cacc=0;
        //cnorm=0;
        //bool b=true;
        for(ll i:v)
            cacc+=min(mid-i,i);
        if(cacc>=tacc)
            mfr=mid,r=mid-1;
        else
            l=mid+1;
    }
    //cout<<mfr<<'\n';
    ll ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        if(car[i].ff>=mfr)
            ans=min(ans,car[i].ss);
    }
    if(ans==LLONG_MAX)
        cout<<-1;
    else cout<<ans;
}