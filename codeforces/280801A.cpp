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
ll marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    ll tm=(l+r)/2;
    if(marked[v]!=-1){
        t[2*v]=marked[v]*(tm-l+1);
        t[2*v+1]=marked[v]*(r-tm);
        marked[2*v]=marked[2*v+1]=marked[v];
        lazy[2*v]=lazy[2*v+1]=0;
        marked[v]=-1;
    }
    if(lazy[v]){
        t[2*v]+=lazy[v]*(tm-l+1);
        t[2*v+1]+=lazy[v]*(r-tm);
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        lazy[v]=0;
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
void update(ll ty,ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        push(v,l,r);
        if(ty==1){
            t[v]=new_val*(r-l+1);
            marked[v]=new_val;
            lazy[v]=0;
        }
        else if(ty==2){
            t[v]+=new_val*(r-l+1);
            lazy[v]+=new_val;
        }
    }
    else{
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update(ty,2*v,tl,tm,l,min(r,tm),new_val);
        update(ty,2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=t[2*v]+t[2*v+1];
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
        memset(marked,-1,sizeof(marked));
        for(int i=0;i<m;i++){
            ll ty,l,r,v;
            cin>>ty;
            if(ty==1){
                cin>>l>>r>>v;
                update(ty,1,1,n,l+1,r,v);
            }
            else if(ty==2){
                cin>>l>>r>>v;
                update(ty,1,1,n,l+1,r,v);
            }
            else{
                cin>>l>>r;
                cout<<sum(1,1,n,l+1,r)<<'\n';
            }
        }
    }
}