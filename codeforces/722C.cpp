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

ll p[100005],sum[100005];
ll get(ll a){
    return p[a]=(p[a]==a)? a:get(p[a]);
}
void uni(ll a,ll b){
    a=get(a);
    b=get(b);
    p[b]=a;
    sum[a]+=sum[b];
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
    //factorial(100005);
    while(te--){
        ll n;
        cin>>n;
        ll a[n+1],b[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i+1];
        for(int i=0;i<n;i++)
            cin>>b[i+1];
        multiset<ll>sums;
        sums.insert(0);
        deque<ll>ans;
        for(int i=n;i>=1;i--){
            ans.push_front(*sums.rbegin());
            p[b[i]]=b[i];
            sum[b[i]]=a[b[i]];
            get(b[i]+1);
            get(b[i]-1);
            if(p[b[i]+1]){
                sums.erase(sums.lower_bound(sum[p[b[i]+1]]));
                uni(b[i],b[i]+1);
            }
            if(p[b[i]-1]){
                sums.erase(sums.lower_bound(sum[p[b[i]-1]]));
                uni(b[i],b[i]-1);
            }
            sums.insert(sum[p[b[i]]]);
        }
        for(ll i:ans)
            cout<<i<<'\n';
    }
}