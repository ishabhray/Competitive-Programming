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
    ll s,m;
    node(){
        s=m=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.s=(s+other.s);
        sum.m=min(m,s+other.m);
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
    bool sum(int l,int r){
        node x=sum(1,1,n,l,r);
        return !(x.s||x.m);
    }
    void update(int v,int tl,int tr,int pos,int new_val)
    {
        if(tl==tr)
            t[v].s=t[v].m=new_val;
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
        int n,q;
        string s;
        cin>>n>>q>>s;
        SegTree ST(n+5);
        for(int i=0;i<n;i++){
            int x=(s[i]=='(')? 1:-1;
            ST.update(i+1,x);
        }
        for(int i=0;i<q;i++){
            int t,l,r;
            cin>>t>>l>>r;
            if(t==1){
                swap(s[l-1],s[r-1]);
                int x=(s[l-1]=='(')? 1:-1;
                ST.update(l,x);
                x=(s[r-1]=='(')? 1:-1;
                ST.update(r,x);
            }
            else{
                if(ST.sum(l,r)) cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }
}