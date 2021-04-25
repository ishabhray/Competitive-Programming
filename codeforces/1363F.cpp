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

int dp[2005][2005];
string s,t;
int ss[26][2005],st[26][2005];
int solve(int i,int j)
{
    //cout<<i<<' '<<j<<'\n';
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=1+solve(i-1,j);
    if(s[i]==t[j])
        dp[i][j]=min(dp[i][j],solve(i-1,j-1));
    if(i<j&&ss[t[j]-'a'][i+1]>st[t[j]-'a'][j+1])
        dp[i][j]=min(dp[i][j],solve(i,j-1));
    return dp[i][j];
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n>>s>>t;
        for(int i=0;i<n+5;i++)
            for(int j=0;j<n+5;j++)
                dp[i][j]=-1;
        for(int i=0;i<26;i++)
            for(int j=0;j<n+5;j++)
                ss[i][j]=0,st[i][j]=0;
        
        for(int i=0;i<=2000;i++)
            dp[0][i]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                ss[j][i]+=ss[j][i+1];
            }
            ss[s[i]-'a'][i]++;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                st[j][i]+=st[j][i+1];
            }
            st[t[i]-'a'][i]++;
        }
        bool b=true;
        for(int i=0;i<26;i++)
            if(ss[i][0]!=st[i][0])
                b=false;
        if(b)
            cout<<solve(n-1,n-1)<<'\n';
        else
            cout<<"-1\n";
    }
}