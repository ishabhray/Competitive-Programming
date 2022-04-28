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
        x=1e9,y=0;
    }
    node operator +(const node& other){
        node sum=node();
        if(x<=other.x) sum.x=x,sum.y=y;
        else sum.x=other.x,sum.y=other.y;
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
    node sum(int l,int r){
        return sum(1,1,n,l,r);
    }
    void update(int v,int tl,int tr,int pos,ll new_val,ll b)
    {
        if(tl==tr)
            t[v].x=new_val,t[v].y=b;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val,b);
            else
                update(2*v+1,tm+1,tr,pos,new_val,b);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,ll a,ll b){
        update(1,1,n,idx,a,b);
    }
};
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
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
        int a[n],b[n];
        for(int &i:a) cin>>i;
        for(int &i:b) cin>>i;
        int dp[n+1],back[n+1];
        for(int i=0;i<=n;i++) dp[i]=1e9;
        queue<int>q;
        SegTree ST(n+5);
        vi adj[n+1];
        for(int i=0;i<n;i++){
            adj[i+1+b[i]].pb(i+1);
            if(a[i]>=i+1){
                dp[i+1]=1;
                back[i+1]=0;
                q.push(i+1);
            }
            else{
                ST.update(i+1,i+1-a[i],i+1);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int i:adj[a]){
                node mn=ST.sum(i,n);
                while(mn.x<=i){
                    int x=mn.y;
                    if(dp[x]>1+dp[a]){
                        dp[x]=1+dp[a];
                        back[x]=i;
                        q.push(x);
                    }
                    ST.update(x,1e9,0);
                    mn=ST.sum(i,n);
                }
            }
        }
        if(dp[n]==1e9) {cout<<"-1\n"; continue;}
        cout<<dp[n]<<'\n';
        vi ans;
        int i=back[n];
        while(i){
            ans.pb(i);
            i+=b[i-1];
            i=back[i];
        }
        ans.pb(0);
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}