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

void dfs(ll i,ll j,vv<ii > adj[],ll vis[],ll cnt[])
{
    if(vis[i])
        return;
    vis[i]=1;
    ll c=0;
    for(auto a:adj[i]){
        dfs(a.ff,a.ss,adj,vis,cnt);
        c+=cnt[a.ss];
    }
    cnt[j]=(c)?c:1;
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
    cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        ll n,s;
        cin>>n>>s;
        vv<ii > adj[n+1];
        ll w[n],c[n];
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y>>w[i]>>c[i];
            adj[x].pb({y,i});
            adj[y].pb({x,i});
        }
        ll vis[n+1]={0};
        ll cnt[n]={0};
        dfs(1,0,adj,vis,cnt);
        ll sum=0;
        priority_queue<pair<ll,ll> >p,q;
        for(ll i=1;i<n;i++){
            if(c[i]==1)
                p.push({cnt[i]*(w[i]-w[i]/2),i});
            else
                q.push({cnt[i]*(w[i]-w[i]/2),i});
            sum+=cnt[i]*w[i];
        }
        vl x,y;
        x.pb(0);
        y.pb(0);
        while(!p.empty()){
            auto t=p.top();
            p.pop();
            w[t.ss]/=2;
            x.pb(x.back()+t.ff);
            if(cnt[t.ss]*(w[t.ss]-w[t.ss]/2))
            p.push({cnt[t.ss]*(w[t.ss]-w[t.ss]/2),t.ss});
        }
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            w[t.ss]/=2;
            y.pb(y.back()+t.ff);
            if(cnt[t.ss]*(w[t.ss]-w[t.ss]/2))
            q.push({cnt[t.ss]*(w[t.ss]-w[t.ss]/2),t.ss});
        }
        ll ans=INT_MAX;
        if(sum<=s){
            cout<<"0\n";
            continue;
        }
        for(ll i=0;i<x.size();i++){
            ll l=0,r=(ll)y.size()-1;
            while(l<=r){
                ll mid=(l+r)/2;
                if(sum-x[i]-y[mid]<=s)
                    ans=min(ans,i+2*mid),r=mid-1;
                else
                    l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
}