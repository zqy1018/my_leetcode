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
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(n & 1){
            pq1.push(num);
            pq2.push(pq1.top());
            pq1.pop();
        }else{
            if(pq1.empty() || pq1.top() >= num) pq1.push(num);
            else{
                pq2.push(num);
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        ++n;
    }
    
    double findMedian() {
        if(!n) return 0;
        if(n & 1){
            return pq1.top();
        }else{
            return (pq1.top() + pq2.top()) * 0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
MedianFinder sol;
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
