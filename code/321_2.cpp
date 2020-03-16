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

typedef pair<pair<int, int>, int> Tpp;
class Solution {
    int nxt1[105][10], nxt2[105][10], n, m;
    map<Tpp, pair<int, int>> to;
    map<Tpp, int> ans;
    inline bool check(int c1, int c2, int c3, int c4, int ck){
        Tpp t1(make_pair(c1, c2), ck), t2(make_pair(c3, c4), ck);
        while (t1.second){
            if (ans[t1] != ans[t2])
                return ans[t1] > ans[t2];
            t1.first = to[t1], t2.first = to[t2];
            --t1.second, --t2.second;
        }
        return true;
    }
    void dfs(int cur1, int cur2, int curk){
        Tpp cur(make_pair(cur1, cur2), curk);
        if (curk == 0 || ans.count(cur)) return ;
        //cout << cur1 << " " << cur2 << " " << curk << endl;
        for (int t = 9; t >= 0; --t){
            int pos1 = nxt1[cur1][t], pos2 = nxt2[cur2][t];
            bool flag = false;
            //cout << t << " " << pos1 << " " << pos2 << endl;
            if (pos1 >= 0 || pos2 >= 0){
                if (pos1 >= 0 && n - pos1 + m - cur2 >= curk){
                    ans[cur] = t + 1, flag = true;
                    dfs(pos1 + 1, cur2, curk - 1);
                    to[cur] = make_pair(pos1 + 1, cur2);
                }
                if (pos2 >= 0 && n - cur1 + m - pos2 >= curk){
                    ans[cur] = t + 1, flag = true;
                    dfs(cur1, pos2 + 1, curk - 1);
                    if (!to.count(cur) || check(cur1, pos2 + 1, pos1 + 1, cur2, curk - 1))
                        to[cur] = make_pair(cur1, pos2 + 1);
                }
                if (flag) break;
            }
        }
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size(), m = nums2.size();
        if (!(n + m) || !k) return vector<int>();
        for (int t = 0; t < 10; ++t){
            nxt1[n][t] = nxt2[m][t] = -1;
            for (int lst = -1, i = n - 1; i >= 0; --i){
                if (nums1[i] == t) lst = i;
                nxt1[i][t] = lst;
            }
            for (int lst = -1, i = m - 1; i >= 0; --i){
                if (nums2[i] == t) lst = i;
                nxt2[i][t] = lst;
            }
        }
        dfs(0, 0, k);
        vector<int> aans;
        Tpp tmp(make_pair(0, 0), k);
        while (tmp.second){
            aans.push_back(ans[tmp]);
            tmp.first = to[tmp], --tmp.second;
        }
        return aans;
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
