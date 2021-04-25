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
int MOD=1e9+7;

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

struct node{
    int mx,pos;
    node(){
        mx=0,pos=0;
    }
    node operator +(const node& other){
        node sum=node();
        if(mx>other.mx)
            sum.mx=mx,sum.pos=pos;
        else
            sum.mx=other.mx,sum.pos=other.pos;
        return sum;
    }
};
node t[600050];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v].mx=a[tl],t[v].pos=tl;
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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<n;i++)
            cin>>a[i];
        a[n]=n;
        ll dp[n+1]={0};
        dp[n]=0;
        build(a,1,1,n);
        for(int i=n-1;i>=1;i--){
            int m=sum(1,1,n,i+1,a[i]).pos;
            dp[i]=dp[m]-(a[i]-m)+n-i;
            //cout<<m<<' '<<dp[m]<<' '<<dp[i]<<'\n';
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans+=dp[i];
        cout<<ans<<'\n';
    }
}