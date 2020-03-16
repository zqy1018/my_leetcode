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
    int cnt[30], res[30], n, l;
    vector<pair<int, int>> vec;
    string *pat, *s;
    bool check(){
        unordered_map<string, int> mp;
        unordered_map<int, string> mp2;
        int cur = 0;
        string& ss = *s;
        for (char c: *pat){
            if (mp2.count(c - 'a')){
                string sss = ss.substr(cur, res[c - 'a']);
                if (mp2[c - 'a'] != sss)
                    return false;
            }else {
                string sss = ss.substr(cur, res[c - 'a']);
                if (mp.count(sss))
                    return false;
                mp[sss] = c - 'a';
                mp2[c - 'a'] = sss;             // 建立双射关系
            }
            cur += res[c - 'a'];
        }
        return true;
    }
    bool solve(int cur, int left){
        if (cur == n){
            if (left == 0) return check();
            return false;
        }
        int p = vec[cur].first;
        for (int i = 1; i <= left / p; ++i){
            res[vec[cur].second] = i;
            if (solve(cur + 1, left - i * p)) return true;
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        for (char c: pattern)   
            ++cnt[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i])
                vec.push_back(make_pair(cnt[i], i));
        sort(vec.begin(), vec.end());
        n = vec.size(), l = str.length();
        pat = &pattern, s = &str;
        return solve(0, l);
    }
};
Solution sol;
void init(){
    string a("aba"), b("redblueredblue");
    cout << sol.wordPatternMatch(a, b) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
