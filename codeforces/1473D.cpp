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
    ll mx,mn;
    node(){
        mx=-1e7;
        mn=1e7;
    }
    node operator +(const node& other){
        node sum=node();
        sum.mx=max(mx,other.mx);
        sum.mn=min(mn,other.mn);
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
    SegTree(vector<ll>&a)
        : SegTree(a.size()) {
        build(a,1,1,n);
    }
    void build(vector<ll>&a,int v,int tl,int tr)
    {
        if(tl==tr)
            t[v].mx=a[tl-1],t[v].mn=a[tl-1];
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
    node sum(int l,int r){
        return sum(1,1,n,l,r);
    }
    
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        string s;
        cin>>n>>m>>s;
        vl pre(n+1,0);
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+((s[i-1]=='+')?1:-1);
        SegTree st(pre);
        while(m--){
            int l,r;
            cin>>l>>r;
            node x,ans;
            ans.mn=0,ans.mx=0;
            if(l!=1){
                x=st.sum(2,l);
                //cout<<x.mn<<' '<<x.mx<<'\n';
                ans=ans+x;
            }
            if(r!=n){
                x=st.sum(r+2,n+1);
                int z=pre[r]-pre[l-1];
                //cout<<x.mn<<' '<<x.mx<<' '<<z<<'\n';
                x.mx-=z,x.mn-=z;
                ans=ans+x;
            }
            cout<<ans.mx-ans.mn+1<<'\n';
        }
    }
}