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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
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
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n];
        for(ll &i:a) cin>>i;
        ll ans=0;
        ordered_set s;
        for(int i=0;i<m;i++) s.insert({a[i],i});
        for(int i=0;i<k;i++) ans+=s.find_by_order(i)->ff;
        cout<<ans<<' ';
        for(int i=m;i<n;i++){
            s.insert({a[i],i});
            if(s.order_of_key({a[i],i})<k){
                ans+=a[i];
                ans-=s.find_by_order(k)->ff;
            }
            if(s.order_of_key({a[i-m],i-m})<k){
                ans-=a[i-m];
                ans+=s.find_by_order(k)->ff;
            }
            s.erase({a[i-m],i-m});
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
}