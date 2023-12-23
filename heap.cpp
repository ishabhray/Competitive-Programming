#include<bits/stdc++.h>
using namespace std;

class Heap{
    int *a;
    int cap;
    int sz;
    void heapify_up(int idx){
        if(!idx) return;
        int p=(idx-1)/2;
        if(a[p]<a[idx]) swap(a[p],a[idx]);
        heapify_up(p);
    }
    void heapify_down(int idx){
        int l=2*idx+1,r=2*idx+2;
        if(l>=sz) return;
        if(r>=sz){
            if(a[idx]<a[l]){
                swap(a[idx],a[l]);
                heapify_down(l);
            }
        }
        else{
            if(a[l]<=a[r]){
                if(a[idx]<a[r]){
                    swap(a[idx],a[r]);
                    heapify_down(r);
                }
            }
            else if(a[idx]<a[l]){
                swap(a[idx],a[l]);
                heapify_down(l);
            }
        }
    }
public:
    Heap():a(new int[1]),cap(1),sz(0){
    }
    int top(){
        if(!sz){
            cout<<"Empty Heap!!\n";
            return INT_MIN;
        }
        return a[0];
    }
    bool empty(){
        return sz==0;
    }
    void push(int x){
        if(sz==cap){
            cap*=2;
            int *temp=new int[cap];
            for(int i=0;i<cap/2;i++) temp[i]=a[i];
            delete [] a;
            a=temp;
        }
        a[sz]=x;
        heapify_up(sz);
        sz++;
    }
    int pop(){
        if(!sz){
            cout<<"Empty Heap!!\n";
            return INT_MIN;
        }
        sz--;
        int x=a[0];
        swap(a[0],a[sz]);
        heapify_down(0);
        return x;
    }
};

int main(){
    Heap q;
    int a[10]={1,3,4,2,5,4,5,7,1,9};
    for(int i=0;i<10;i++){
        q.push(a[i]);
    }
    while(!q.empty()) cout<<q.pop()<<'\n';
}