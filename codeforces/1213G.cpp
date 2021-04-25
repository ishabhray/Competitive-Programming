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
ll ans=0;
ll p[200005],sz[200005];
ll get(ll a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(ll a,ll b){
    a=get(a),b=get(b);
    if(a==b)
        return;
    ans-=sz[a]*(sz[a]-1)/2;
    ans-=sz[b]*(sz[b]-1)/2;
    ans+=(sz[a]+sz[b])*(sz[a]+sz[b]-1)/2;
    if(sz[a]>=sz[b]){
        sz[a]+=sz[b];
        p[b]=a;
    }
    else{
        sz[b]+=sz[a];
        p[a]=b;
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
    //factorial(100005);
    while(te--){
        ll n,m;
        cin>>n>>m;
        pair<ll,pll >e[n-1];
        for(int i=0;i<n-1;i++)
            cin>>e[i].ss.ff>>e[i].ss.ss>>e[i].ff;
        pll q[m];
        for(int i=0;i<m;i++){
            cin>>q[i].ff;
            q[i].ss=i;
        }
        sort(e,e+n-1);
        sort(q,q+m);
        ll j=0;
        ll x[m];
        for(int i=1;i<=n;i++)
            p[i]=i,sz[i]=1;
        for(int i=0;i<m;i++){
            while(j<n-1&&e[j].ff<=q[i].ff){
                uni(e[j].ss.ff,e[j].ss.ss);
                j++;
            }
            x[q[i].ss]=ans;
        }
        for(ll i:x)
            cout<<i<<' ';
    }
}