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
        l++,r++;
        return sum(1,1,n,l,r);
    }
    void update(int v,int tl,int tr,int pos,ll x,ll y)
    {
        if(tl==tr)
            t[v].x+=x,t[v].y+=y;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,x,y);
            else
                update(2*v+1,tm+1,tr,pos,x,y);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,ll x,ll y){
        idx++;
        update(1,1,n,idx,x,y);
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
    for(int T=1;T<=te;T++){
        int n,k,x,d;
        cin>>n>>k>>x>>d;
        int cnt[n]={0};
        vi st[d+1];
        vi e[d+1];
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int p,l,r;
            cin>>p>>l>>r;
            p--;
            st[l].pb(p);
            e[r].pb(p);
        }
        SegTree ST(m+5);
        for(int i=0;i<n;i++) ST.update(0,1,0);
        for(int i=0;i<x;i++){
            for(int j:st[i]){
                ST.update(cnt[j],-1,-cnt[j]);
                cnt[j]++;
                ST.update(cnt[j],1,cnt[j]);
            }
        }
        ll ans=m;
        for(int i=x;i<=d;i++){
            for(int j:e[i-x]){
                ST.update(cnt[j],-1,-cnt[j]);
                cnt[j]--;
                ST.update(cnt[j],1,cnt[j]);
            }
            int l=0,r=m,curr;
            while(l<=r){
                int mid=(l+r)/2;
                if(ST.sum(0,mid).x<k) l=mid+1;
                else curr=mid,r=mid-1;
            }
            // cout<<i<<' '<<curr<<'\n';
            // for(int i=0;i<n;i++) cout<<cnt[i]<<' ';
            // cout<<'\n';
            // for(int i=0;i<=m;i++) cout<<ST.sum(i,i).x<<'.'<<ST.sum(i,i).y<<' ';
            // cout<<'\n';
            if(ST.sum(0,curr).x>k) ans=min(ans,ST.sum(0,curr-1).y+(k-ST.sum(0,curr-1).x)*curr);
            else ans=min(ans,ST.sum(0,curr).y);
            for(int j:st[i]){
                ST.update(cnt[j],-1,-cnt[j]);
                cnt[j]++;
                ST.update(cnt[j],1,cnt[j]);
            }
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}