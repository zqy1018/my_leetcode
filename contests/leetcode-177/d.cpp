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
    int cnt[11];
    int ccnt[11];
    string ans, tmp;
    void dfs(int cur, int md){
        if (cur == -1){
            if (md != 0) return ;
            long long t1 = (tmp.empty() ? 0: stoll(tmp));
            long long t2 = stoll(ans);
            if (t1 > t2) ans = tmp;
            return ;
        }
        if (ccnt[cur] == 0) dfs(cur - 1, md);
        else if (ccnt[cur] == 1){
            dfs(cur - 1, md);
            tmp.push_back(cur + '0');
            dfs(cur - 1, (md + cur) % 3);
            tmp.pop_back();
        }else {
            dfs(cur - 1, md);
            tmp.push_back(cur + '0');
            dfs(cur - 1, (md + cur) % 3);
            tmp.pop_back();
            tmp.push_back(cur + '0');
            tmp.push_back(cur + '0');
            dfs(cur - 1, (md + cur + cur) % 3);
            tmp.pop_back();
            tmp.pop_back();
        }
    }
public:
    string largestMultipleOfThree(vector<int>& digits) {
        for (int x: digits)
            ++cnt[x];
        bool only0 = true;
        for (int i = 1; i < 10; ++i)
            if (cnt[i]){
                only0 = false;
                break;
            }
        if (only0){
            return string("0");
        }
        for (int i = 0; i < 10; ++i){
            if (i % 3 == 0) continue;
            ccnt[i] = min(2, cnt[i]);
        }
        ans = string("0");
        dfs(9, 0);

        string res;
        int cur = 0;

        for (int i = 0; i < cnt[9]; ++i)
            res.push_back('9');
        while (cur < ans.length() && ans[cur] == '8')
            res.push_back('8'), ++cur, --cnt[8];
        for (int i = 0; i < cnt[8] / 3; ++i)
            res.push_back('8'), 
            res.push_back('8'), 
            res.push_back('8');
        while (cur < ans.length() && ans[cur] == '7')
            res.push_back('7'), ++cur, --cnt[7];
        for (int i = 0; i < cnt[7] / 3; ++i)
            res.push_back('7'), 
            res.push_back('7'), 
            res.push_back('7');

        for (int i = 0; i < cnt[6]; ++i)
            res.push_back('6');
        while (cur < ans.length() && ans[cur] == '5')
            res.push_back('5'), ++cur, --cnt[5];
        for (int i = 0; i < cnt[5] / 3; ++i)
            res.push_back('5'), 
            res.push_back('5'), 
            res.push_back('5');
        while (cur < ans.length() && ans[cur] == '4')
            res.push_back('4'), ++cur, --cnt[4];
        for (int i = 0; i < cnt[4] / 3; ++i)
            res.push_back('4'), 
            res.push_back('4'), 
            res.push_back('4');

        for (int i = 0; i < cnt[3]; ++i)
            res.push_back('3');
        while (cur < ans.length() && ans[cur] == '2')
            res.push_back('2'), ++cur, --cnt[2];
        for (int i = 0; i < cnt[2] / 3; ++i)
            res.push_back('2'), 
            res.push_back('2'), 
            res.push_back('2');
        while (cur < ans.length() && ans[cur] == '1')
            res.push_back('1'), ++cur, --cnt[1];
        for (int i = 0; i < cnt[1] / 3; ++i)
            res.push_back('1'), 
            res.push_back('1'), 
            res.push_back('1');
        
        for (int i = 0; i < cnt[0]; ++i)
            res.push_back('0');
        return res;
    }
};
Solution sol;
void init(){
    vector<int> vec{8, 7, 6, 1, 0};
    cout << sol.largestMultipleOfThree(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
