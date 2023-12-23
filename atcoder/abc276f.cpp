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
const int MOD=998244353;
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
struct mi {
    int v; explicit operator int() const { return v; } 
    mi():v(0) {}
    mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a; }
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // won't work for negative p
    return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }
struct node{
    mi x,y;
    node(){
        x=y=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=(x+other.x);
        sum.y=(y+other.y);
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
    mi sum(int l,int r){
        return sum(1,1,n,l,r).y;
    }
    mi sum1(int l,int r){
        return sum(1,1,n,l,r).x;
    }
    void update(int v,int tl,int tr,int pos,ll new_val)
    {
        if(tl==tr)
            t[v].x+=new_val,t[v].y+=1;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,ll a){
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        ll a[n];
        for(ll &i:a) cin>>i;
        SegTree st(200005);
        mi ans=0;
        ll c[200005]={0};
        for(ll j=0;j<n;j++){
            ll i=a[j];
            ans-=i*c[i]%MOD*c[i];
            ans-=2*i*c[i]%MOD*st.sum(1,i-1);
            c[i]++;
            st.update(i,i);
            // for(int i=1;i<=7;i++) cout<<st.sum(i,i).v<<'.'<<st.sum1(i,i).v<<' ';
            // cout<<'\n'<<ans.v<<' ';
            ans+=i*c[i]%MOD*c[i];
            // cout<<ans.v<<' ';
            ans+=2*i*c[i]%MOD*st.sum(1,i-1);
            // cout<<ans.v<<' ';
            ans+=2*st.sum1(i+1,200001);
            cout<<(ans*fermat_inv((j+1)*(j+1)%MOD)).v<<'\n';
        }
    }
}