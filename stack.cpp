#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int *a,cap,tp;
    Stack():cap(1),tp(-1),a(new int){}
    void push(int x){
        if(tp==cap-1){
            cap*=2;
            int *temp=new int[cap];
            for(int i=0;i<cap/2;i++) temp[i]=a[i];
            delete a;
            a=temp;
        }
        a[++tp]=x;
    }
    int pop(){
        if(tp==-1) {cout<<"STACK EMPTY\n"; return INT_MIN;}
        return a[tp--];
    }
    int top(){
        if(tp==-1) {cout<<"STACK EMPTY\n"; return INT_MIN;}
        return a[tp];
    }
    bool empty(){
        return (tp==-1);
    }
    ~Stack(){
        delete[] a;
    }
};
int main(){
    Stack st;
    for(int i=0;i<20;i++) st.push(i);
    while(!st.empty()){
        cout << st.top() <<'\n';
        st.pop();
    }
    st.pop();
}