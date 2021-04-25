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
        ll m,n;
        cin>>m>>n;
        ll t[n],z[n],y[n],a[n];
        for(int i=0;i<n;i++)
            cin>>t[i]>>z[i]>>y[i];
        ll l=0,r=1e15,ans;
        while(l<=r){
            ll mid=(l+r)/2;
            ll cnt=0;
            ll b[n];
            for(int i=0;i<n;i++){
                b[i]=(mid/(t[i]*z[i]+y[i]))*z[i];
                ll x=(mid%(t[i]*z[i]+y[i]))/t[i];
                if(x>=z[i])
                    b[i]+=z[i];
                else
                    b[i]+=x;
                cnt+=b[i];
            }
            if(cnt>=m){
                ans=mid,r=mid-1;
                for(int i=0;i<n;i++)
                    a[i]=b[i];
            }
            else l=mid+1;
        }
        cout<<ans<<'\n';

        for(int i=0;i<n;i++){
            cout<<min(m,a[i])<<' ';
            m=max(0ll,m-a[i]);
        }
    }
}