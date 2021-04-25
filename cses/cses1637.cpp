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
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
            dp[i]=1e15;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int j=i;
            while(j){
                int c=j%10;
                j/=10;
                dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
        cout<<dp[n];
    }
}