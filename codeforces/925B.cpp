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

bool check(int k1,int k2,int n,ii a[],bool b)
{
    int j=0;
    for(int i=n-1;i>=0;i--){
        j++;
        if(a[i].ff>k1/j||a[i].ff==k1/j&&k1%j==0)
            break;
    }
    if(j==n)
        return false;
    int k=0,i;
    for(i=n-1-j;i>=0;i--){
        k++;
        if(a[i].ff>k2/k||a[i].ff==k2/k&&k2%k==0)
            break;
    }
    if(i==-1)
        return false;
    cout<<"Yes\n";
    if(b){
        cout<<j<<' '<<k<<'\n';
        for(int i=0;i<j+k;i++){
            if(i==j)
                cout<<'\n';
            cout<<a[n-1-i].ss<<' ';
        }
    }
    else{
        cout<<k<<' '<<j<<'\n';
        for(int i=0;i<j+k;i++){
            if(i==k)
                cout<<'\n';
            cout<<a[n-(j+k)+i].ss<<' ';
        }
    }
    return true;
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
        int n,k1,k2;
        cin>>n>>k1>>k2;
        ii a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].ff;
            a[i].ss=i+1;
        }
        sort(a,a+n);
        bool b=check(k1,k2,n,a,1);
        if(!b)
            b=check(k2,k1,n,a,0);
        if(!b)
            cout<<"No";
    }
}