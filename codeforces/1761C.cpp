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
void dfs(int a,vi adj[],vi ans[]){
    set<int>s;
    for(int i:ans[a]) s.insert(i);
    for(int i=0;i<adj[a].size();i++){
        int b=adj[a][i];
        s.erase(ans[a][i]);
        ans[b]=vi(all(s));
        s.insert(ans[a][i]);
        dfs(b,adj,ans);
    }
}
void dfs(int a,int vis[],vi adj[],stack<int>&s){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i]) continue;
        dfs(i,vis,adj,s);
    }
    s.push(a);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        string s[n];
        for(string &i:s) cin>>i;
        vi adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='1') adj[i].pb(j);
            }
        }
        int vis[n]={0};
        stack<int>st;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,vis,adj,st);
        }
        set<int> ans[n];
        int c=1;
        while(st.size()){
            int x=st.top();
            st.pop();
            ans[x].insert(c++);
            for(int i:adj[x]) for(int j:ans[x]) ans[i].insert(j);
        }
        for(int i=0;i<n;i++){
            cout<<ans[i].size()<<' ';
            for(int j:ans[i]) cout<<j<<' ';
            cout<<'\n';
        }
    }
}