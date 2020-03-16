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

class Leaderboard {
public:
    multiset<int> st;
    unordered_map<int, int> mp;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (!mp.count(playerId)){
            mp[playerId] = score;
            st.insert(score);
        }else {
            int cur = mp[playerId];
            auto tt = st.find(cur);
            st.erase(tt);
            mp[playerId] = cur + score;
            st.insert(cur + score);
        }
    }
    
    int top(int K) {
        auto tt = st.end();
        --tt;
        int ans = 0;
        for (int i = 0; i < K; ++i) {
            ans += *tt;
            --tt;
        }
        return ans;
    }
    
    void reset(int playerId) {
        int cur = mp[playerId];
        mp[playerId] = 0;
        auto tt = st.find(cur);
        st.erase(tt);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
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
