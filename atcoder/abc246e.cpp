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
int vis[1500][1500];
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
        int n,sx,sy,ex,ey;
        cin>>n>>sx>>sy>>ex>>ey;
        string s[n];
        for(auto &i:s) cin>>i;
        sx--,sy--,ex--,ey--;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) vis[i][j]=1e8;
        vis[sx][sy]=1;
        deque<vi>q;
        q.pb({sx,sy,0});
        q.pb({sx,sy,1});
        q.pb({sx,sy,2});
        q.pb({sx,sy,3});
        vi moves[]={{1,1,0},{1,-1,1},{-1,1,2},{-1,-1,3}};
        while(q.size()){
            auto a=q.front();
            q.pop_front();
            int x=a[0],y=a[1],d=a[2];
            // cout<<x<<' '<<y<<' '<<d<<' '<<vis[x][y]<<'\n';
            if(x==ex&&y==ey) break;
            for(auto i:moves){
                int xx=x+i[0],yy=y+i[1];
                if(xx<0||yy<0||xx==n||yy==n||s[xx][yy]=='#'||vis[xx][yy]<vis[x][y]+(d!=i[2])) continue;
                vis[xx][yy]=vis[x][y]+(d!=i[2]);
                if(d==i[2]) q.push_front({xx,yy,i[2]});
                else q.pb({xx,yy,i[2]});
            }
        }
        if(vis[ex][ey]==1e8) vis[ex][ey]=-1;
        cout<<vis[ex][ey]<<'\n';
    }
}