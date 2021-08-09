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
#define MAXN 100005
#define MOD 1000000007
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

    int te=1;
    while(te--){
        int n;
        cin>>n;
        vv<pair<int,ii>>v,w,z;
        SegTree ST(1e5+5);
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            vv<ii>pts(m);
            vv<pair<int,ii>>y;
            for(int i=0;i<m;i++) cin>>pts[i].ff>>pts[i].ss;
            if(pts[0].ff==pts[m-1].ff) y.pb({pts[0].ff,{min(pts[0].ss,pts[m-1].ss),max(pts[0].ss,pts[m-1].ss)}});
            for(int j=1;j<m;j++){
                if(pts[j].ff==pts[j-1].ff) y.pb({pts[j].ff,{min(pts[j].ss,pts[j-1].ss),max(pts[j].ss,pts[j-1].ss)}});
            }
            sort(all(y));
            for(int j=0;j<y.size();j++){
                if(ST.sum(0,y[j].ss.ff)){
                    w.pb(y[j]);
                    ST.update(y[j].ss.ff,-1);
                    ST.update(y[j].ss.ss,1);
                }
                else{
                    v.pb(y[j]);
                    ST.update(y[j].ss.ff,1);
                    ST.update(y[j].ss.ss,-1);
                }
            }
        }
        sort(all(v));
        sort(all(w));
        int q;
        cin>>q;
        int ans[q];
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            z.pb({x,{y,i}});
        }
        sort(all(z));
        int j=0,k=0;
        for(int i=0;i<q;i++){
            // cout<<z[i].ff<<' '<<z[i].ss.ff<<'\n';
            while(j<v.size()&&v[j].ff<=z[i].ff){
                ST.update(v[j].ss.ff,1);
                ST.update(v[j].ss.ss,-1);
                // cout<<v[j].ss.ff<<' '<<v[j].ss.ss<<" 1\n";
                j++;
            }
            while(k<w.size()&&w[k].ff<=z[i].ff){
                ST.update(w[k].ss.ff,-1);
                ST.update(w[k].ss.ss,1);
                // cout<<w[k].ss.ff<<' '<<w[k].ss.ss<<" -1\n";
                k++;
            }
            // for(int i=0;i<10;i++) cout<<ST.sum(0,i)<<' ';
            // cout<<'\n';
            ans[z[i].ss.ss]=ST.sum(0,z[i].ss.ff);
        }
        for(auto i:ans) cout<<i<<'\n';
    }
}