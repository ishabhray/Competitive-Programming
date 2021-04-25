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
int mon[200005][2],tim[400005][2];
int p[200005],sz[200005],t[200005];
int get(int a){
    if(p[a]==1||p[a]==a)
        return p[a];
    int x=get(p[a]);
    t[a]=t[p[a]];
    p[a]=x;
    return x;
}
void uni(int a,int b,int x)
{
    a=get(a);
    b=get(b);
    if(a==b)
        return;
    if(a==1){
        t[b]=x;
        p[b]=a;
        sz[a]+=sz[b];
    }
    else if(b==1){
        t[a]=x;
        p[a]=b;
        sz[b]+=sz[a];
    }
    else if(sz[a]>=sz[b])
        p[b]=a,sz[a]+=sz[b];
    else
        p[a]=b,sz[b]+=sz[a];
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
        for(int i=1;i<=n;i++)
            cin>>mon[i][0]>>mon[i][1];
        for(int i=0;i<m;i++)
            cin>>tim[i][0]>>tim[i][1];
        for(int i=1;i<=n;i++)
            p[i]=i,sz[i]=0,t[i]=0;
        int fin[n+1][2];
        memset(fin,0,sizeof(fin));
        for(int i=0;i<m;i++)
            fin[tim[i][0]][tim[i][1]-1]=1;
        t[1]=-1;
        for(int i=1;i<=n;i++){
            if(!fin[i][0]&&mon[i][0]!=-1)
                uni(i,mon[i][0],-1);
            if(!fin[i][1]&&mon[i][1]!=-1)
                uni(i,mon[i][1],-1);
        }
        for(int i=m-1;i>=0;i--){
            /*for(int i=1;i<=5;i++)
                cout<<p[i]<<' ';
            cout<<'\n';
            for(int i=1;i<=5;i++)
                cout<<t[i]<<' ';
            cout<<'\n';*/
            uni(tim[i][0],mon[tim[i][0]][tim[i][1]-1],i);
        }
        for(int i=1;i<=n;i++){
            get(i);
            cout<<((t[i]==m+1)?-1:t[i])<<'\n';
        }
    }
}