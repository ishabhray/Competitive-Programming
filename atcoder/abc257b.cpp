#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,q;
  cin>>n>>k>>q;
  int a[k],b[q];
  for(int &i:a) cin>>i;
  for(int &i:b) cin>>i;
  for(int i=0;i<q;i++){
    b[i]--;
    if(b[i]==k-1) a[b[i]]=min(n,a[b[i]]+1);
    else if(a[b[i]+1]!=1+a[b[i]]) a[b[i]]++;
  }
  for(int i:a) cout<<i<<' ';
  cout<<'\n';
}