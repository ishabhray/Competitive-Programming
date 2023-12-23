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
    ll mn,mx;
    node(){
        mx=-1e18;
        mn=1e18;
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
    void update(int v,int tl,int tr,int pos,ll new_val)
    {
        if(tl==tr)
            t[v].mx=t[v].mn=new_val;
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
        int n;
        cin>>n;
        ll a[n];
        for(ll &i:a) cin>>i;
        stack<ll> g;
        int l[n],r[n];
        for(int i=0;i<n;i++) l[i]=-1,r[i]=n+1;
        for(int i=0;i<n;i++){
        	while(!g.empty()&&a[i]>a[g.top()]){
        		r[g.top()]=i+1;
        		g.pop();
        	}
        	g.push(i);
        }
        while(!g.empty())
        	g.pop();
        for(int i=n-1;i>=0;i--){
        	while(!g.empty()&&a[i]>a[g.top()]){
        		l[g.top()]=i+1;
        		g.pop();
        	}
        	g.push(i);
        }
        ll pre[n+1]={0};
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
        SegTree ST(n+5);
        for(int i=0;i<=n;i++) ST.update(i,pre[i]);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(a[i]<=0) continue;
            auto x=ST.sum(l[i]+1,i+1).mn,y=ST.sum(i+1,r[i]-1).mx;
            // cout<<l[i]<<' '<<r[i]<<'\n';
            // cout<<y<<' '<<x<<'\n';
            if(y-x>a[i]){
                ans=false;
                break;
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
