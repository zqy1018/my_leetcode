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
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i: stones)
            pq.push(i);
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(pq.empty())
                return a;
            int b = pq.top();
            pq.pop();
            if(a != b){
                if(a < b) swap(a, b);
                pq.push(a - b);
            }
        }
        return 0;
    }
};
Solution sol;
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
