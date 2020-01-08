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
    vector<int> vis, ans;
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        if (!m) return vector<int>();

        unordered_map<string, int> mp;
        sort(words.begin(), words.end());
        for (int i = 0, rz = 0; i < m; ){
            int j = i;
            while (j < m && words[i] == words[j])
                ++j;
            vis.push_back(j - i);
            mp[words[i]] = rz, rz++;
            i = j;
        }

        int unit_len = words[0].length(), s_len = s.length();
        int cnt = unit_len * m;
        if (cnt > s_len) return vector<int>();
        
        queue<int> que;
        for (int i = 0; i < unit_len && i + cnt < s_len; ++i){
            int left = m;
            for (int j = 0; j < m; ++j){
                if (mp.count(s.substr(j * unit_len + i, unit_len))){
                    int id = mp[s.substr(j * unit_len + i, unit_len)];
                    --vis[id];
                    if (vis[id] >= 0) --left;
                    que.push(id);
                }else que.push(-1);
            }
            int rt = i + cnt;
            if (!left) ans.push_back(i);
            while (rt + unit_len <= s_len){
                int tp = que.front();
                que.pop();
                if (tp >= 0){
                    ++vis[tp];
                    if (vis[tp] >= 1) ++left; 
                }
                if (mp.count(s.substr(rt, unit_len))){
                    int id = mp[s.substr(rt, unit_len)];
                    --vis[id];
                    if (vis[id] >= 0) --left;
                    que.push(id);
                }else que.push(-1);
                rt += unit_len;
                if (!left) ans.push_back(rt - cnt);
            }
            while (!que.empty()) {
                if (que.front() >= 0) ++vis[que.front()];
                que.pop();
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
