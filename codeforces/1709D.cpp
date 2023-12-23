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
struct Node{
    int x;
    Node():x(0){}
    Node operator +(const Node &r){
        Node res;
        res.x=max(x,r.x);
        return res;
    }
};
struct SegTree{
    vector<Node>v;
    SegTree():v(vector<Node>(800005)){
    }
    Node sum(int i,int tl,int tr,int l,int r){
        if(l>r) return Node();
        if(l==tl&&r==tr) return v[i];
        int tm=(tl+tr)/2;
        return sum(2*i,tl,tm,l,min(r,tm))+sum(2*i+1,tm+1,tr,max(l,tm+1),r);
    }
    void update(int i,int tl,int tr,int idx,int x){
        if(tl>tr) return;
        if(tl==tr){
            v[i].x=x;
            return;
        }
        int tm=(tl+tr)/2;
        if(idx<=tm) update(2*i,tl,tm,idx,x);
        else update(2*i+1,tm+1,tr,idx,x);
        v[i]=v[2*i]+v[2*i+1];
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
        int n,m;
        cin>>n>>m;
        int a[m+1];
        for(int i=1;i<=m;i++) cin>>a[i];
        SegTree ST;
        for(int i=1;i<=m;i++) ST.update(1,1,m,i,a[i]);
        int q;
        cin>>q;
        while(q--){
            int xi,yi,xf,yf,k;
            cin>>xi>>yi>>xf>>yf>>k;
            if(abs(xf-xi)%k||abs(yf-yi)%k||xi<=a[yi]||xf<=a[yf]){
                cout<<"NO\n";
                continue;
            }
            int mx=ST.sum(1,1,m,min(yi,yf)+1,max(yi,yf)-1).x;
            int top=n/k*k+xi%k;
            if(top>n) top-=k;
            if(top>mx) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}