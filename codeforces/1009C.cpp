#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long
#define double long double
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
    //factorial(100005);
    while(te--){
        ll n,m;
        cin>>n>>m;
        ll avg=0;
        ll a=(n-1)*n/2,b=n/2*(n/2+1)/2+(n-1)/2*((n-1)/2+1)/2;
        for(int i=0;i<m;i++){
            ll x,d;
            cin>>x>>d;
            avg+=n*x;
            if(d>=0)
                d*=a;
            else
                d*=b;
            avg+=d;
        }
        double ans=avg;
        ans/=n;
        cout<<setprecision(12)<<ans;
    }
}