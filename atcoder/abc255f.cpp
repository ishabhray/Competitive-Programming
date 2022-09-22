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

ii ans[MAXN];
int p[MAXN],in[MAXN],pre=0,n;
map<int,int>m;
bool f=true;
int build(int l,int r){
    if(l>r||l<0||r>=n) return 0;
    int par=p[pre++];
    if(m[par]<l||m[par]>r){
        f=false;
        return 0;
    }
    ans[par].ff=build(l,m[par]-1);
    ans[par].ss=build(m[par]+1,r);
    return par;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>in[i];
        if(p[0]!=1) f=false;
        for(int i=0;i<n;i++) m[in[i]]=i;
        build(0,n-1);
        if(!f){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++) cout<<ans[i].ff<<' '<<ans[i].ss<<'\n';
    }
}