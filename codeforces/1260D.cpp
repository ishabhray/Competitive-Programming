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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int m,n,k,t;
        cin>>m>>n>>k>>t;
        int a[m];
        for(int i=0;i<m;i++)
            cin>>a[i];
        sort(a,a+m,greater<int>());
        vv<vi>v(k,vi(3));
        for(int i=0;i<k;i++)
            cin>>v[i][0]>>v[i][1]>>v[i][2];
        sort(all(v));
        int l=1,r=m,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int mn=a[mid-1],mx=0,cnt=n+1;
            //cout<<mid<<'\n';
            for(int i=0;i<k;i++){
                mx=max(mx,v[i][0]-1);
                if(v[i][2]<=mn||v[i][1]<=mx){
                    //mx=max(mx,v[i][0]);
                    continue;
                }
                if(v[i][0]-1>mx)
                    cnt+=2*(v[i][1]-v[i][0]+1);
                else
                    cnt+=2*(v[i][1]-mx);
                mx=v[i][1];
                //cout<<i<<' '<<mx<<' '<<cnt<<'\n';
            }
            //cout<<cnt<<'\n';
            if(cnt<=t)
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        cout<<ans;
    }
}