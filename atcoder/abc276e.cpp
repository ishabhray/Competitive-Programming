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
int p[1000006],sz[1000006];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(sz[a]>sz[b]) swap(a,b);
    p[a]=b;
    sz[a]+=sz[b];
}
int hsh(int x,int y,int n,int m){
    return x*m+y;
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
        int n,m;
        cin>>n>>m;
        string s[n];
        for(string &i:s) cin>>i;
        ii mv[4]={{1,0},{-1,0},{0,1},{0,-1}};
        int sx,sy;
        for(int i=0;i<n*m;i++) p[i]=i,sz[i]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='S') sx=i,sy=j;
                if(s[i][j]!='.') continue;
                for(auto k:mv){
                    int x=i+k.ff,y=j+k.ss;
                    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.') uni(hsh(i,j,n,m),hsh(x,y,n,m));
                }
            }
        }
        bool ans=0;
        for(int i=0;i<4;i++){
            int x=sx+mv[i].ff,y=sy+mv[i].ss;
            if(x<0||x>=n||y<0||y>=m) continue;
            for(int j=0;j<4;j++){
                if(i==j) continue;
                int x1=sx+mv[j].ff,y1=sy+mv[j].ss;
                if(x1<0||x1>=n||y1<0||y1>=m) continue;
                int u=hsh(x,y,n,m),v=hsh(x1,y1,n,m);
                u=get(u);
                v=get(v);
                if(u==v) ans=1;
            }
        }
        // for(int i=0;i<n*m;i++) cout<<get(i)<<' ';
        // cout<<'\n';
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
}