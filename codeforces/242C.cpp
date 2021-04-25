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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int x0,y0,x1,y1;
        cin>>x0>>y0>>x1>>y1;
        int n;
        cin>>n;
        pair<int,ii >seg[n];
        map<ii,int> allow,vis;
        for(int i=0;i<n;i++)
            cin>>seg[i].ff>>seg[i].ss.ff>>seg[i].ss.ss;
        for(int i=0;i<n;i++)
            for(int j=seg[i].ss.ff;j<=seg[i].ss.ss;j++)
                allow[{seg[i].ff,j}]=1;
        bool ans=false;
        queue<pair<ii,int> >q;
        q.push({{x0,y0},0});
        vis[{x0,y0}]=1;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.ff.ff,y=a.ff.ss,r=a.ss;
            if(x==x1&&y==y1){
                ans=true;
                cout<<r;
                break;
            }
            if(allow[{x+1,y}]&&!vis[{x+1,y}]){
                q.push({{x+1,y},r+1});
                vis[{x+1,y}]=1;
            }
            if(allow[{x-1,y}]&&!vis[{x-1,y}]){
                q.push({{x-1,y},r+1});
                vis[{x-1,y}]=1;
            }
            if(allow[{x,y+1}]&&!vis[{x,y+1}]){
                q.push({{x,y+1},r+1});
                vis[{x,y+1}]=1;
            }
            if(allow[{x,y-1}]&&!vis[{x,y-1}]){
                q.push({{x,y-1},r+1});
                vis[{x,y-1}]=1;
            }
            if(allow[{x+1,y+1}]&&!vis[{x+1,y+1}]){
                q.push({{x+1,y+1},r+1});
                vis[{x+1,y+1}]=1;
            }
            if(allow[{x-1,y+1}]&&!vis[{x-1,y+1}]){
                q.push({{x-1,y+1},r+1});
                vis[{x-1,y+1}]=1;
            }
            if(allow[{x+1,y-1}]&&!vis[{x+1,y-1}]){
                q.push({{x+1,y-1},r+1});
                vis[{x+1,y-1}]=1;
            }
            if(allow[{x-1,y-1}]&&!vis[{x-1,y-1}]){
                q.push({{x-1,y-1},r+1});
                vis[{x-1,y-1}]=1;
            }
        }
        if(!ans)
            cout<<-1;
    }
}