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
int dp[1001][1001];
int n,m;
string s,t;
int f(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==n&&y==m) return dp[x][y]=1;
    if(y==m) return dp[x][y]=0;
    if(x==n){
        if(isdigit(t[y])) return dp[x][y]=f(x,y+1);
        else return dp[x][y]=0;
    }
    if(isdigit(t[y])){
        dp[x][y]=0;
        for(int i=0;i<=t[y]-'0';i++){
            if(x+i<=n&&f(x+i,y+1)){
                dp[x][y]=1;
                break;
            }
        }
        return dp[x][y];
    }
    else if(s[x]==t[y]) return dp[x][y]=f(x+1,y+1);
    else return dp[x][y]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    cin>>te;
    while(te--){
        cin>>n>>m>>s>>t;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=-1;
        if(f(0,0)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
