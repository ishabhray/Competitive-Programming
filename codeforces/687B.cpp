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
int prime[1000001];
void SieveOfEratosthenes(int n) 
{ 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p] == 0) 
        { 
            for (int i=p; i<=n; i += p) 
                prime[i] = p; 
        } 
    } 
}
int fl[1000001],fk[1000001];
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
    SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,k;
        cin>>n>>k;
        while(k>1){
            fk[prime[k]]++;
            k/=prime[k];
        }
        
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            while(x>1){
                int cnt=0,p=prime[x];
                while(x%p==0)
                    cnt++,x/=p;
                fl[p]=max(fl[p],cnt);
            }
        }
        bool b=true;
        for(int i=2;i<=1000000;i++){
            if(i!=prime[i])
                continue;
            if(fl[i]<fk[i])
                b=false;
        }
        if(b)
            cout<<"Yes";
        else cout<<"No";
    }
}