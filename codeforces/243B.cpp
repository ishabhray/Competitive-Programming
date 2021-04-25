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
        int n,m,h,t;
        cin>>n>>m>>h>>t;
        vi adj[n+1];
        ii edge[2*m];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            edge[2*i]={u,v};
            edge[2*i+1]={v,u};
        }
        bool b=true;
        for(int i=0;i<2*m;i++){
            int u=edge[i].ff,v=edge[i].ss;
            if(adj[u].size()<h+1||adj[v].size()<t+1)
                continue;
            if(adj[u].size()>h+t+1){
                b=false;
                cout<<"YES\n";
                cout<<u<<' '<<v<<'\n';
                int freq[100001]={0};
                vi hi,ti;
                for(int j:adj[v]){
                    if(j==u)
                        continue;
                    if(ti.size()==t)
                        break;
                    ti.pb(j);
                    freq[j]++;
                }
                for(int j:adj[u]){
                    if(j==v||freq[j])
                        continue;
                    if(hi.size()==h)
                        break;
                    hi.pb(j);
                }
                for(int j:hi)
                    cout<<j<<' ';
                cout<<'\n';
                for(int j:ti)
                    cout<<j<<' ';
                cout<<'\n';
                break;
            }
            if(adj[v].size()>h+t+1){
                b=false;
                cout<<"YES\n";
                cout<<u<<' '<<v<<'\n';
                int freq[100001]={0};
                vi hi,ti;
                for(int j:adj[u]){
                    if(j==v)
                        continue;
                    if(hi.size()==h)
                        break;
                    hi.pb(j);
                    freq[j]++;
                }
                for(int j:adj[v]){
                    if(j==u||freq[j])
                        continue;
                    if(ti.size()==t)
                        break;
                    ti.pb(j);
                }
                for(int j:hi)
                    cout<<j<<' ';
                cout<<'\n';
                for(int j:ti)
                    cout<<j<<' ';
                cout<<'\n';
                break;
            }
            int freq[100001]={0};
            int cnt=0;
            for(int j:adj[u])
                if(j!=v)
                    freq[j]++,cnt++;
            vi common;
            for(int j:adj[v]){
                if(j==u)
                    continue;
                if(!freq[j])
                    cnt++;
                else
                    common.pb(j);
                freq[j]++;
            }
            if(cnt>=h+t){
                b=false;
                cout<<"YES\n";
                cout<<u<<' '<<v<<'\n';
                vi hi,ti;
                for(int j:adj[u]){
                    if(j==v)
                        continue;
                    if(freq[j]!=2)
                        hi.pb(j);
                }
                for(int j:adj[v]){
                    if(j==u)
                        continue;
                    if(freq[j]!=2)
                        ti.pb(j);
                }
                int k=0;
                while(hi.size()<h)
                    hi.pb(common[k++]);
                while(ti.size()<t)
                    ti.pb(common[k++]);
                for(int i=0;i<h;i++)
                    cout<<hi[i]<<' ';
                cout<<'\n';
                for(int i=0;i<t;i++)
                    cout<<ti[i]<<' ';
                cout<<'\n';
                break;
            }
        }
        if(b)
            cout<<"NO";
    }
}