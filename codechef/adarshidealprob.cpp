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

int prime[1000001]={0};

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
vi factor(int n)
{
    vi fact;
    while(n>1){
        fact.pb(prime[n]);
        int tmp=prime[n];
        while(n%tmp==0)
            n/=tmp;
    }
    return fact;
}
bitset<1000001> freq;
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
    SieveOfEratosthenes(1000000);
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll l=0,r=0,ans=0,lcm;
        freq.reset(0);
        for(int l=0;l<n;l++){
            while(r<n){
                bool b=1;
                vi fact=factor(a[r]);
                for(int i:fact){
                    if(freq[i]){
                        b=0;
                        break;
                    }
                }
                if(b==0)
                    break;
                for(int i:fact)
                    freq[i]=1;
                r++;
            }
            ans=max(ans,r-l);
            vi fact=factor(a[l]);
            for(int i:fact)
                freq[i]=0;
        }
        cout<<ans<<'\n';
    }
}