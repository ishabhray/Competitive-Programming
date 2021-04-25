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

ll fact[21];
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
    //factorial(25);
    fact[0]=1;
    for(int i=1;i<=20;i++)
        fact[i]=fact[i-1]*i;
    while(te--){
        int n;
        cin>>n;
        ll ans=fact[n]/fact[n/2]/fact[n/2]*fact[n/2-1]*fact[n/2-1]/2;
        cout<<ans<<'\n';
    }
}