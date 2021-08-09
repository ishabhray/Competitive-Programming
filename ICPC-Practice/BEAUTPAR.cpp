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
    ll x,y;
    node(){
        x=0;
        y=0;
    }
    node(ll xx,ll yy){
        x=xx;
        y=yy;
    }
    node operator +(const node& other){
        node sum=node();
        if(x>=other.x)
            sum.y=y;
        else sum.y=other.y;
        sum.x=max(x,other.x);
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
    void update(int v,int tl,int tr,int pos,node new_val)
    {
        if(tl==tr)
            t[v]=t[v]+new_val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,node a){
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
        int n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        vl pre(n+1,0);
        map<ll,int>m;
        m[0]++;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+a[i];
            m[pre[i+1]]++;
        }
        int c=0;
        for(auto i:m){
            m[i.ff]=++c;
        }
        SegTree ST(c+5);
        node dp[n+1];
        for(int i=1;i<=n;i++){
            dp[i]=ST.sum(1,m[pre[i]]-1);
            if(pre[i]>0)
                dp[i].x++;
            ST.update(m[pre[i]],node(dp[i].x,i));
            // cout<<pre[i]<<' '<<dp[i].x<<' '<<dp[i].y<<'\n';
        }
        if(dp[n].x>=k){
            cout<<"YES\n";
            vi v;
            int j=n;
            while(v.size()<k){
                v.pb(j);
                j=dp[j].y;
            }
            v.pb(0);
            reverse(all(v));
            for(int i=1;i<v.size();i++)
            cout<<v[i]-v[i-1]<<' ';
            cout<<'\n';
        }
        else cout<<"NO\n";
    }
}