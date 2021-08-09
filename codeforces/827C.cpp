#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll int
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
        string s;
        cin>>s;
        int n=s.size(),q;
        cin>>q;
        map<char,int>m;
        m['A']=0;
        m['C']=1;
        m['G']=2;
        m['T']=3;
        vv<vv<SegTree>>ST(4,vv<SegTree>(10,SegTree(n+1)));
        for(int i=1;i<=n;i++){
            for(int j=0;j<10;j++){
                ST[m[s[i-1]]][j].update(i,1);
            }
        }
        for(int i=0;i<10;i++){
            for(int j=1;j<=n;j++)
                cout<<ST[3][i].sum(j,j)<<' ';
            cout<<'\n';
        }
        while(q--){
            int t;
            cin>>t;
            if(t==1){
                int x;
                char c;
                cin>>x>>c;
                for(int i=1;i<=10;i++){
                    ST[m[s[x-1]]][x%i].update(x,-1);
                }
                s[x-1]=c;
                for(int i=1;i<=10;i++){
                    ST[m[s[x-1]]][x%i].update(x,1);
                }
            }
            else{
                int l,r;
                string e;
                cin>>l>>r>>e;
                int ans=0;
                for(int i=0;i<e.size();i++){
                    ans+=ST[m[e[i]]][(l+i)%e.size()].sum(l,r);
                }
                cout<<ans<<'\n';
            }
        }
    }
}