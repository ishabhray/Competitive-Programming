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
    while(te--){
        string s;
        ll k,n;
        cin>>s>>k;
        n=s.size();
        vl v;
        v.pb(0);
        for(int i=0;i<n;i++){
            if(s[i]=='Y') v.pb(i-v.size());
        }
        n=v.size();
        if(n<3){
            cout<<n-1<<'\n';
            return 0;
        }

        vl pre(n,0);
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
        ll l=2,r=n-1,ans=1;
        while(l<=r){
            ll mid=(l+r)/2,curr=1e18;
            for(ll i=1;i+mid-1<n;i++){
                ll x=i+mid/2;
                ll s=(x-i+1)*v[x]-pre[x]+pre[i-1]+pre[i+mid-1]-pre[x]-(i+mid-1-x)*v[x];
                // cout<<i<<' '<<x<<' '<<s<<'\n';
                curr=min(curr,s);
                x--;
                s=(x-i+1)*v[x]-pre[x]+pre[i-1]+pre[i+mid-1]-pre[x]-(i+mid-1-x)*v[x];
                // cout<<i<<' '<<x<<' '<<s<<'\n';
                curr=min(curr,s);
            }
            // cout<<mid<<' '<<curr<<'\n';
            if(curr<=k) l=mid+1,ans=mid;
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
}