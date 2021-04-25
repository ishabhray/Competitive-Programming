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
#define MAXN 100005
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

struct node{
    bitset<26>v;
    node operator +(const node& other){
        node sum=node();
        sum.v=v|other.v;
        return sum;
    }
};

node t[4*MAXN];
void build(string &a,int v,int tl,int tr)
{
    if(tl==tr)
        t[v].v[a[tl-1]-'a']=1;
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
void update(int v,int tl,int tr,int pos,char new_val)
{
    if(tl==tr){
        t[v].v.reset();
        t[v].v[new_val-'a']=1;
    }
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    while(te--){
        string s;
        cin>>s;
        int n=s.size(),m;
        cin>>m;
        build(s,1,1,n);
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(x==1){
                int pos;
                char ch;
                cin>>pos>>ch;
                update(1,1,n,pos,ch);
            }
            if(x==2){
                int l,r;
                cin>>l>>r;
                node z=sum(1,1,n,l,r);
                cout<<z.v.count()<<'\n';
            }
        }
    }
}