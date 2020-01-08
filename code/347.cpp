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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for ( int i: nums ){
            if ( !mp.count( i ) ) mp[i] = 1;
            else ++mp[i];
        }
        priority_queue<pair<int, int> > pq;
        for ( int i: nums ){
            if ( mp.count( i ) ) 
                pq.push( make_pair( -mp[i], i ) ), mp.erase( i );
            if ( pq.size() > k ) pq.pop();
        }
        vector<int> ans;
        for ( int i = 0; i < k; ++i ){
            ans.push_back( pq.top().second );
            pq.pop();
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
