#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MAXN 100005
struct node{
    ll x;
    node(){
        x=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=(x+other.x);
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
    ll sum(int l,int r){
        return sum(1,1,n,l,r).x;
    }
    void update(int v,int tl,int tr,int pos,int new_val)
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
    void update(int idx,int a){
        update(1,1,n,idx,a);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int te = 1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while (te--)
    {
        string s;
        cin >> s;
        int n = s.size();
        ll mx=0;
        vi ans;
        unordered_map<char,int>key;
        key['A']=0;
        key['N']=1;
        key['O']=2;
        key['T']=3;
        unordered_map<int,char>key1;
        key1[0]='A';
        key1[1]='N';
        key1[2]='O';
        key1[3]='T';
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++)
            m[s[i]]++;
        vi v;
        for (auto i : m)
            v.pb(key[i.ff]);
        sort(all(v));
        do
        {
            int st[4]={0},x=1;
            for(auto i:v){
                st[i]=x;
                x+=m[key1[i]];
            }
            vi w;
            for(int i=0;i<n;i++){
                w.pb(st[key[s[i]]]++);
            }
            ll cnt=0;
            SegTree ST(n+5);
            for(int i:w){
                cnt+=i-1-ST.sum(1,i);
                ST.update(i,1);
            }
            if(cnt>=mx){
                mx=cnt;
                ans=v;
            }
        }while (next_permutation(all(v)));
        for(auto i:ans){
            for(int j=0;j<m[key1[i]];j++)
                cout<<key1[i];
        }
        cout<<'\n';
    }
}