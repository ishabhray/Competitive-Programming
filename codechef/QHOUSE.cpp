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

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        ll l=0,r=1000,ymax,x,xmax;
        string s;
        while(l<=r){
            ll mid=(l+r)/2;
            cout<<"? 0 "<<mid<<endl;
            cin>>s;
            if(s=="YES")
                l=mid+1,ymax=mid;
            else
                r=mid-1;
        }
        l=0,r=1000;
        while(l<=r){
            ll mid=(l+r)/2;
            cout<<"? "<<mid<<" 0"<<endl;
            cin>>s;
            if(s=="YES")
                l=mid+1,x=mid;
            else
                r=mid-1;
        }
        l=0,r=1000;
        while(l<=r){
            ll mid=(l+r)/2;
            cout<<"? "<<mid<<" "<<2*x<<endl;
            cin>>s;
            if(s=="YES")
                l=mid+1,xmax=mid;
            else
                r=mid-1;
        }
        ll ans=xmax*(ymax-2*x)+4*x*x;
        cout<<"! "<<ans<<endl;
        return 0;
    }
}