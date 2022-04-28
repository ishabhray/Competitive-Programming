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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(te--){
        int n;
        cin>>n;
        ll a[n];
        for(ll &i:a) cin>>i;
        ll ans=0;
        for(int c=0;c<10;c++){
            ll x=a[rng()%n];
            vl v;
            for(ll i =1;i*i<=x;i++){
                if(x%i) continue;
                v.pb(i);
                if(i!=x/i) v.pb(x/i);
            }
            sort(all(v));
            int cnt[v.size()]={0};
            for(int i=0;i<n;i++){
                ll g=gcd(x,a[i]);
                cnt[lower_bound(all(v),g)-v.begin()]++;
            }
            for(int i=0;i<v.size();i++){
                for(int j=i+1;j<v.size();j++){
                    if(v[j]%v[i]==0) cnt[i]+=cnt[j];
                }
            }
            for(int i=(int)v.size()-1;i>=0;i--){
                if(cnt[i]*2>=n) ans=max(ans,v[i]);
            }
        }
        cout<<ans<<'\n';
    }
}