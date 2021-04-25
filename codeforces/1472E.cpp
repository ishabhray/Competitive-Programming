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

ll min(ll a, ll b) {return (a > b) ? b : a;}
ll max(ll a, ll b) {return (a > b) ? a : b;}

struct node{
    ll x,id;
    node(){
        x=1e18;
        id=0;
    }
    node operator +(const node& other){
        node sum=node();
        if(x<=other.x)
            sum.x=x,sum.id=id;
        else
            sum.x=other.x,sum.id=other.id;
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
    node sum(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        int tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    node sum(int r){
        return sum(1,1,n,1,r);
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
    void update(int idx,node new_val){
        update(1,1,n,idx,new_val);
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
    cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--) {
        int n;
        cin>>n;
        int h[n],w[n];
        map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>h[i]>>w[i];
            m[h[i]]++,m[w[i]]++;
        }
        int c=1;
        for(auto i:m)
            m[i.ff]=c++;
        SegTree x(c+5);
        for(int i=0;i<n;i++){
            h[i]=m[h[i]];
            w[i]=m[w[i]];
            node z=node();
            z.x=w[i],z.id=i+1;
            x.update(h[i],z);
            z.x=h[i];
            x.update(w[i],z);
        }
        for(int i=0;i<n;i++){
            node mn=x.sum(h[i]-1);
            if(mn.x<w[i]){
                cout<<mn.id<<' ';
                continue;
            }
            mn=x.sum(w[i]-1);
            if(mn.x<h[i])
                cout<<mn.id<<' ';
            else
                cout<<-1<<' ';
        }
        cout<<'\n';
    }
}