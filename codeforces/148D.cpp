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

ld dp[2][1001][1001];

ld solve(int w,int b,int c){
    if(w<0||b<0)
        return 0.0;
    if(dp[c][w][b]>=0.0)
        return dp[c][w][b];
    if(!c){
        if(w==0)
            return dp[c][w][b]=0.0;
        if(b==0)
            return dp[c][w][b]=1.0;
        dp[c][w][b]=1.0*w/(w+b)+1.0*b/(w+b)*solve(w,b-1,1);
        return dp[c][w][b];
    }
    else{
        if(w==0||b==0||w+b<=2)
            return dp[c][w][b]=0.0;
        dp[c][w][b]=1.0*b/(w+b)*(1.0*w/(w+b-1)*solve(w-1,b-1,0)+1.0*(b-1)/(w+b-1)*solve(w,b-2,0));
        return dp[c][w][b];
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
    //factorial(1000005);
    while(te--){
        int w,b;
        cin>>w>>b;
        for(int i=0;i<=1000;i++)
            for(int j=0;j<=1000;j++)
                dp[0][i][j]=dp[1][i][j]=-1.0;
        cout<<setprecision(12)<<solve(w,b,0);
    }
}