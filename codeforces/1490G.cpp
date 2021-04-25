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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n,m;
        cin>>n>>m;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll pre[n+1]={0};
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+a[i];
        ll mx=0;
        vv<pll>v;
        v.pb({0,0});
        for(int i=1;i<=n;i++){
            if(pre[i]>mx){
                mx=pre[i];
                v.pb({pre[i],i});
            }
        }
        for(int i=0;i<m;i++){
            ll q;
            cin>>q;
            if(pre[n]<=0&&q>mx){
                cout<<"-1 ";
                continue;
            }
            if(q<=mx){
                auto it=lower_bound(all(v),mp(q,-1ll));
                cout<<it->ss-1<<' ';
            }
            else{
                ll noc=(q-mx+-1)/pre[n];
                q-=noc*pre[n];
                if(q<=mx){
                    auto it=lower_bound(all(v),mp(q,-1ll));
                    cout<<n*noc+it->ss-1<<' ';
                    continue;
                }
                noc++;
                q-=pre[n];
                auto it=lower_bound(all(v),mp(q,-1ll));
                cout<<n*noc+it->ss-1<<' ';
            }
        }
        cout<<'\n';
    }
}