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
ll fact[1000010];
ll finv[1000010];
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
void dfs(int a,vi adj[],vi words[],set<int>dp[],set<int>dp1[],int leafcnt[]){
    map<int,int>dpc;
    int x=adj[a].size();
    if(x==0){
        for(int i:words[a]) dp[a].insert(i);
        leafcnt[a]=1;
        return;
    }
    map<int,ll>lmao;
    ll tot=0;
    for(int i:adj[a]){
        tot+=i;
        dfs(i,adj,words,dp,dp1,leafcnt);
        leafcnt[a]+=leafcnt[i];
        for(int j:dp[i]) dpc[j]++,lmao[j]+=i;
    }
    if(x==1) swap(dp1[a],dp1[adj[a][0]]);
    for(auto i:dpc){
        if(i.ss==x) dp[a].insert(i.ff);
        else if(i.ss==x-1){
            ll miss=tot-lmao[i.ff];
            if(leafcnt[miss]==1||dp1[miss].find(i.ff)!=dp1[miss].end()) dp1[a].insert(i.ff);
        }
    }
    for(int i:words[a]){
        if(leafcnt[a]==1) dp[a].insert(i);
        else if(dp1[a].find(i)!=dp1[a].end()){
            dp[a].insert(i);
            dp1[a].erase(i);
        }
    }
    return;
}
vi adj[1000005],words[1000005];
int leafcnt[1000005]={0};
set<int>dp[1000005];
set<int>dp1[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            adj[i].clear();
            words[i].clear();
            leafcnt[i]=0;
            dp[i].clear();
            dp1[i].clear();
        }
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            x--;
            adj[x].pb(i);
        }
        map<string,int>m;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            for(int j=0;j<c;j++){
                string s;
                cin>>s;
                if(m.find(s)==m.end())
                    m[s]=m.size();
                words[i].pb(m[s]);
            }
        }
        dfs(0,adj,words,dp,dp1,leafcnt);
        // for(auto i:m){
        //     cout<<i.ff<<' '<<i.ss<<'\n';
        // }
        // for(int i=0;i<n;i++){
        //     cout<<i<<": "<<leafcnt[i]<<'\n';
        //     for(int j:dp[i]) cout<<j<<' ';
        //     cout<<'\n';
        //     for(int j:dp1[i]) cout<<j<<' ';
        //     cout<<'\n';
        // }
        cout<<"Case #"<<T<<": "<<dp[0].size()<<'\n';
    }
}