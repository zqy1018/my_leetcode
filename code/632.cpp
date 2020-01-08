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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct N{
            int id;
            vector<int>::iterator iter;  
            N ( int _id, vector<int>::iterator _v ): id( _id ), iter( _v ) {}
        };
        struct cmp{
            bool operator() ( const N& n1, const N& n2 ){
                return *(n1.iter) > *(n2.iter);
            }
        };
        priority_queue<N, vector<N>, cmp> pq;
        int n = nums.size();
        int ansl = 2147483647, ansr = -2147483648;
        for (int i = 0; i < n; ++i){
            if ( nums[i].empty() ) continue;
            pq.push( N( i, nums[i].begin() ) );
            ansl = min( ansl, nums[i].front() );
            ansr = max( ansr, nums[i].front() );
        }
        int curl = ansl, curr = ansr;
        for (; ansr > ansl && !pq.empty(); ){
            N nn = pq.top();
            pq.pop();
            if ( nn.iter + 1 != nums[nn.id].end() ){
                curl = ( pq.size() == n - 1 ) ? *pq.top().iter: curl;
                ++nn.iter;
                curl = min( curl, *nn.iter ), curr = max( curr, *nn.iter );
                pq.push( nn );
            }
            if ( ansr - ansl > curr - curl )
                ansl = curl, ansr = curr;
        }
        return vector<int> { ansl, ansr };
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
