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

int match[505];
pll dp[505][505];
string s,t;
int n,m;
pll f(int l,int r){
    if(l>r) return {0,1};
    if(dp[l][r].ff!=-1) return dp[l][r];
    vi v;
    for(int i=l;i+m-1<=r;i++){
        if(match[i]) v.pb(i);
    }
    if(v.empty()) return dp[l][r]={0,1};
    for(int i=0;i<v.size();i++){
        if(i+1<v.size()){
            if(v[i]+m-1<v[i+1]){
                pll x=f(l,v[i]+m-1),y=f(v[i+1],r);
                pll z={x.ff+y.ff,x.ss*y.ss%MOD};
                return z;
            }
        }
    }
    pll mn={1e18,1};
    int pre=v[0];
    for(int i:v){
        if(pre!=-1){
            if(pre+m-1<i) break;
        }
        pll x=f(l,i-1),y=f(i+m,r);
        pll z={x.ff+y.ff+1,x.ss*y.ss%MOD};
        // if(l==0&&r==n-1) cout<<i<<' '<<x.ff<<' '<<x.ss<<' '<<y.ff<<' '<<y.ss<<'\n';
        if(z.ff<mn.ff) mn=z;
        else if(z.ff==mn.ff) mn.ss=(mn.ss+z.ss)%MOD;
    }
    return dp[l][r]=mn;
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
        cin>>s>>t;
        n=s.size(),m=t.size();
        if(m>n){
            cout<<"0 1\n";
            continue;
        }
        for(int i=0;i+m<=n;i++){
            bool f=true;
            for(int j=0;j<m;j++){
                f&=(s[i+j]==t[j]);
            }
            match[i]=f;
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]={-1,-1};
        cout<<f(0,n-1).ff<<' '<<f(0,n-1).ss<<'\n';
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j].ff<<'.'<<dp[i][j].ss<<' ';
        //     cout<<'\n';
        // }
    }
}