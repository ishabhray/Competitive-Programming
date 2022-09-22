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
int MOD=1e9+7;
struct ds{
    set<ii>s;
    void add(int x){
        auto it=s.lower_bound({x,0});
        if(it!=s.end()&&it->ff==x){
            s.insert({x,it->ss+1});
            s.erase(it);
        }
        else s.insert({x,1});
    }
    void del(int x){
        auto it=s.lower_bound({x,0});
        if(it->ss>1) s.insert({x,it->ss-1});
        s.erase(it);
    }
};
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
        int n,m;
        cin>>n>>m;
        vi adj[m+1];
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(i);
            adj[b].pb(i);
        }
        ll ans[m+2]={0};
        ds s;
        int r=-1;
        for(int i=1;i<=m;i++){
            while(s.s.size()<n&&r<m){
                r++;
                for(int j:adj[r]){
                    s.add(j);
                }
            }
            if(s.s.size()<n) break;
            ll len=r-i+1;
            ans[len]++;
            len=m-i+1;
            // cout<<i<<' '<<len+1<<'\n';
            ans[len+1]--;
            for(int j:adj[i]) s.del(j);
        }
        for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    }
}