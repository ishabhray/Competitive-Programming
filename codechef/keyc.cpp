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


char a[5005][5005];
ll dp[5005][5005],u[5005][5005],r[5005][5005];

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
    //factorial(1000005);
    while(te--){
        int MOD=998244353;
        int h,w,k;
        cin>>h>>w>>k;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                a[i][j]='.',u[i][j]=1,r[i][j]=1;
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            cin>>a[x][y];
            u[x][y]--,r[x][y]--;
        }
        ll pow[5005];
        pow[0]=1;
        for(int i=1;i<=5000;i++)
            pow[i]=(pow[i-1]*3)%MOD;
        for(int i=h;i>=1;i--){
            for(int j=w;j>=1;j--){
                r[i][j]+=r[i][j+1];
                u[i][j]+=u[i+1][j];
            }
        }
        dp[1][1]=1;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(a[i][j]=='D'||a[i][j]=='X')
                    (dp[i+1][j]+=dp[i][j]*pow[r[i][j+1]]%MOD)%MOD;
                if(a[i][j]=='R'||a[i][j]=='X')
                    (dp[i][j+1]+=dp[i][j]*pow[u[i+1][j]]%MOD)%MOD;
                if(a[i][j]=='.')
                    (dp[i+1][j]+=2*dp[i][j]*pow[r[i][j+1]]%MOD)%MOD,(dp[i][j+1]+=2*dp[i][j]*pow[u[i+1][j]]%MOD)%MOD;
            }
        }
        
        if(a[h][w]=='.')
            (dp[h][w]*=3)%=MOD;
        cout<<dp[h][w];
    }
}