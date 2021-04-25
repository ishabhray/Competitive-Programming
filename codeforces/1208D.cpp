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
#define MAXN 200005
#define MOD 1000000007
//bool marked[4*MAXN];
pll t[4*MAXN];
ll lazy[4*MAXN];

void push(ll v){
    t[2*v].ff+=lazy[v];
    t[2*v+1].ff+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
void build(ll a[],ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v].ff=a[tl],t[v].ss=tl;
    else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        if(t[2*v].ff<t[2*v+1].ff)
            t[v]=t[2*v];
        else
            t[v]=t[2*v+1];
    }
}
pll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return {INT_MAX,0};
    if(l==tl&&r==tr)
        return t[v];
    push(v);
    ll tm=(tl+tr)/2;
    pll x=sum(2*v,tl,tm,l,min(r,tm));
    pll y=sum(2*v+1,tm+1,tr,max(l,tm+1),r);
    if(x.ff<y.ff)
        return x;
    else
        return y;
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v].ff+=new_val;
        lazy[v]+=new_val;
    }
    else{
        push(v);
        ll tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        if(t[2*v].ff<t[2*v+1].ff)
            t[v]=t[2*v];
        else
            t[v]=t[2*v+1];
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
        int n;
        cin>>n;
        ll a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        int curr=0,ans[n+1]={0};
        while(curr<n){
            pll x=sum(1,1,n,1,n);
            ans[x.ss]=++curr;
            update(1,1,n,x.ss+1,n,-curr);
            update(1,1,n,x.ss,x.ss,1e15);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}