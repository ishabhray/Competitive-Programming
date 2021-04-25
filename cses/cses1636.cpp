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

ll dp[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,x,MOD=1e9+7;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=x;j++){
                if(j+a[i]>x)
                    continue;
                (dp[j+a[i]]+=dp[j])%=MOD;
            }
        }
        cout<<dp[x];
    }
}