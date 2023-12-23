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
ii mv[4]={mp(0,1),mp(0,-1),mp(1,0),mp(-1,0)};
int r,c,curr;
set<ii> find_adj(string s[],int x,int y,vv<vi>&vis){
    set<ii>adj;
    curr+=1;
    for(auto i:mv){
        int a=x+i.ff,b=y+i.ss;
        if(a<0||a>=r||b<0||b>=c) continue;
        if(s[a][b]=='W'&&!vis[a][b]){
            vis[a][b]=1;
            set<ii>adj1=find_adj(s,a,b,vis);
            for(auto j:adj1) adj.insert(j);
        }
        else if(s[a][b]=='.') adj.insert(mp(a,b));
    }
    return adj;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        cin>>r>>c;
        string s[r];
        for(auto &i:s) cin>>i;
        vv<vi>vis(r,vi(c,0));
        map<ii,int>pts;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(s[i][j]!='W'||vis[i][j]==1) continue;
                vis[i][j]=1;
                curr=0;
                set<ii>x=find_adj(s,i,j,vis);
                if(x.size()!=1) continue;
                pts[*x.begin()]+=curr;
            }
        }
        int ans=0;
        for(auto i:pts)
            ans=max(ans,i.ss);
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}