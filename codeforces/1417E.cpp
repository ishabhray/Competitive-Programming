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
int MOD=1e9+7;

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

ll merge(vl &v,ll l,ll mid,ll r)
{
    vl v1;
    ll i=l,j=mid,ans=0;
    while(i<mid&&j<=r){
        if(v[i]<=v[j])
            v1.pb(v[i++]);
        else
            v1.pb(v[j++]),ans+=mid-i;
    }
    while(i<mid)
        v1.pb(v[i++]);
    while(j<=r)
        v1.pb(v[j++]);
    for(int i:v1)
        v[l++]=i;
    return ans;
}

ll invCnt(vl &v,ll l,ll r)
{
    ll cnt=0;
    if(r>l){
        ll mid=(l+r)/2;
        cnt+=invCnt(v,l,mid);
        cnt+=invCnt(v,mid+1,r);
        cnt+=merge(v,l,mid+1,r);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        vl v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        ll ans=0;
        vl u(n);
        for(int i=0;i<n;i++)
            u[i]=v[i];
        ll pre=invCnt(u,0,n-1);
        for(int i=30;i>=0;i--){
            /*for(int j=0;j<n;j++)
                cout<<v[j]<<' ';
            cout<<'\n';*/
            vl v2(n);
            for(int j=0;j<n;j++)
                v2[j]=v[j]^(1<<i);
            ll b=invCnt(v2,0,n-1);
            //cout<<i<<' '<<a<<' '<<b<<'\n';
            if(pre>b){
                pre=b;
                ans=ans^(1<<i);
                for(int j=0;j<n;j++)
                    v[j]=v[j]^(1<<i);
            }
        }
        cout<<invCnt(v,0,n-1)<<' '<<ans;
    }
}