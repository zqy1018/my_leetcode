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
    int cap, len;
    vector<int> vec, sm;
    Solution(int N, vector<int>& blacklist) {
        cap = N - blacklist.size();
        int cur = 0, n = blacklist.size();
        while (cur < n && blacklist[cur] == cur)
            ++cur;
        if (cur == n) vec.push_back(n), sm.push_back(N - n);
        else{
            int lst = cur;
            for (; cur < n; ){
                vec.push_back(lst), sm.push_back(blacklist[cur] - lst);
                int tmp = blacklist[cur], t = cur;
                while (cur < n && cur - t == blacklist[cur] - tmp)
                    ++cur;
                lst = blacklist[cur - 1] + 1;
            }
            if (lst != N)
                vec.push_back(lst), sm.push_back(N - lst);
        } 
         for (int i = 0; i < vec.size(); ++i)    
            cout << vec[i] << "  " << sm[i] << endl;
        len = sm.size();
        for (int i = 1; i < len; ++i)   
            sm[i] += sm[i - 1];
    }
    
    int pick() {
        int t = rand() % cap + 1;
        int id = lower_bound(sm.begin(), sm.end(), t) - sm.begin();
        return vec[id] + (sm[id] - t);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
void init(){
    vector<int> vec{1};
    Solution sol(3, vec);
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
