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

bool prime[10000001];
ll freq[10000005]={0};
ll cnt[10000005]={0};

void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p] == true) 
        {
            for (int i=p; i<=n; i += p) 
                prime[i] = false,freq[p]+=cnt[i]; 
        }
    }
    for(int i=2;i<=n;i++)
        freq[i]+=freq[i-1];
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
    while(t--){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            cnt[x]++;
        }
        SieveOfEratosthenes(10000000);
        ll q;
        cin>>q;
        while(q--){
            ll l,r;
            cin>>l>>r;
            l=min(10000000LL,l);
            r=min(10000000LL,r);
            cout<<freq[r]-freq[l-1]<<'\n';
        }
    }
}