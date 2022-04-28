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
#define MAXN 2000005
#define MOD 1000000007
bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];
 
void push(ll v,ll l,ll r){
    if(marked[v]){
        ll z=t[v]/(r-l+1);
        ll tm=(l+r)/2;
        t[2*v]=z*(tm-l+1);
        t[2*v+1]=z*(r-tm);
        marked[2*v]=marked[2*v+1]=true;
        marked[v]=false;
    }
}
void build(int a[],ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    push(v,tl,tr);
    ll tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]=new_val*(r-l+1);
        marked[v]=true;
    }
    else{
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
int a[MAXN],mx[MAXN];
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
    for(int T=1;T<=te;T++){
        ll n,m;
        cin>>n>>m;
        ll ans=1;
        for(int i=1;i<=n;i++) a[i]=i,mx[i]=i;
        for(int i=0;i<=4*n;i++) t[i]=lazy[i]=marked[i]=0;
        build(a,1,1,n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(u>v) swap(u,v);
            u=sum(1,1,n,u,u);
            v=mx[sum(1,1,n,v,v)];
            update(1,1,n,u,v,u);
            mx[u]=max(mx[u],v);
            // for(int i=1;i<=n;i++) cout<<sum(1,1,n,i,i)<<' ';
            // cout<<'\n';
            ll curr=(n*n-sum(1,1,n,1,n))%MOD;
            // cout<<curr<<'\n';
            (ans*=curr)%=MOD;
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}