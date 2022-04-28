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

vv<vv<char>>v;
vv<vi>pre;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        int n,m,k;
        cin>>n>>m>>k;
        k--;
        v.assign(n,vv<char>(m));
        pre.assign(n+1,vi(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int mx=0;
        for(int i=0;i<m;i++){
            if(v[k][i]=='X') mx++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[j+1][i]=pre[j][i];
                if(v[j][i]=='X') pre[j+1][i]++;
            }
        }
        int ans=mx;
        // up
        for(int i=1;i<min(n,mx);i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(k+i<n&&v[k+i][j]=='X'||pre[min(n,k+i)][j]>k) cnt++;
            }
            ans=min(ans,cnt+i);
        }
        // down
        for(int i=1;i<min(n,mx);i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(k-i>=0&&v[k-i][j]=='X'||pre[n][j]-pre[max(0,k-i+1)][j]>n-1-k) cnt++;
            }
            ans=min(ans,cnt+i);
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}
