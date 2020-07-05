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
    int c[30005], cur[15], nn;
    bool vis[30005];
    inline int lowbit(int x){
        return x & (-x);
    }
    void add(int x, int v){
        while (x <= nn)
            c[x] += v, x += lowbit(x);
    }
    int query(int x){
        int res = 0;
        while (x > 0)
            res += c[x], x -= lowbit(x);
        return res;
    }
    vector<int> G[15];
public:
    string minInteger(string num, int k) {
        nn = num.length();
        string ans;
        for (int i = 2; i <= nn; ++i)
            add(i, 1);
        for (int i = 0; i < nn; ++i)
            G[num[i] - '0'].push_back(i + 1);
        for (int i = 0; i < 10; ++i)
            cur[i] = 0;
        for (int p = 1; p <= nn; ++p){
            if (vis[p]) continue;
            bool flag = false;
            int dis1 = query(p);
            for (int i = 0; i < 10; ++i){
                if (cur[i] == G[i].size() || G[i][cur[i]] < p)
                    continue;
                int dis = query(G[i][cur[i]]) - dis1;
                if (dis <= k){
                    k -= dis;
                    ans.push_back(i + '0');
                    add(G[i][cur[i]], -1);
                    vis[G[i][cur[i]]] = true;
                    ++cur[i];
                    flag = true;
                    break;
                }
            }
            if (!flag) ans.push_back(num[p - 1]);
            else --p;
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
