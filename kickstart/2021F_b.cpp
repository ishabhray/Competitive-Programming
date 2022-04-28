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
    ll x,s;
    node(){
        x=s=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=(x+other.x);
        sum.s=(s+other.s);
        return sum;
    }
};
struct SegTree {
    vector<node>t;
    ll n;
    SegTree(ll n){
        this->n = n;
        t.assign(4*n,node());
    }
    node sum(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        int tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    node sum(int l,int r){
        return sum(1,1,n,l,r);
    }
    void update(int v,int tl,int tr,int pos,int new_val)
    {
        if(tl==tr)
            t[v].x+=new_val,t[v].s+=new_val*tl;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,int a){
        update(1,1,n,idx,a);
    }
};
vi st[300005],en[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        ll d,n,k;
        cin>>d>>n>>k;
        for(int i=0;i<=3e5;i++) st[i].clear(),en[i].clear();
        for(int i=0;i<n;i++){
            ll s,e,h;
            cin>>h>>s>>e;
            st[s].pb(h);
            en[e].pb(h);
        }
        SegTree ST(MAXN);
        ll ans=0;
        for(int i=1;i<=d;i++){
            for(int j:en[i-1]) ST.update(j,-1);
            for(int j:st[i]) ST.update(j,1);
            int l=1,r=3e5,x=1;
            while(l<=r){
                int mid=(l+r)/2;
                if(ST.sum(mid,3e5).x<k) r=mid-1;
                else l=mid+1,x=mid;
            }
            if(ST.sum(x,3e5).x<=k) ans=max(ans,ST.sum(x,3e5).s);
            else ans=max(ans,ST.sum(x,3e5).s-x*(ST.sum(x,3e5).x-k));
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}