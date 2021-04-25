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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int te = 1;
    //cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--) {
        int n;
        cin>>n;
        vl v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        set<int>ans;
        ans.insert(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]>=*ans.rbegin())
                ans.insert(v[i]);
            else{
                ans.erase(ans.lower_bound(v[i]));
                ans.insert(v[i]);
            }
        }
        cout<<ans.size();
    }
}