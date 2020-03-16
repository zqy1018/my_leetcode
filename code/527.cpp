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
    int id[405], pos[405];
    vector<string> tmp;
    inline int opr(int l, int i, int lcp, vector<string>& dict){
        if (lcp >= l - 3)
            tmp.push_back(dict[id[i]]);
        else {
            string ss;
            for (int u = 0; u <= lcp; ++u)
                ss.push_back(dict[id[i]][u]);
            ss += to_string(l - lcp - 2);      // ll - lcp - 2 是被缩掉的字符个数
            ss.push_back(dict[id[i]].back());
            tmp.push_back(ss);
        }
    }
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        for (int i = 0; i < n; ++i)
            id[i] = i;
        sort(id, id + n, [&dict](int i, int j){
            if (dict[i].length() == dict[j].length()) {
                if (dict[i].back() == dict[j].back())
                    return dict[i] < dict[j];
                return dict[i].back() < dict[j].back();
            }
            return dict[i].length() < dict[j].length();
        });
        for (int i = 0; i < n; ++i)
            pos[id[i]] = i;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && dict[id[i]].length() == dict[id[j]].length() && dict[id[i]].back() == dict[id[j]].back())
                ++j;
            int ll = dict[id[i]].length();
            if (ll <= 3){
                for (int t = i; t < j; ++t)
                    tmp.push_back(dict[id[t]]);
            }else {
                if (j - i == 1) {
                    string ss;
                    ss.push_back(dict[id[i]][0]);
                    ss += to_string(ll - 2);
                    ss.push_back(dict[id[i]].back());
                    tmp.push_back(ss);
                }else {
                    int lst;
                    {
                        int lcp = 0;
                        while (lcp < ll && dict[id[i]][lcp] == dict[id[i + 1]][lcp])
                            ++lcp;
                        lst = lcp;
                        opr(ll, i, lcp, dict);
                    }
                    for (int t = i + 1; t < j - 1; ++t){
                        // 先试试看暴力枚举？
                        int curlcp = 0, lcp = 0;
                        while (curlcp < ll && dict[id[t]][curlcp] == dict[id[t + 1]][curlcp])
                            ++curlcp;
                        lcp = max(curlcp, lst);
                        lst = curlcp;
                        opr(ll, t, lcp, dict);
                    }
                    {
                        int lcp = lst;
                        opr(ll, j - 1, lcp, dict);
                    }
                }
            }
            i = j;
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i)
            ans.push_back(tmp[pos[i]]);
        return ans;
    }
};
Solution sol;
void init(){
    vector<string> vec{"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    auto ans = sol.wordsAbbreviation(vec);
    for (auto& s: ans)
        cout << s << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
