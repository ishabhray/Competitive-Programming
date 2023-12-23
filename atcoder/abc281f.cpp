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
ll f(vl &v,int l,int r,int c){
    if(c==-1||l>r) return 0;
    // cout<<c<<' '<<l<<' '<<r<<": ";
    // for(int i=l;i<=r;i++) cout<<v[i]<<' ';
    // cout<<'\n';
    int cnt=0;
    for(int i=l;i<=r;i++) if(v[i]&(1<<c)) cnt++;
    if(cnt==0||cnt==r-l+1) return f(v,l,r,c-1);
    vl temp;
    for(int i=l;i<=r;i++) if(!(v[i]&(1<<c))) temp.pb(v[i]);
    int x=temp.size();
    for(int i=l;i<=r;i++) if(v[i]&(1<<c)) temp.pb(v[i]);
    for(int i=l;i<=r;i++) v[i]=temp[i-l];
    return (1LL<<c)+min(f(v,l,l+x-1,c-1),f(v,l+x,r,c-1));
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
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        vl v(n);
        for(ll &i:v) cin>>i;
        cout<<f(v,0,n-1,29)<<'\n';
    }
}