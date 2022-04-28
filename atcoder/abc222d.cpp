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

ll dp[3005][3005];
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
        int n;
        cin>>n;
        int a[n],b[n];
        for(int &i:a) cin>>i;
        for(int &i:b) cin>>i;
        for(int i=a[0];i<=b[0];i++) dp[0][i]=1;
        for(int i=1;i<=3000;i++) dp[0][i]+=dp[0][i-1];
        for(int i=1;i<n;i++){
            for(int j=a[i];j<=b[i];j++){
                dp[i][j]=dp[i-1][j];
            }
            for(int j=1;j<=3000;j++) (dp[i][j]+=dp[i][j-1])%=MOD;
        }
        cout<<(dp[n-1][b[n-1]]-dp[n-1][a[n-1]-1]+MOD)%MOD<<'\n';
    }
}