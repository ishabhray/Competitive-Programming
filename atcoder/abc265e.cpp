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
int MOD=998244353;
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

ll dp[305][305][305];
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
        ll n,m,a,b,c,d,e,f;
        cin>>n>>m>>a>>b>>c>>d>>e>>f;
        map<pll,int>s;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            s[{x,y}]++;
        }
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int x=0;x<=i;x++){
                for(int y=0;x+y<=i;y++){
                    int z=i-x-y;
                    ll xx=x*a+y*c+z*e;
                    ll yy=x*b+y*d+z*f;
                    if(s.find({xx,yy})!=s.end()) continue;
                    (dp[i][x][y]+=dp[i-1][x][y])%=MOD;
                    if(x) (dp[i][x][y]+=dp[i-1][x-1][y])%=MOD;
                    if(y) (dp[i][x][y]+=dp[i-1][x][y-1])%=MOD;
                }
            }
        }
        ll ans=0;
        for(int x=0;x<=n;x++){
            for(int y=0;x+y<=n;y++){
                (ans+=dp[n][x][y])%=MOD;
            }
        }
        cout<<ans<<'\n';
    }
}