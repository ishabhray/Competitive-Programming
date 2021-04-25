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

ll check(vi v,ll c[],int k)
{
    int l=v.size();
    ll x=k/l,y=k%l;
    ll sum=0;
    for(int i:v)
        sum+=c[i];
    ll a[l+1];
    a[0]=0;
    for(int i=0;i<l;i++)
        v.pb(v[i]);
    for(int i=1;i<=l;i++){
        ll s=0;
        for(int j=0;j<i;j++)
            s+=c[v[j]];
        a[i]=s;
        for(int j=1;j<l;j++)
            s+=c[v[j+i-1]]-c[v[j-1]],a[i]=max(a[i],s);
    }
    ll ans=LLONG_MIN;
    if(!x||sum<=0){
        for(int i=1;i<=min(l,k);i++)
            ans=max(ans,a[i]);
    }
    else if(sum>0){
        ans=x*sum;
        for(int i=1;i<=l;i++){
            if(i<=y)
                ans=max(ans,x*sum+a[i]);
            else
                ans=max(ans,(x-1)*sum+a[i]);
        }
    }
    return ans;
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
        int n,k;
        cin>>n>>k;
        int p[n+1];
        ll c[n+1];
        for(int i=1;i<=n;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++)
            cin>>c[i];
        ll ans=LLONG_MIN;
        int vis[n+1]={0};
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            vis[i]=1;
            int j=p[i];
            vi v;
            v.pb(i);
            while(!vis[j]){
                v.pb(j);
                vis[j]=1;
                j=p[j];
            }
            ans=max(ans,check(v,c,k));
        }
        cout<<ans<<'\n';
    }
}
