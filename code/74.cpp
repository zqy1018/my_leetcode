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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(matrix[mid / m][mid % m] < target) 
                l = mid + 1;
            else if(matrix[mid / m][mid % m] > target)
                r = mid - 1;
            else return true;
        }
        return false;
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
