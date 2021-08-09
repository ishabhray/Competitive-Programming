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
ii a[100];
int dp[105][105],n;
int solve(int l,int r){
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int cnt[105]={0};
    for(int i=0;i<n;i++){
        if(a[i].ff>=l&&a[i].ss<=r) cnt[solve(l,a[i].ff)^solve(a[i].ss,r)]++;
    }
    for(int i=0;i<105;i++){
        if(!cnt[i]) {return dp[l][r]=i;}
    }
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>a[i].ff>>a[i].ss;
        }
        if(solve(1,100)) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}