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
    ll mx,mn;
    node(){
        mx=0,mn=1e9;
    }
    node operator +(const node& other){
        node sum=node();
        sum.mx=max(mx,other.mx);
        sum.mn=min(mn,other.mn);
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
    ll range_max(int l,int r){
        return sum(1,1,n,l,r).mx;
    }
    ll range_min(int l,int r){
        return sum(1,1,n,l,r).mn;
    }
    void update(int v,int tl,int tr,int pos,ll new_val)
    {
        if(tl==tr)
            t[v].mx=t[v].mn=new_val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(int idx,ll a){
        update(1,1,n,idx,a);
    }
};

#define K 25
int st[MAXN][K + 1],st1[MAXN][K + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    int lg[MAXN+1];
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++) lg[i] = lg[i/2] + 1;

    while(te--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        int dp[n]={0};

        for (int i = 0; i < n; i++)
            st[i][0] = a[i], st1[i][0] = a[i];

        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]),st1[i][j] = max(st1[i][j-1], st1[i + (1 << (j - 1))][j - 1]);
        int idx[n+1]={0};
        idx[a[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i-1]<a[i]){
                int l=0,r=i-1,x;
                while(l<=r){
                    int mid=(l+r)/2;
                    int L=mid,R=i-1;
                    int j = lg[R - L + 1];
                    int mx=max(st1[L][j], st1[R - (1 << j) + 1][j]);
                    if(mx>a[i]) l=mid+1;
                    else{
                        r=mid-1;
                        x=mid;
                    }
                }
                int L=x,R=i-1;
                int j = lg[R - L + 1];
                int mn = min(st[L][j], st[R - (1 << j) + 1][j]);
                dp[i]=1+dp[idx[mn]];
            }
            else{
                int l=0,r=i-1,x;
                while(l<=r){
                    int mid=(l+r)/2;
                    int L=mid,R=i-1;
                    int j = lg[R - L + 1];
                    int mn=min(st[L][j], st[R - (1 << j) + 1][j]);
                    if(mn<a[i]) l=mid+1;
                    else{
                        r=mid-1;
                        x=mid;
                    }
                }
                int L=x,R=i-1;
                int j = lg[R - L + 1];
                int mx = max(st1[L][j], st1[R - (1 << j) + 1][j]);
                dp[i]=1+dp[idx[mx]];
            }
            idx[a[i]]=i;
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<' ';
        // cout<<'\n';
        cout<<dp[n-1]<<'\n';
    }
}