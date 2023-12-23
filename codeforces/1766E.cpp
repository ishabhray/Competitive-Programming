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
vi f(vi a,int x){
    for(int i=0;i<a.size();i++){
        if(a[i]&x){
            a[i]=x;
            return a;
        }
    }
    a.pb(x);
    return a;
}
vv<vi>v={{},{1},{2},{3},{1,1},{1,2},{2,1},{2,2},{3,1},{3,2},{1,1,2},{1,2,1},{2,2,1},{2,1,2},{3,1,2},{3,2,1}};
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
        ll n;
        cin>>n;
        int a[n];
        for(int &i:a) cin>>i;
        ll ans=0;
        ll dp[n][16];
        memset(dp,0,sizeof(dp));
        for(ll i=0;i<n;i++){
            if(!a[i]){
                ans+=(n-i)*(i+1);
                dp[i][0]++;
                if(i) for(int j=0;j<16;j++) dp[i][j]+=dp[i-1][j];
                continue;
            }
            dp[i][a[i]]++;
            ll curr=1;
            if(i){
                for(int j=0;j<16;j++){
                    vi x=f(v[j],a[i]);
                    for(int k=0;k<16;k++){
                        if(v[k]==x){
                            dp[i][k]+=dp[i-1][j];
                            break;
                        }
                    }
                    if(x.size()>v[j].size()) curr+=dp[i-1][j];
                }
            }
            ans+=curr*(n-i);
            // cout<<ans<<'\n';
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<16;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        cout<<ans<<'\n';
    }
}