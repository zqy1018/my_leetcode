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

struct Tp{
    int p1, p2, ck;
    Tp(int _p1, int _p2, int _ck){
        p1 = _p1, p2 = _p2, ck = _ck;
    }
};
class Solution {
    int nxt1[205][10], nxt2[205][10], n, m;
    map<Tp, pair<int, int>> to;
    vector<int> vec1, vec2;
    inline bool check(int c1, int c2, int c3, int c4, int ck){
        while (ck){
            int t1 = to[c1][c2][0], t2 = to[c1][c2][1];
            int t3 = to[c3][c4][0], t4 = to[c3][c4][1];
            int ans1 = (t1 == c1 ? c2 = t2, vec2[t2 - 1]: c1 = t1, vec1[t1 - 1]);
            int ans2 = (t3 == c3 ? c4 = t4, vec2[t4 - 1]: c3 = t3, vec1[t3 - 1]);
            if (ans1 != ans2) return ans1 > ans2;
            --ck;
        }
        return true;
    }
    void dfs(int cur1, int cur2, int curk){
        if (curk == 0 || to[cur1][cur2][0] >= 0) return ;
        //cout << cur1 << " " << cur2 << " " << curk << endl;
        for (int t = 9; t >= 0; --t){
            int pos1 = nxt1[cur1][t], pos2 = nxt2[cur2][t];
            //cout << t << " " << pos1 << " " << pos2 << endl;
            if (pos1 >= 0 || pos2 >= 0){
                if (pos1 >= 0 && n - pos1 + m - cur2 >= curk){
                    dfs(pos1 + 1, cur2, curk - 1);
                    to[cur1][cur2][0] = pos1 + 1, 
                    to[cur1][cur2][1] = cur2;
                }
                if (pos2 >= 0 && n - cur1 + m - pos2 >= curk){
                    dfs(cur1, pos2 + 1, curk - 1);
                    if (to[cur1][cur2][0] < 0 || check(cur1, pos2 + 1, pos1 + 1, cur2, curk - 1))
                        to[cur1][cur2][0] = cur1, 
                        to[cur1][cur2][1] = pos2 + 1;
                }
                if (to[cur1][cur2][0] >= 0)
                    break;
            }
        }
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size(), m = nums2.size();
        if (!(n + m) || !k) return vector<int>();
        vec1 = nums1, vec2 = nums2; 
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
        for (int i = 0, j = 0, t = k; t > 0; --t){
            auto& p = to[Tp(i, j, t)];
            int t1 = p.first, t2 = p.second;
            if (t1 == i) aans.push_back(nums2[t2 - 1]), j = t2;
            else aans.push_back(nums1[t1 - 1]), i = t1;
        }
        return aans;
    }
};
Solution sol;
void init(){
    vector<int> nums1{2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5}, nums2{2,6,2,0,1,0,5,4,5,5,3,3,3,4};
    cout << sol.maxNumber(nums1, nums2, 35) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
