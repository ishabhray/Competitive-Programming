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

ll dp[5001][5001];

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
        ll n,k,q;
        cin>>n>>k>>q;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll cnt[n]={0};
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                    dp[j][i]=1;
                else{
                    if(j)
                        (dp[j][i]+=dp[j-1][i-1])%=MOD;
                    if(j<n-1)
                        (dp[j][i]+=dp[j+1][i-1])%=MOD;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++)
                (cnt[i]+=dp[i][j]*dp[i][k-j]%MOD)%=MOD;
        }
        ll sum=0;
        for(int i=0;i<n;i++)
            (sum+=cnt[i]*a[i])%=MOD;
        for(int i=0;i<q;i++){
            ll idx,val;
            cin>>idx>>val;
            idx--;
            sum-=cnt[idx]*a[idx]%MOD;
            (sum+=MOD)%=MOD;
            a[idx]=val;
            (sum+=cnt[idx]*a[idx]%MOD)%=MOD;
            cout<<sum<<'\n';
        }
    }
}