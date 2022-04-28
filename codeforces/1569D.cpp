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
    ll x;
    node(){
        x=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=(x+other.x);
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
    SegTree(vector<ll>&a)
        : SegTree(a.size()) {
        build(a,1,1,n);
    }
    void build(vector<ll>&a,int v,int tl,int tr)
    {
        if(tl==tr)
            t[v].x=a[tl-1];
        else{
            int tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            t[v]=t[v*2]+t[v*2+1];
        }
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
    ll sum(int l,int r){
        l++,r++;
        return sum(1,1,n,l,r).x;
    }
    void update(int v,int tl,int tr,int pos,int new_val)
    {
        if(tl==tr)
            t[v].x+=new_val;
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
        idx++;
        update(1,1,n,idx,a);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,k;
        cin>>n>>m>>k;
        set<int>x,y;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            x.insert(a);
        }
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            y.insert(a);
        }
        map<int,vi>v,h;
        vv<ii> ver,hor;
        vi xx,yy;
        for(int i=0;i<k;i++){
            int u,v;
            cin>>u>>v;
            if(x.count(u)&&y.count(v)) continue;
            if(x.count(u)) ver.pb({u,v});
            else hor.pb({v,u});
        }
        ll ans=0;
        for(auto i:ver) v[i.ff].pb(i.ss),xx.pb(i.ss);
        for(auto i:hor) h[i.ff].pb(i.ss),yy.pb(i.ss);
        for(auto &i:v) sort(all(i.ss));
        for(auto &i:h) sort(all(i.ss));
        sort(all(xx));
        sort(all(yy));
        for(int i=0;i<ver.size();i++){
            int up=1e6,lo=0;
            auto it=y.lower_bound(ver[i].ss);
            if(it!=y.end())
                up=*it;
            if(it!=y.begin()){
                it--;
                lo=*it;
            }
            auto it1=lower_bound(all(xx),up);
            it1--;
            int cnt=it1-lower_bound(all(xx),lo);
            it1=lower_bound(all(v[ver[i].ff]),up);
            it1--;
            cnt-=it1-lower_bound(all(v[ver[i].ff]),lo);
            ans+=cnt;
        }
        for(int i=0;i<hor.size();i++){
            int up=1e6,lo=0;
            auto it=x.lower_bound(hor[i].ss);
            if(it!=x.end())
                up=*it;
            if(it!=x.begin()){
                it--;
                lo=*it;
            }
            auto it1=lower_bound(all(yy),up);
            it1--;
            int cnt=it1-lower_bound(all(yy),lo);
            it1=lower_bound(all(h[hor[i].ff]),up);
            it1--;
            cnt-=it1-lower_bound(all(h[hor[i].ff]),lo);
            ans+=cnt;
        }
        cout<<ans/2<<'\n';
    }
}
