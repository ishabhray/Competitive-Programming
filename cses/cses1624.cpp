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

char a[8][8];
ll ans=0,col[8],dia1[16],dia2[16];

void solve(int n){
    if(n==8)
        ans++;
    for(int i=0;i<8;i++){
        if(col[i]||dia1[8+n-i]||dia2[n+i]||a[n][i]=='*')
            continue;
        col[i]=dia1[8+n-i]=dia2[n+i]=1;
        solve(n+1);
        col[i]=dia1[8+n-i]=dia2[n+i]=0;
    }
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
    //factorial(1000005);
    while(te--){
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                cin>>a[i][j];
        solve(0);
        cout<<ans<<'\n';
    }
}