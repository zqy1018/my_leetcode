#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty()){
            while(!st1.empty())
                st2.push(st1.top()), st1.pop();
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty()){
            while(!st1.empty())
                st2.push(st1.top()), st1.pop();
        }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
MyQueue sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
