#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  cout<<2*n<<'\n';
  int c=n/4;
  char extra=n-4*c;
  string ans="";
  if(extra) ans+=extra+'0';
  for(int i=0;i<c;i++) ans+='4';
  cout<<ans<<'\n';
}