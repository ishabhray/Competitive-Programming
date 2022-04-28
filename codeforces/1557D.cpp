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
struct node{
    ll x,idx;
    node(){
        x=idx=0;
    }
    node operator +(const node& other){
        node sum=node();
        if(x>=other.x) sum.x=x,sum.idx=idx;
        else sum=other;
        return sum;
    }
};
struct SegTree {
    vector<node>t,lazy;
    ll n;
    SegTree(ll n){
        this->n = n;
        t.assign(4*n,node());
        lazy.assign(4*n,node());
    }
    void push(ll v,ll l,ll r){
        t[2*v]=t[2*v]+lazy[v];
        t[2*v+1]=t[2*v+1]+lazy[v];
        lazy[2*v]=lazy[2*v]+lazy[v];
        lazy[2*v+1]=lazy[2*v+1]+lazy[v];
        lazy[v]=node();
    }
    node sum(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    node sum(int l,int r){
        return sum(1,1,n,l,r);
    }
    void update(int v,int tl,int tr,int l,int r,node new_val)
    {
        if(l>r) return;
        if(l==tl&&r==tr)
            t[v]=t[v]+new_val,lazy[v]=lazy[v]+new_val;
        else{
            push(v,tl,tr);
            int tm=(tl+tr)/2;
            update(2*v,tl,tm,l,min(r,tm),new_val);
            update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int l,int r,node a){
        update(1,1,n,l,r,a);
    }
};
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
        int n,k;
        cin>>n>>k;
        vv<ii> adj[n+1];
        map<int,int>m;
        for(int i=0;i<k;i++){
            int x,l,r;
            cin>>x>>l>>r;
            adj[x].pb({l,r});
            m[l]++,m[r]++;
        }
        int c=0;
        for(auto i:m){
            m[i.ff]=++c;
        }
        SegTree ST(c+5);
        for(auto &i:adj){
            for(auto &j:i){
                j.ff=m[j.ff];
                j.ss=m[j.ss];
            }
        }
        int pre[n+1]={0},cnt[n+1]={0};
        for(int i=1;i<=n;i++){
            node mx;
            for(auto j:adj[i]){
                mx=mx+ST.sum(j.ff,j.ss);
            }
            pre[i]=mx.idx;
            cnt[i]=mx.x+1;
            mx.idx=i,mx.x++;
            for(auto j:adj[i]){
                ST.update(j.ff,j.ss,mx);
            }
            // cout<<pre[i]<<' '<<cnt[i]<<'\n';
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,cnt[i]);
        set<int>s;
        for(int i=1;i<=n;i++){
            if(cnt[i]==ans){
                s.insert(i);
                while(pre[i]){
                    s.insert(pre[i]);
                    i=pre[i];
                }
                break;
            }
        }
        cout<<n-ans<<'\n';
        for(int i=1;i<=n;i++){
            if(s.count(i)==0) cout<<i<<' ';
        }
        cout<<'\n';
    }
}