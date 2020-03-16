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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int dis[105];
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> que;
        vector<string> ans;
        vector<pair<int, string> > res;
        map<string, int> mp;
        unordered_set<string> st;
        int n = watchedVideos.size();
        for (int i = 0; i < n; ++i)
            for (auto& s: watchedVideos[i]){
                if (!mp.count(s))
                    mp[s] = 1;
                else ++mp[s];
            }
        que.push(id);
        while (!que.empty()){
            int h = que.front();
            que.pop();
            for (int x: friends[h])
                if (!dis[x] && id != x){
                    dis[x] = dis[h] + 1;
                    if (dis[x] == level){
                        for (auto& s: watchedVideos[x])
                            st.insert(s);
                    }
                    que.push(x);
                }
        }
        for (auto& s: st)
            res.push_back(make_pair(mp[s], s));
        sort(res.begin(), res.end());
        for (auto& p: res)
            ans.push_back(p.second);
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
