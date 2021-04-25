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

string s;
ll dp[2005][2005];
ll solve(int i,int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j||i>j)
        return dp[i][j]=1;
    if(s[i]==s[j]){
        if(solve(i+1,j-1))
            dp[i][j]=1;
        else
            dp[i][j]=0;
    }
    else dp[i][j]=0;
    solve(i+1,j);
    solve(i,j-1);
    return dp[i][j];
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
        cin>>s;
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        solve(0,n-1);
        ll suff[n]={0};
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                suff[i]+=dp[i][j];
        }
        for(int i=n-2;i>=0;i--)
            suff[i]+=suff[i+1];
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1;j++){
                if(dp[i][j]){
                    ans+=suff[j+1];
                }
            }
        }
        cout<<ans<<'\n';
    }
}