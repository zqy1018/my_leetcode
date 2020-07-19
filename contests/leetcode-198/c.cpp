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
    int st[27], ed[27];
    pair<int, int> seg[100];
public:
    vector<string> maxNumOfSubstrings(string s) {
        int l = s.length();
        memset(st, 0x3f, sizeof(st));
        for (int i = 0; i < l; ++i)
            st[s[i] - 'a'] = min(st[s[i] - 'a'], i), 
            ed[s[i] - 'a'] = i;
        vector<string> ans;
        int tot = 0;
        for (int i = 0; i < 26; ++i){
            if (st[i] < 0) continue;
            int targ = ed[i];
            bool flag = true;
            for (int j = st[i] + 1; j <= targ; ++j){
                if (st[s[j] - 'a'] < st[i]){
                    flag = false;
                    break;
                }
                targ = max(targ, ed[s[j] - 'a']);
            }
            if (flag)
                seg[tot].first = st[i], seg[tot++].second = targ;
        }
        for (int i = 0; i < tot; ++i){
            bool flag = true;
            for (int j = 0; j < tot; ++j)
                if (i != j && seg[i].first >= seg[j].first && seg[i].second <= seg[j].second){
                    flag = false;
                    break;
                }
            if (flag) 
                ans.push_back(s.substr(seg[i].first, seg[i].second - seg[i].first + 1));
        }
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
