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
int mx[1000005];
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
        int n,m;
        cin>>n>>m;
        vv<ii > x(n),y(m);
        for(int i=0;i<n;i++)
            cin>>x[i].ff>>x[i].ss;
        for(int i=0;i<m;i++)
            cin>>y[i].ff>>y[i].ss;
        vv<ii >v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(y[j].ff-x[i].ff>=0&&y[j].ss-x[i].ss>=0)
                    v.pb({y[j].ff-x[i].ff,y[j].ss-x[i].ss});
            }
        }
        memset(mx,-1,sizeof(mx));
        for(auto i:v)
            mx[i.ff]=max(i.ss,mx[i.ff]);
        int ans=1e9;
        for(int i=1000000;i>=0;i--){
            mx[i]=max(mx[i],mx[i+1]);
            ans=min(ans,i+mx[i]+1);
        }
        cout<<ans;
    }
}