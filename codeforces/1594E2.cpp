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

map<ll,vl>dp;
set<ll>marked;
map<ll,ll>a;
void dfs(ll i){
    if(marked.find(2*i)!=marked.end()) dfs(2*i);
    if(marked.find(2*i+1)!=marked.end()) dfs(2*i+1);
    dp[i]=vl(7,1);
    dp[i][6]=0;
    if(marked.find(2*i)!=marked.end()){
        (dp[i][0]*=(dp[2*i][6]+2*MOD-dp[2*i][0]-dp[2*i][1])%MOD)%=MOD;
        (dp[i][1]*=(dp[2*i][6]+2*MOD-dp[2*i][0]-dp[2*i][1])%MOD)%=MOD;
        (dp[i][2]*=(dp[2*i][6]+2*MOD-dp[2*i][2]-dp[2*i][3])%MOD)%=MOD;
        (dp[i][3]*=(dp[2*i][6]+2*MOD-dp[2*i][2]-dp[2*i][3])%MOD)%=MOD;
        (dp[i][4]*=(dp[2*i][6]+2*MOD-dp[2*i][4]-dp[2*i][5])%MOD)%=MOD;
        (dp[i][5]*=(dp[2*i][6]+2*MOD-dp[2*i][4]-dp[2*i][5])%MOD)%=MOD;
    }
    if(marked.find(2*i+1)!=marked.end()){
        (dp[i][0]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][0]-dp[2*i+1][1])%MOD)%=MOD;
        (dp[i][1]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][0]-dp[2*i+1][1])%MOD)%=MOD;
        (dp[i][2]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][2]-dp[2*i+1][3])%MOD)%=MOD;
        (dp[i][3]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][2]-dp[2*i+1][3])%MOD)%=MOD;
        (dp[i][4]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][4]-dp[2*i+1][5])%MOD)%=MOD;
        (dp[i][5]*=(dp[2*i+1][6]+2*MOD-dp[2*i+1][4]-dp[2*i+1][5])%MOD)%=MOD;
    }
    for(int j=0;j<6;j++) (dp[i][6]+=dp[i][j])%=MOD;
    if(a.find(i)!=a.end()){
        for(int j=0;j<6;j++) if(j!=a[i]) dp[i][j]=0;
        dp[i][6]=dp[i][a[i]];
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll k,n;
        cin>>k>>n;
        string col[]={"white", "yellow", "green", "blue", "red", "orange"};
        map<string,int>idx;
        for(int i=0;i<6;i++) idx[col[i]]=i;
        for(int i=0;i<n;i++){
            ll x;
            string s;
            cin>>x>>s;
            a[x]=idx[s];
            while(x>=1){marked.insert(x); x/=2;}
        }
        dfs(1);
        ll tot=(1ll<<k)-1,ans=power(4,tot-marked.size());
        (ans*=dp[1][6])%=MOD;
        cout<<ans<<'\n';
    }
}