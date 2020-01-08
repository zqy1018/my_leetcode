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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(!n && !m) return 0.0;
        int tot = (n + m - 1) >> 1;
        int l = max(0, tot - m), r = min(tot, n);
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums1[mid] < nums2[tot - mid - 1])
                l = mid + 1;
            else r = mid;
        }
        if((n + m) & 1) {
            if(l >= n) return nums2[tot - l];
            if(tot - l >= m) return nums1[l];
            if(nums1[l] < nums2[tot - l]) return nums1[l];
            return nums2[tot - l];
        }else{
            if(l >= n) return 0.5 * (nums2[tot - l] + nums2[tot - l + 1]);
            if(tot - l >= m) return 0.5 * (nums1[l] + nums1[l + 1]);
            if(tot - l + 1 < m && nums1[l] > nums2[tot - l + 1])
                return 0.5 * (nums2[tot - l] + nums2[tot - l + 1]);
            else if(l + 1 < n && nums2[tot - l] > nums1[l + 1])
                return 0.5 * (nums1[l] + nums1[l + 1]);
            else return 0.5 * (nums1[l] + nums2[tot - l]);
        }
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
