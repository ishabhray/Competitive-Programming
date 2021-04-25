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
        x=y=1e18;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=min(x,other.x);
        sum.y=min(y,other.y);
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
    node sum(ll v,ll tl,ll tr,ll l,ll r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        ll tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    node sum(ll l,ll r){
        return sum(1,1,n,l,r);
    }
    void update(ll v,ll tl,ll tr,ll pos,node new_val)
    {
        if(tl==tr)
            t[v]=new_val;
        else{
            ll tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(ll idx,node a){
        update(1,1,n,idx,a);
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        pll a[n];
        ll ans=0;
        map<ll,int>m;
        for(int i=0;i<n;i++){
            cin>>a[i].ff>>a[i].ss;
            ans+=a[i].ss;
            m[a[i].ff+a[i].ss]++;
            m[a[i].ff]++;
        }
        sort(a,a+n);
        int c=1;
        for(auto i:m)
            m[i.ff]=c++;
        SegTree ST(c+5);
        ll dp[n];
        dp[0]=0;
        node curr;
        curr.x=0,curr.y=-a[0].ff-a[0].ss;
        ST.update(m[a[0].ff+a[0].ss],curr);
        for(int i=1;i<n;i++){
            dp[i]=ST.sum(m[a[i].ff],c).x;
            dp[i]=min(dp[i],a[i].ff+ST.sum(1,m[a[i].ff]).y);
            curr.x=dp[i],curr.y=dp[i]-a[i].ff-a[i].ss;
            ST.update(m[a[i].ff+a[i].ss],curr);
        }
        //for(int i=0;i<n;i++)
            //cout<<dp[i]<<' ';
        cout<<ans+dp[n-1];
    }
}