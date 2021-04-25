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

int dp[505][505],a[505],n;
int memo(int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+2;k<=j;k++){
        if(a[k]!=a[i])
            continue;
        ans=min(ans,memo(i+1,k-1)+memo(k+1,j));
    }
    if(i<n-1&&a[i]==a[i+1])
        ans=min(ans,1+memo(i+2,j));
    return dp[i][j]=min(1+memo(i+1,j),ans);
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
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<memo(0,n-1);
    }
}