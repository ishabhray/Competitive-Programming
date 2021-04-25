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

int dfs(int i,vi adj[],int vis[],int a[])
{
    if(vis[i])
        return 0;
    vis[i]=1;
    int ans=0;
    if(a[i]==i)
        ans=i;
    for(int j:adj[i])
        ans=max(ans,dfs(j,adj,vis,a));
    return ans;
}
int dfs1(int i,vi adj[],unordered_map<int,int> &vis,unordered_map<int,int> &rec,int par)
{
    if(rec[i])
        return i;
    if(vis[i])
        return 0;
    vis[i]=1;
    rec[i]=1;
    int ans=0;
    for(int j:adj[i]){
        if(j==par)
            continue;
        ans=max(ans,dfs1(j,adj,vis,rec,i));
    }
    rec[i]=0;
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

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        vi adj[n+1];
        //int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        unordered_map<int,int>w;
        for(int i=1;i<=n;i++){
            if(a[a[i]]==i){
                a[i]=i;//,ans++;
                w[i]++;
                continue;
            }
            adj[i].pb(a[i]);
            adj[a[i]].pb(i);
        }
        int vis[n+1]={0};
        vi cyc,acyc;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            int x=dfs(i,adj,vis,a);
            if(x)
                acyc.pb(x);
            else{
                //int rec[n+1]={0},vis1[n+1]={0};
                unordered_map<int,int>rec,vis1;
                int y=dfs1(i,adj,vis1,rec,-1);
                //cout<<y<<'\n';
                cyc.pb(y);
            }
        }
        int p;
        /*for(int i:cyc)
            cout<<i<<' ';
        cout<<'\n';
        for(int i:acyc)
            cout<<i<<' ';
        cout<<'\n';*/
        if(acyc.size()){
            for(int i:acyc){
                p=i;
                if(!w[p])
                    break;
            }
        }
        else if(cyc.size())
            p=cyc[0];
        for(int i:acyc)
            a[i]=p;//,ans++;
        for(int i:cyc)
            a[i]=p;//,ans++;
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=(a[i]!=b[i]);
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }
}