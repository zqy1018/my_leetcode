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
    vector<int> sortedSquares(vector<int>& A) {
        if(!A.size()) return vector<int>();
        vector<int> ans;
        int n = A.size();
        if(A[0] >= 0){
            for (int i = 0; i < n; ++i)
                ans.push_back(A[i] * A[i]);
            return ans;
        }else if(A[n - 1] <= 0){
            for (int i = n - 1; i >= 0; --i)
                ans.push_back(A[i] * A[i]);
            return ans;
        }
        int cur = 0;
        while(cur < n - 1){
            if(A[cur] <= 0 && A[cur + 1] >= 0)
                break;
            cur++;
        }
        for (int i = cur, j = cur + 1; i >= 0 || j < n; ){
            if(j >= n || (i >= 0 && A[i] * A[i] <= A[j] * A[j]))
                ans.push_back(A[i] * A[i]), --i;
            else{
                ans.push_back(A[j] * A[j]), ++j;
            }       
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
