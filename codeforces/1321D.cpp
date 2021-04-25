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
    prime[0]=prime[1]=0;
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
        int n,m;
        cin>>n>>m;
        vi adj[n+1],adj1[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[v].pb(u);
            adj1[u].pb(v);
        }
        int k;
        cin>>k;
        int p[k];
        for(int i=0;i<k;i++)
            cin>>p[i];
        queue<int>q;
        int dist[n+1];
        for(int i=0;i<=n;i++)
            dist[i]=1e8;
        q.push(p[k-1]);
        dist[p[k-1]]=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int i:adj[a]){
                if(dist[i]<=dist[a]+1)
                    continue;
                dist[i]=dist[a]+1;
                q.push(i);
            }
        }
        int mn=0,mx=0;
        for(int i=0;i<k-1;i++){
            int d=dist[p[i+1]];
            int cnt1=0,cnt2=0;
            for(int j:adj1[p[i]]){
                if(j==p[i+1])
                    continue;
                if(dist[j]<d)
                    cnt1++;
                else if(dist[j]==d)
                    cnt2++;
            }
            //cout<<p[i]<<' '<<d<<' '<<cnt1<<' '<<cnt2<<'\n';
            if(cnt1)
                mn++;
            else if(cnt2)
                mx++;
        }
        cout<<mn<<' '<<mx+mn;
    }
}