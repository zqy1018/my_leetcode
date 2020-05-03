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

class Solution {
    vector<int> tmp1, tmp2;
    priority_queue<pair<int, pair<int, int> > > pq;
    bool vis[255][255];
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        for (int x: mat[0])
            tmp1.push_back(x)    ;
        for (int i = 1; i < n; ++i){
            tmp2.clear();
            memset(vis, 0, sizeof(vis));
            pq.push(make_pair(-tmp1[0] - mat[i][0], make_pair(0, 0)));
            vis[0][0] = true;
            while (!pq.empty() && tmp2.size() < k)  {
                auto p = pq.top();
                pq.pop();
                tmp2.push_back(-p.first);
                int cur1 = p.second.first, cur2 = p.second.second;
                // cout << cur1 << " " << cur2 << endl;
                if (cur1 + 1 < tmp1.size() && !vis[cur1 + 1][cur2])
                    pq.push(make_pair(-tmp1[cur1 + 1] - mat[i][cur2], make_pair(cur1 + 1, cur2))), 
                    vis[cur1 + 1][cur2] = true;
                if (cur2 + 1 < m && !vis[cur1][cur2 + 1])
                    pq.push(make_pair(-tmp1[cur1] - mat[i][cur2 + 1], make_pair(cur1, cur2 + 1))),
                    vis[cur1][cur2 + 1] = true;
            }
            while (!pq.empty()) pq.pop();
            tmp1.clear();
            for (int x: tmp2)
                tmp1.push_back(x);
        }
        return tmp1[k - 1];
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
