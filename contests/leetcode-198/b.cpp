#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

const int M = 1000000007;
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
    vector<int> G[100005];
    int cnt[100005][27];
    void dfs(int cur, int fa, string& l){
        ++cnt[cur][l[cur] - 'a'];
        for (int x: G[cur]){
            if (x == fa) continue;
            dfs(x, cur, l);
            for (int i = 0; i < 26; ++i)
                cnt[cur][i] += cnt[x][i];
        }
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for (auto& e: edges){
            int u = e[0], v = e[1];
            G[u].push_back(v), 
            G[v].push_back(u);
        }
        dfs(0, -1, labels);
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            ans.push_back(cnt[i][labels[i] - 'a']);
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
