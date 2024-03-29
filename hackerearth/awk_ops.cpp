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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    cin>>te;
    while(te--){
        ll n;
        cin>>n;
        ll a[n],b[n];
        for(ll &i:a) cin>>i;
        for(ll &i:b) cin>>i;
        if(n>=1000){
            string ans="Yes\n";
            ll x=0,y=0;
            for(int i=0;i<n;i++) x+=a[i],y+=b[i];
            if(x!=y) ans="No\n";
            cout<<ans;
            continue;
        }
        bool ans=true;
        for(int i=0;i+1<n;i++){
            ll diff=b[i]-a[i];
            if(!diff) continue;
            ll s=0,j=i+1;
            while(j<n-1&&s!=diff) s+=a[j++];
            if(s!=diff){
                ans=false;
                break;
            }
            a[j]+=a[j-1];
            for(int k=j-1;k>i+1;k--) a[k]=a[k-1];
            a[i+1]=-diff;
        }
        if(a[n-1]!=b[n-1]) ans=false;
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
}