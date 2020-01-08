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
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int cur = 0, n = queries.size();
        for (int i: A) 
            if(!(i & 1)) cur += i;
        for (int i = 0; i < n; ++i){
            int id = queries[i][1], v = queries[i][0];
            if(A[id] & 1){
                if(v & 1) cur += A[id] + v;
                A[id] += v;
            }else{
                if(v & 1) cur -= A[id];
                else cur += v;
                A[id] += v;
            }
            ans.push_back(cur);
        }
        return ans;
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
