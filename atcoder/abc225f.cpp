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
bool comp(string &l,string &r){
    if(l+r<r+l) return 1;
    return 0;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,k;
        cin>>n>>k;
        string a[n];
        for(auto &i:a) cin>>i;
        sort(a,a+n,comp);
        string dp[n][k+1];
        for(int i=0;i<=k;i++) dp[n-1][i]="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        dp[n-1][1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i][1]=min(a[i],dp[i+1][1]);
            for(int j=2;j<=k;j++){
                dp[i][j]=min(a[i]+dp[i+1][j-1],dp[i+1][j]);
            }
        }
        cout<<dp[0][k]<<'\n';
    }
}