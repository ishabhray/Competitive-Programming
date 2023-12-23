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

ll f(char op,ll x,ll y){
    if(op=='+')
        return x+y;
    else if(op=='-')
        return x-y;
    else if(op=='*')
        return x*y;
    else if(op=='/'){
        if(x>0||x%y==0) return x/y;
        else return x/y-1;
    }
    else return x;
}
ll dp[11][11][21][1050];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int te=1;
    cin>>te;
    for(int T=1;T<=te;T++){
        ll n,p,m,sx,sy;
        cin>>n>>p>>m>>sx>>sy;
        sx--,sy--;
        pair<char,int>ops[5];
        ii moves[5]={{-1,0},{0,1},{0,-1},{1,0},{0,0}};
        ops[4]={'$',0};
        for(int i=0;i<4;i++) cin>>ops[i].ff>>ops[i].ss;
        ii is_p[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) is_p[i][j]={-1,-1};
        for(int i=0;i<p;i++){
            int x,y,w;
            cin>>x>>y>>w;
            x--,y--;
            is_p[x][y]={i,w};
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<=m;k++) for(int mask=0;mask<(1<<p);mask++) dp[i][j][k][mask]=-1e18;
        dp[sx][sy][0][0]=0;
        for(int k=0;k<m;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int mask=0;mask<(1<<p);mask++){
                        if(dp[i][j][k][mask]==-1e18) continue;
                        for(int c=0;c<5;c++){
                            int x=i+moves[c].ff,y=j+moves[c].ss;
                            if(x<0||x==n||y<0||y==n)
                                continue;
                            dp[x][y][k+1][mask]=max(dp[x][y][k+1][mask],f(ops[c].ff,dp[i][j][k][mask],ops[c].ss));
                            if(is_p[x][y].ff!=-1&&((mask&(1<<is_p[x][y].ff))==0)) dp[x][y][k+1][mask|(1<<is_p[x][y].ff)]=max(dp[x][y][k+1][mask|(1<<is_p[x][y].ff)],f(ops[c].ff,dp[i][j][k][mask],ops[c].ss)+is_p[x][y].ss);
                        }
                    }
                }
            }
        }
        ll ans=-1e18;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j][m][(1<<p)-1]);
            }
        }
        if(ans==-1e18){
            cout<<"Case #"<<T<<": IMPOSSIBLE\n";
            continue;
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}