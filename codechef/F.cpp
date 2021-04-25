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
int MOD = 1e9 + 7;
ll power(ll a, ll b) { //a^b
    ll res = 1;
    a = a % MOD;
    while (b > 0) {
        if (b & 1) {res = (res * a) % MOD; b--;}
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll fermat_inv(ll y) {return power(y, MOD - 2);}
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
ll min(ll a, ll b) {return (a > b) ? b : a;}
ll max(ll a, ll b) {return (a > b) ? a : b;}

struct node{
    ll s,c;
    node(){
        c=s=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.s=s+other.s;
        sum.c=c+other.c;
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
    ll sum(ll l,ll r){
        return sum(1,1,n,l,r).s;
    }
    ll cnt(ll l,ll r){
        return sum(1,1,n,l,r).c;
    }
    void update(ll v,ll tl,ll tr,ll pos,ll new_val,ll cnt)
    {
        if(tl==tr)
            t[v].s+=new_val,t[v].c+=cnt;
        else{
            ll tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val,cnt);
            else
                update(2*v+1,tm+1,tr,pos,new_val,cnt);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(ll idx,ll a,ll c){
        update(1,1,n,idx,a,c);
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

    int te = 1;
    //cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--) {
        int n,m,q;
        cin>>n>>m>>q;
        ll ans=0,t[q],x[q],y[q],a[n+1]={0},b[m+1]={0};
        map<int,int>mp;
        for(int i=0;i<q;i++){
            cin>>t[i]>>x[i]>>y[i];
            mp[y[i]]++;
        }
        int c=1;
        for(auto i:mp)
            mp[i.ff]=c++;
        SegTree S(c+5),T(c+5);
        for(int i=0;i<n;i++)
        	S.update(mp[a[i+1]],a[i+1],1);
        for(int i=0;i<m;i++)
        	T.update(mp[b[i+1]],b[i+1],1);
        for(int i=0;i<q;i++){
            if(t[i]==1){
                ans-=T.sum(mp[a[x[i]]]+1,c);
                ans-=a[x[i]]*T.cnt(1,mp[a[x[i]]]);
                //cout<<ans<<' ';
                S.update(mp[a[x[i]]],-a[x[i]],-1);
                a[x[i]]=y[i];
                S.update(mp[a[x[i]]],a[x[i]],1);
                ans+=T.sum(mp[a[x[i]]]+1,c);
                ans+=a[x[i]]*T.cnt(1,mp[a[x[i]]]);
            }
            else{
                ans-=S.sum(mp[b[x[i]]]+1,c);
                ans-=b[x[i]]*S.cnt(1,mp[b[x[i]]]);
                ///cout<<ans<<' ';
                T.update(mp[b[x[i]]],-b[x[i]],-1);
                b[x[i]]=y[i];
                T.update(mp[b[x[i]]],b[x[i]],1);
                ans+=S.sum(mp[b[x[i]]]+1,c);
                ans+=b[x[i]]*S.cnt(1,mp[b[x[i]]]);
            }
            cout<<ans<<'\n';
        }
    }
}