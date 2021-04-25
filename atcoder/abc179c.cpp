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
int prime[1000001];

void SieveOfEratosthenes(int n) 
{ 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p] == 0) 
        { 
            for (int i=p; i<=n; i += p) 
                prime[i] = p; 
        } 
    } 
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
    SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        ll n;
        cin>>n;
        ll ans=0;
        for(ll i=1;i<n;i++){
            ll y=i;
            ll cnt=1;
            ll j=prime[y];
            //cout<<j<<'\n';
            while(y>1&&j>1){
                ll c=0;
                while(y%j==0)
                    y/=j,c++;
                cnt*=(c+1);
                j=prime[y];
            }
            ans+=cnt;
        }
        cout<<ans;
    }
}