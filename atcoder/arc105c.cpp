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
        ll n,m;
        cin>>n>>m;
        ll w[n];
        for(ll i=0;i<n;i++)
            cin>>w[i];
        ii a[m];
        for(ll i=0;i<m;i++)
            cin>>a[i].ff>>a[i].ss;
        bool ans=true;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(w[i]>a[j].ss)
                    ans=false;
            }
        }
        if(!ans){
            cout<<"-1";
            return 0;
        }
        ll mindis[n][n];
        memset(mindis,0,sizeof(mindis));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<m;k++){
                    if(w[i]+w[j]>a[k].ss)
                        mindis[i][j]=max(mindis[i][j],a[k].ff);
                }
            }
        }
        ll perm[n];
        for(ll i=0;i<n;i++)
            perm[i]=i;
        ll mn=LLONG_MAX;
        do{
            ll dis[n]={0};
            for(ll i=0;i<n;i++){
                for(ll j=i-1;j>=0;j--){
                    dis[i]=max(dis[j]+mindis[perm[i]][perm[j]],dis[i]);
                }
            }
            mn=min(mn,dis[n-1]);
        }while(next_permutation(perm,perm+n));
        cout<<mn;
    }
}