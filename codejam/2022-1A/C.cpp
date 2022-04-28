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
int cost(int x,int y){
    string a="",b="";
    while(x){
        a+=('0'+x/10);
        x/=10;
    }
    while(y){
        b+=('0'+y/10);
        y/=10;
    }
    reverse(all(a));
    reverse(all(b));
    int n=a.length(),m=b.length(),i=0;
    if(a.length()==0&&b.length()==0) return 0;
    if(a.length()==0) return m;
    if(b.length()==0) return n;
    for(i=0;i<min(n,m);i++) if(a[i]!=b[i]) break;
    return n-i+m-i;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        int e,w;
        cin>>e>>w;
        int x[e+1][w];
        for(int i=0;i<e;i++) for(int j=0;j<w;j++) cin>>x[i][j];
        for(int i=0;i<w;i++) x[e][i]=0;
        unordered_map<int,int>dp;
        dp[0]=0;
        for(int i=0;i<=e;i++){
            unordered_map<int,int>dp1;
            string v="";
            int y=0;
            for(int j=0;j<w;j++){
                for(int k=0;k<x[i][j];k++) v+=('0'+j+1),y=y*10+j+1;
            }
            if(y==0) v="0";

            do{
                y=0;
                for(char j:v) y=y*10+j-'0';
                dp1[y]=1e8;
                for(auto i:dp){
                    cout<<i.ff<<' '<<y<<' '<<cost(i.ff,y)<<'\n';
                    dp1[y]=min(dp1[y],i.ss+cost(i.ff,y));
                }
            }while(next_permutation(all(v)));
            // for(auto i:dp1) cout<<i.ff<<' '<<i.ss<<'\n';
            swap(dp,dp1);
        }
        cout<<"Case #"<<T<<": "<<dp[0]<<'\n';
    }
}