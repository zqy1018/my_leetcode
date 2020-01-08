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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        int l = 0, r = n - 1;
		if(nums[l] < nums[r]) r = 0;
        while(l < r){
            int mid = (l + r) >> 1;
			if(nums[mid] > nums[0]) l = mid + 1;
			else r = mid;
        }
		int st = l;
		l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r + 1) >> 1;
			if(nums[(st + mid) % n] <= target) l = mid;
			else r = mid - 1;
		}
		return nums[(st + l) % n] == target ? (st + l) % n: -1;
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
