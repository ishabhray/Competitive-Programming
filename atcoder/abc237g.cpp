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
bool small_marked[4*MAXN],large_marked[4*MAXN];
ll small_t[4*MAXN],small_lazy[4*MAXN];
ll large_t[4*MAXN],large_lazy[4*MAXN];

void push(ll t[],bool marked[],ll lazy[],ll v,ll l,ll r){
    if(marked[v]){
        ll tm=(l+r)/2;
        t[2*v]=lazy[v]*(tm-l+1);
        t[2*v+1]=lazy[v]*(r-tm);
        lazy[2*v]=lazy[v];
        lazy[2*v+1]=lazy[v];
        marked[2*v]=marked[2*v+1]=true;
        lazy[v]=0;
        marked[v]=false;
    }
}
void build(ll t[],bool marked[],ll lazy[],ll a[],ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(t,marked,lazy,a,v*2,tl,tm);
        build(t,marked,lazy,a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum(ll t[],bool marked[],ll lazy[],ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    push(t,marked,lazy,v,tl,tr);
    ll tm=(tl+tr)/2;
    return sum(t,marked,lazy,2*v,tl,tm,l,min(r,tm))+sum(t,marked,lazy,2*v+1,tm+1,tr,max(l,tm+1),r);
}
void update(ll t[],bool marked[],ll lazy[],ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]=new_val*(r-l+1);
        marked[v]=true;
        lazy[v]=new_val;
    }
    else{
        push(t,marked,lazy,v,tl,tr);
        ll tm=(tl+tr)/2;
        update(t,marked,lazy,2*v,tl,tm,l,min(r,tm),new_val);
        update(t,marked,lazy,2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,q,x;
        cin>>n>>q>>x;
        int p[n];
        for(int &i:p) cin>>i;
        ll small[n+1]={0},large[n+1]={0},ans;
        for(int i=0;i<n;i++){
            if(p[i]<x) small[i+1]++;
            else if(p[i]>x) large[i+1]++;
            else ans=i+1;
        }
        build(small_t,small_marked,small_lazy,small,1,1,n);
        build(large_t,large_marked,large_lazy,large,1,1,n);
        while(q--){
            int t,l,r;
            cin>>t>>l>>r;
            int sm=sum(small_t,small_marked,small_lazy,1,1,n,l,r);
            int big=sum(large_t,large_marked,large_lazy,1,1,n,l,r);
            if(t==1){;
                update(small_t,small_marked,small_lazy,1,1,n,l,l+sm-1,1);
                update(small_t,small_marked,small_lazy,1,1,n,l+sm,r,0);
                update(large_t,large_marked,large_lazy,1,1,n,l,r-big,0);
                update(large_t,large_marked,large_lazy,1,1,n,r-big+1,r,1);
                if(sm+big!=r-l+1) ans=l+sm;
            }
            else{
                update(large_t,large_marked,large_lazy,1,1,n,l,l+big-1,1);
                update(large_t,large_marked,large_lazy,1,1,n,l+big,r,0);
                update(small_t,small_marked,small_lazy,1,1,n,l,r-sm,0);
                update(small_t,small_marked,small_lazy,1,1,n,r-sm+1,r,1);
                if(sm+big!=r-l+1) ans=l+big;
            }
        }
        cout<<ans<<'\n';
    }
}