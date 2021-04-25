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
        ii edges[m];
        map<ii,int>hash;
        vi adj[n+1];
        for(int i=0;i<m;i++){
            cin>>edges[i].ff>>edges[i].ss;
            adj[edges[i].ff].pb(edges[i].ss);
            adj[edges[i].ss].pb(edges[i].ff);
            hash[edges[i]]++;
        }
        int x=edges[0].ff,y=edges[0].ss,z;
        for(z=1;z<=n;z++){
            if(z==x||z==y)
                continue;
            if((hash[{x,z}]||hash[{z,x}])&&(hash[{y,z}]||hash[{z,y}]))
                break;
        }
        if(z>n){
            cout<<-1;
            return 0;
        }
        int ans[n+1]={0};
        ans[x]=1,ans[y]=2,ans[z]=3;
        for(int i=1;i<=n;i++){
            if(i==x||i==y||i==z)
                continue;
            if(hash[{x,i}]+hash[{i,x}]+hash[{y,i}]+hash[{i,y}]+hash[{z,i}]+hash[{i,z}]!=2){
                cout<<-1;
                return 0;
            }
            if(!hash[{x,i}]&&!hash[{i,x}])
                ans[i]=ans[x];
            if(!hash[{y,i}]&&!hash[{i,y}])
                ans[i]=ans[y];
            if(!hash[{z,i}]&&!hash[{i,z}])
                ans[i]=ans[z];
            for(int j:adj[i]){
                if(!ans[j])
                    continue;
                if(ans[j]==ans[i]){
                    cout<<-1;
                    return 0;
                }
            }
        }
        vv<vi>v(3);
        for(int i=1;i<=n;i++)
            v[ans[i]-1].pb(i);
        for(int i:v[0]){
            for(int j:v[1]){
                if(!hash[{i,j}]&&!hash[{j,i}]){
                    cout<<-1;
                    return 0;
                }
            }
            for(int j:v[2]){
                if(!hash[{i,j}]&&!hash[{j,i}]){
                    cout<<-1;
                    return 0;
                }
            }
        }
        for(int i:v[1]){
            for(int j:v[2]){
                if(!hash[{i,j}]&&!hash[{j,i}]){
                    cout<<-1;
                    return 0;
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}