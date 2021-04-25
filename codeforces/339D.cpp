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
#define MAXN 200000
struct node{
    int n,t;
    node(){
        n=0,t=0;
    }
    node operator +(const node& other){
        node sum=node();
        if(t==0)
            sum.n=n|other.n,sum.t=1;
        else
            sum.n=n^other.n,sum.t=0;
        return sum;
    }
};
node t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v].n=a[tl],t[v].t=0;
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
void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        t[v].n=new_val;
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        n=(1<<n);
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        for(int i=0;i<m;i++){
            int pos,new_val;
            cin>>pos>>new_val;
            update(1,1,n,pos,new_val);
            //for(int i=1;i<=4*n;i++)
              //  cout<<t[i].n<<' ';
            //cout<<'\n';
            cout<<t[1].n<<'\n';
        }
    }
}