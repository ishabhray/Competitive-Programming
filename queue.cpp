#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* nxt;
    Node* pre;
    Node():val(0),nxt(0),pre(0){
    }
    Node(int x):val(x),nxt(0),pre(0){
    }
};

class Deque{
    Node* _front;
    Node* _back;
    int _size;
public:
    Deque():_front(0), _back(0),_size(0){
    }
    int size(){
        return _size;
    }
    bool empty(){
        return _size==0;
    }
    int front(){
        if(_size){
            return _front->val;
        }
        return INT_MIN;
    }
    int back(){
        if(_size){
            return _back->val;
        }
        return INT_MIN;
    }
    void push_back(int x){
        Node* tmp = new Node(x);
        if(_size){
            _back->nxt = tmp;
            tmp->pre = _back;
            _back = _back->nxt;
        }
        else{
            _front = _back = tmp;
        }
        _size++;
    }
    void push_front(int x){
        Node* tmp = new Node(x);
        if(_size){
            _front->pre = tmp;
            tmp->nxt = _front;
            _front = _front->pre;
        }
        else{
            _front = _back = tmp;
        }
        _size++;
    }
    int pop_front(){
        if(!_size){
            cout<<"QUEUE EMPTY!!!\n";
            return INT_MIN;
        }

        _size--;
        int x = _front->val;
        Node* tmp = _front->nxt;
        delete _front;
        _front = tmp;
        if(_size){
            _front->pre = 0;
        }
        else{
            _front = _back = 0;
        }
        return x;
    }
    int pop_back(){
        if(!_size){
            cout<<"QUEUE EMPTY!!!\n";
            return INT_MIN;
        }
        _size--;
        int x = _back->val;
        Node* tmp = _back->pre;
        delete _back;
        _back = tmp;
        if(_size){
            _back->nxt = 0;
        }
        else{
            _front = _back = 0;
        }
        return x;
    }
    ~Deque(){
        while(_front){
            Node *tmp = _front->nxt;
            delete _front;
            _front = tmp;
        }
    }
};
int main(){
    Deque q;
    for(int i=1; i<=11; i++){
        q.push_back(i);
    }
    while(!q.empty()){
        cout<<q.pop_front()<<' ';
        cout<<q.pop_back()<<' ';
        cout<<q.size()<<'\n';
    }
}