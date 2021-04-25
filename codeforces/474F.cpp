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

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
struct node{
    int g,gcnt;
    node(){
        g=0,gcnt=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.g=gcd(g,other.g);
        if(sum.g==g)
            sum.gcnt+=gcnt;
        if(sum.g==other.g)
            sum.gcnt+=other.gcnt;
        return sum;
    }
};
ll n;
node t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v].g=a[tl],t[v].gcnt=1;
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
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
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            cout<<y-x+1-sum(1,1,n,x,y).gcnt<<'\n';
        }
    }
}