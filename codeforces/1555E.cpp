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
#define MAXN 1000005
#define MOD 1000000007
//bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    ll tm=(l+r)/2;
    t[2*v]+=lazy[v];
    t[2*v+1]+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 1e9;
    if(l==tl&&r==tr)
        return t[v];
    push(v,tl,tr);
    ll tm=(tl+tr)/2;
    return min(sum(2*v,tl,tm,l,min(r,tm)),sum(2*v+1,tm+1,tr,max(l,tm+1),r));
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]+=new_val;
        lazy[v]+=new_val;
    }
    else{
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=min(t[2*v],t[2*v+1]);
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
        int n,m;
        cin>>n>>m;
        vv<pair<int,ii>>v;
        for(int i=0;i<n;i++){
            int l,r,w;
            cin>>l>>r>>w;
            v.pb({w,{l,r}});
        }
        sort(all(v));
        int ans=1e9;
        int curr=0;
        for(int i=0;i<n;i++){
            while(curr<n&&!sum(1,1,m,1,m-1)){
                update(1,1,m,v[curr].ss.ff,v[curr].ss.ss-1,1);
                curr++;
            }
            if(sum(1,1,m,1,m-1)) ans=min(ans,v[curr-1].ff-v[i].ff);
            update(1,1,m,v[i].ss.ff,v[i].ss.ss-1,-1);
        }
        cout<<ans<<'\n';
    }
}
