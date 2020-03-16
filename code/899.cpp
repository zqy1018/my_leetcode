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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
}

class Solution {
public:
    int cnt[30];
    string ans;
    string orderlyQueue(string S, int K) {
        for (char c: S)
            ++cnt[c - 'a'];
        int l = S.length();
        if (K == l){
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < cnt[i]; ++j)
                    ans.push_back(i + 'a');
            return ans;
        }
        ans.reserve(l);
        for (int i = 0; i < 26; ++i){
            if (!cnt[i]) continue;
            for (int j = min(K, cnt[i]); j >= 1; --j)
                ans.push_back(i + 'a');
            if (K > cnt[i]){
                K -= cnt[i];
                continue;
            }
            bool is_first = true;
            for (int j = 0; j < l; ++j){
                if (S[j] != i + 'a') continue;
                int left = K;
                if (is_first){
                    for (int t = j; t < l; ++t){
                        if (S[t] == i + 'a' && left > 0) --left;
                        else if (S[t] >= i + 'a') ans.push_back(S[t]);
                    }
                    for (int t = 0; t < j; ++t){
                        if (S[t] == i + 'a' && left > 0) --left;
                        else if (S[t] >= i + 'a') ans.push_back(S[t]);
                    }
                    is_first = false;
                }else {
                    int flag = 0, cur = K;
                    for (int t = j; t < l; ++t){
                        if (S[t] == i + 'a' && left > 0) --left;
                        else if (S[t] >= i + 'a'){
                            if (S[t] < ans[cur]){
                                flag = 1;
                                break;
                            }else if (S[t] > ans[cur]){
                                flag = -1;
                                break;
                            }
                            ++cur;
                        }
                    }
                    if (flag < 0) continue;
                    if (flag > 0){
                        left = K, cur = l - K;
                        for (int t = j; t < l; ++t){
                            if (S[t] == i + 'a' && left > 0) --left;
                            else if (S[t] >= i + 'a') ans[cur++] = S[t];
                        }
                        for (int t = 0; t < j; ++t){
                            if (S[t] == i + 'a' && left > 0) --left;
                            else if (S[t] >= i + 'a') ans[cur++] = S[t];
                        }
                        continue;
                    }
                    for (int t = 0; t < j; ++t){
                        if (S[t] == i + 'a' && left > 0) --left;
                        else if (S[t] >= i + 'a') {
                            if (S[t] < ans[cur]){
                                flag = 1;
                                break;
                            }else if (S[t] > ans[cur]){
                                flag = -1;
                                break;
                            }
                            ++cur;
                        }
                    }
                    if (flag < 0) continue;
                    if (flag > 0){
                        left = K, cur = K;
                        for (int t = j; t < l; ++t){
                            if (S[t] == i + 'a' && left > 0) --left;
                            else if (S[t] >= i + 'a') ans[cur++] = S[t];
                        }
                        for (int t = 0; t < j; ++t){
                            if (S[t] == i + 'a' && left > 0) --left;
                            else if (S[t] >= i + 'a') ans[cur++] = S[t];
                        }
                        continue;
                    }
                }
            }
            break;
        }
        return ans;
    }
};
Solution sol;
void init(){
    string a("baaca");
    cout << sol.orderlyQueue(a, 3) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
