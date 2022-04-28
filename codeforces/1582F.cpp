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
#define MAXN 100005
#define M 515
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
    bitset<M>x;
    node(){
        x.reset();
        x[0]=1;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=(x|other.x);
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
    bitset<M> sum(int l,int r){
        l++,r++;
        return sum(1,1,n,l,r).x;
    }
    void update(int v,int tl,int tr,int pos,bitset<M>new_val)
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
    void update(int idx,bitset<M>a){
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n];
        for(int &i:a) cin>>i;
        vi ans;
        SegTree ST(M+5);
        for(int i=0;i<n;i++){
            bitset<M>curr,pre;
            pre=ST.sum(0,a[i]-1);
            curr=pre;
            for(int j=0;j<M;j++){
                if(pre[j]) curr[j^a[i]]=1;
            }
            ST.update(a[i],curr);
            // cout<<a[i]<<' '<<curr<<'\n';
        }
        for(int i=0;i<=512;i++){
            if(ST.sum(0,M)[i]) ans.pb(i);
        }
        sort(all(ans));
        cout<<ans.size()<<'\n';
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}