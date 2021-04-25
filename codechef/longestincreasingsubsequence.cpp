#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dpl[n],dps[n];
    for(int i=0;i<n;i++){
        dpl[i]=1;
        dps[i]=a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dpl[i]=max(dpl[i],dpl[j]+1);
                dps[i]=max(dps[i],dps[j]+a[i]);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<dpl[i]<<' ';
    cout<<'\n';
    for(int i=0;i<n;i++)
        cout<<dps[i]<<' ';
    cout<<'\n';
}