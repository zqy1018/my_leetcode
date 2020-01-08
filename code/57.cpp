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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l1 = 0, r1 = n;
        while (r1 > l1){
            int mid = (l1 + r1) >> 1;
            if (intervals[mid][1] < newInterval[0]) l1 = mid + 1;
            else r1 = mid;
        }
        if (l1 == n){
            intervals.push_back(newInterval);
            return intervals;
        }
        int l2 = 0, r2 = n;
        while (r2 > l2){
            int mid = (l2 + r2) >> 1;
            if (intervals[mid][0] <= newInterval[1]) l2 = mid + 1;
            else r2 = mid;
        }
        --l2;
        if (l2 == -1){
            intervals.insert(intervals.begin(), newInterval);
        }else if (l2 == n - 1){
            int rr = max(newInterval[1], intervals[n - 1][1]);
            while (l1 < intervals.size() - 1) intervals.pop_back();
            intervals[l1][0] = min(newInterval[0], intervals[l1][0]);
            intervals[l1][1] = rr;
        }else { 
            int ll = min(newInterval[0], intervals[l1][0]);
            int rr = max(newInterval[1], intervals[l2][1]);
            if (l1 < l2){
                intervals[l1][0] = ll, intervals[l1][1] = rr;
                intervals.erase(intervals.begin() + l1 + 1, intervals.begin() + l2 + 1);
            }else {
                intervals.insert(intervals.begin() + l1, vector<int>{ll, rr});
            }
        }
        return intervals;
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
