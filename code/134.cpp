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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(!n) return -1;
        int cur = 0, to = 0, oil = 0;
        while(cur < n){
            do{
                oil += gas[to], oil -= cost[to];
                to = (to + 1) % n;
            }while(cur != to && oil >= 0);
            if(cur == to && oil >= 0) return cur;
            if(cur >= to) return -1;
            cur = to, oil = 0; 
        }
        return -1;
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
