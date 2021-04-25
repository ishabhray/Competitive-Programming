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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int dp[100005]={0};
    for(int i=1;i<=100000;i++){
        if(__builtin_popcount(i)==1){
            dp[i]=1;
            continue;
        }
        for(int j=20;j>=0;j--){
            if(i&(1<<j)){
                int temp=i;
                int k=j;
                do{
                    temp^=(1<<k);
                    dp[i]|=!dp[temp];
                    k--;
                }while(!(i&(1<<k))&&k>=0);
                j=k+1;
            }
        }
    }
    /*for(int i=1;i<=25;i++)
        cout<<dp[i]<<' ';
    cout<<'\n';*/
    int te=1;
    cin>>te;
    while(te--){
        int n;
        cin>>n;
        if(dp[n])
            cout<<"Tanmay\n";
        else
            cout<<"Kush\n";
    }
}