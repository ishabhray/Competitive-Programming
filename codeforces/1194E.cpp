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
        sum.x=x+other.x;
        return sum;
    }
};
struct SegTree {
    vector<node>t;
    ll n;
    SegTree(ll n){
        this->n = n;
        t.assign(4*n+10,node());
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
        l+=5001,r+=5001;
        return sum(1,1,n,l,r).x;
    }
    void update(int v,int tl,int tr,int pos,int new_val)
    {
        if(tl==tr)
            t[v].x=new_val;
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
        idx+=5001;
        update(1,1,n,idx,a);
    }
};
bool comp(const pair<int,ii>&l,const pair<int,ii>&r){
    return l.ss.ss<r.ss.ss;
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
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        vv<pair<int,ii>>h,v;
        for(int i=0;i<n;i++){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==c)
                v.pb({a,{min(b,d),max(b,d)}});
            else
                h.pb({b,{min(a,c),max(a,c)}});
        }
        sort(all(h));
        sort(all(v),&comp);
        SegTree ST(10005);
        ll ans=0;
        for(int i=0;i<h.size();i++){
            queue<ii>stop;
            for(auto j:v){
                if(j.ff<h[i].ss.ff||j.ff>h[i].ss.ss||j.ss.ff>h[i].ff||j.ss.ss<h[i].ff)
                    continue;
                ST.update(j.ff,1);
                stop.push({j.ss.ss,j.ff});
            }
            for(int j=i+1;j<h.size();j++){
                while(!stop.empty()&&stop.front().ff<h[j].ff){
                    ST.update(stop.front().ss,0);
                    stop.pop();
                }
                if(stop.empty())
                    break;
                ll x=ST.sum(max(h[i].ss.ff,h[j].ss.ff),min(h[i].ss.ss,h[j].ss.ss));
                ans+=x*(x-1)/2;
            }
            while(!stop.empty()){
                ST.update(stop.front().ss,0);
                stop.pop();
            }
        }
        cout<<ans;
    }
}