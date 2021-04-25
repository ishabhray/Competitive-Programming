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
void dfs(int a,vi adj[],int vis[],stack<int>&st){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i])
            continue;
        dfs(i,adj,vis,st);
    }
    st.push(a);
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
        string a[n];
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>a[i];
            for(char j:a[i])
                s.insert(j-'a');
        }
        vi adj[26];
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i].size()-1;j++)
                adj[a[i][j]-'a'].pb(a[i][j+1]-'a');
        }
        stack<int>st;
        int vis[26]={0};
        for(int i:s){
            if(vis[i])
                continue;
            dfs(i,adj,vis,st);
        }
        memset(vis,0,sizeof(vis));
        while(!st.empty()){
            if(!vis[st.top()]){
                int x=st.top();
                vis[x]=1;
                while(!adj[x].empty()){
                    cout<<(char)(x+'a');
                    x=adj[x][0];
                    vis[x]=1;
                }
                cout<<(char)(x+'a');
            }
            st.pop();
        }
    }
}