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

int to[1005], at[1005], nxt[1005], cnt;
class Solution {
public:
    vector<string> vp;
    unordered_set<string> st;
    vector<pair<int, int>> vec;
    unordered_map<string, int> mp;
    void dfs(int S){
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for (int i = 0; i < n; ++i){
            if (!st.count(tickets[i][0])) st.insert(tickets[i][0]);
            if (!st.count(tickets[i][1])) st.insert(tickets[i][1]);
        }
        for (auto& s: st) vp.push_back(s);
        sort(vp.begin(), vp.end());
        int nn = vp.size();
        for (int i = 0; i < nn; ++i) mp[vp[i]] = i;
        for (int i = 0; i < n; ++i)
            vec.push_back(make_pair(mp[tickets[i][0]], mp[tickets[i][1]]));
        sort(vec.begin(), vec.end());
        
        cnt = 0;
        memset(at, 0, sizeof(at));
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && vec[i].first == vec[j].first)
                ++j;
            for (int t = j - 1; t >= i; --t)
                to[++cnt] = vec[t].second, nxt[cnt] = at[vec[i].first], at[vec[i].first] = cnt;
            i = j;
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
