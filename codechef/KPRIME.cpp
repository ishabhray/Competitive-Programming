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

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int prime[100001];

void SieveOfEratosthenes(int n) 
{ 
    for (int p=2; p<=n; p++)
    { 
        if (!prime[p]) 
        { 
            for (int i=p; i<=n; i += p) 
                prime[i]++; 
        } 
    } 
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
    cin>>t;
    SieveOfEratosthenes(100000);
    vv<vi >v(6,vi(100001,0));
    for(int i=1;i<=100000;i++){
        for(int k=1;k<=5;k++){
            v[k][i]=(prime[i]==k);
            v[k][i]+=v[k][i-1];
        }
    }
    //factorial(100005);
    while(t--){
        ll a,b,k;
        cin>>a>>b>>k;
        cout<<v[k][b]-v[k][a-1]<<'\n';
    }
}