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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,k,l;
        cin>>n>>m>>k>>l;
        int a[n],b[l];
        for(int &i:a) cin>>i;
        for(int &i:b) cin>>i;
        vv<ii>adj[n+1];
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        vv<pair<ll,int>>mn(n+1,{-1,-1}),mn1(n+1,{-1,-1});
        priority_queue<pair<ll,ii>>q;
        for(int i=0;i<l;i++){
            q.push({0,{b[i],a[b[i]-1]}});
            mn[b[i]]={0,a[b[i]-1]};
        }
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            // cout<<"CUrr Node: "<<cur.ff<<" "<<cur.ss.ff<<" "<<cur.ss.ss<<endl;
            if(mn[cur.ss.ff].ff!=-cur.ff&&mn1[cur.ss.ff].ff!=-cur.ff) continue;
            for(auto i:adj[cur.ss.ff]){
                if(mn[i.ff].ff==-1||mn[i.ff].ff>-cur.ff+i.ss){
                    if(mn[i.ff].ss!=cur.ss.ss) mn1[i.ff]=mn[i.ff];
                    mn[i.ff]={-cur.ff+i.ss,cur.ss.ss};
                    q.push({cur.ff-i.ss,{i.ff,cur.ss.ss}});
                }
                else if(cur.ss.ss!=mn[i.ff].ss&&(mn1[i.ff].ff==-1||mn1[i.ff].ff>-cur.ff+i.ss)){
                    mn1[i.ff]={-cur.ff+i.ss,cur.ss.ss};
                    q.push({cur.ff-i.ss,{i.ff,cur.ss.ss}});
                }
            }
            // for(int i=1;i<=n;i++) cout<<mn[i].ff<<'.'<<mn[i].ss<<'|'<<mn1[i].ff<<'.'<<mn1[i].ss<<'\n';
        }
        for(int i=1;i<=n;i++){
            if(mn[i].ss!=a[i-1]) cout<<mn[i].ff<<' ';
            else cout<<mn1[i].ff<<' ';
        }
        cout<<'\n';
    }
}