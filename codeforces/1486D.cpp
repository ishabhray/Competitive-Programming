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

ll p,q;

bool f(ld a[],ll n,ll k,ld x){
    ld pres[n+1]={0},prem[n+1]={0};
    ll pos[n+1]={0};
    for(ll i=0;i<n;i++){
        pres[i+1]=a[i]-x+pres[i];
        prem[i+1]=min(prem[i],pres[i+1]);
        pos[i+1]=pos[i];
        if(prem[i+1]!=prem[i])
            pos[i+1]=i+1;
    }
    for(ll i=k;i<=n;i++){
        if(pres[i]-prem[i-k]>=0){
            q=i,p=pos[i-k]+1;
            return true;
        }
    }
    return false;
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
    //factorial(1000005);
    while(te--){
        ll n,k;
        cin>>n>>k;
        ld a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ld l=0,r=100;
        ll ansl,ansr,c=0;
        while(c<50){
            c++;
            ld mid=(l+r)/2;
            if(f(a,n,k,mid)){
                l=mid,ansl=p,ansr=q;
            }
            else
                r=mid;
        }
        cout<<ansl<<' '<<ansr;
    }
}