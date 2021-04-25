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

ii t[4*MAXN];
int update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr){
        t[v].ss=new_val;
        t[v].ff=t[v].ss;
    }
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v].ff=max(t[2*v].ff,t[2*v+1].ff);
    }
}
int sum(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(tl==l&&tr==r)
        return t[v].ff;
    int tm=(tl+tr)/2;
    return max(sum(2*v,tl,tm,l,min(r,tm)),sum(2*v+1,tm+1,tr,max(l,tm+1),r));
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        int a[n];
        map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int c=0;
        for(auto i:m)
            m[i.ff]=c++;
        for(int i=0;i<=4*c;i++)
            t[i]={0,0};
        for(int i=0;i<n;i++)
            a[i]=m[a[i]];
        for(int i=0;i<n;i++){
            int x=sum(1,1,c,1,a[i]);
            //cout<<x<<' ';
            update(1,1,c,a[i],x+1);
        }
        cout<<n-sum(1,1,c,1,c)<<'\n';
    }
}