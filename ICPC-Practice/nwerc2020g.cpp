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
int n,r,m;
ld dp[55][5005],p[55],t[55],d[55];
ld solve(int i,int j,ld mid){
    if(j>=r-n)
        return 1e18;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==m)
        return n-t[m-1];
    ld curr=t[i];
    if(i)
        curr-=t[i-1];
    dp[i][j]=p[i]*(curr+solve(i+1,j,mid));
    dp[i][j]+=(1.0-p[i])*min(curr+mid,d[i]+curr+solve(i+1,j+d[i],mid));
    return dp[i][j];
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n>>r>>m;
        for(int i=0;i<m;i++)
            cin>>t[i]>>p[i]>>d[i];
        ld l=0,rl=1e15;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=r-n;j++)
                dp[i][j]=-1;
        
        while(rl-l>1e-7){
            for(int i=0;i<=m;i++)
                for(int j=0;j<=r-n;j++)
                    dp[i][j]=-1;
            ld mid=(l+rl)/2;
            ld curr=solve(0,0,mid);
            if(curr<=mid)
                rl=mid;
            else
                l=mid;
        }
        cout<<setprecision(12)<<(l+rl)/2<<'\n';
    }
}