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
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size(), ans = 0, ss = 0, maxi = -2147483648;
        deque<int> val, id;
        val.push_back(0), id.push_back(0);
        for (int i = 0; i < n + n; ++i){
            if(id.front() <= i - n)
                id.pop_front(), val.pop_front();
            ss += A[i >= n ? i - n: i];
            ans = max(ans, ss - val.front());
            while(!val.empty() && val.back() >= ss)
                val.pop_back(), id.pop_back();
            val.push_back(ss), id.push_back(i);
            maxi = max(maxi, A[i >= n ? i - n: i]);
        }
        return ans == 0 ? maxi: ans;
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
