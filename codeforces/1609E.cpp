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
    int x[3][3];
    node(){
        memset(x,0,sizeof(x));
    }
    node operator +(const node& other){
        node sum=node();
        for(int l=0;l<3;l++){
            for(int r=l;r<3;r++){
                sum.x[l][r]=1e9;
                for(int i=l;i<=r;i++) sum.x[l][r]=min(sum.x[l][r],x[l][i]+other.x[i][r]);
            }
        }
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
    void update(int v,int tl,int tr,int pos,char new_val)
    {
        if(tl==tr){
            memset(t[v].x,0,sizeof(t[v].x));
            if(new_val=='a') t[v].x[0][0]=1;
            if(new_val=='b') t[v].x[1][1]=1;
            if(new_val=='c') t[v].x[2][2]=1;
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
    void update(int idx,char a){
        update(1,1,n,idx,a);
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
        int n,q;
        string s;
        cin>>n>>q>>s;
        s='$'+s;
        SegTree ST(n+5);
        for(int i=1;i<=n;i++) ST.update(i,s[i]);
        while(q--){
            int idx;
            char x;
            cin>>idx>>x;
            ST.update(idx,x);
            // for(int l=0;l<3;l++){
            //     for(int r=l;r<3;r++){
            //         cout<<l<<' '<<r<<' '<<ST.t[1].x[l][r]<<'\n';
            //     }
            // }
            cout<<ST.t[1].x[0][2]<<'\n';
        }
    }
}