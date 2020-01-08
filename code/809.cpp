#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){# Write your MySQL query statement below
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT 
        (SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT N - 1, 1) AS SecondHighestSalary 
  );
END

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

pair<char, int> pp[105];
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0, tot = 0, l = S.length();
        for (int i = 0; i < l; ){
            int j = i;
            while (j < l && S[i] == S[j])
                ++j;
            pp[++tot].first = S[i], pp[tot].second = j - i;
            i = j;
        }
        for (string& s: words){
            int n = s.length(), cur = 1;
            bool flag = true;
            for (int i = 0; i < n; ){
                int j = i;
                while (j < n && s[i] == s[j])
                    ++j;
                if (cur > tot) { flag = false; break; }
                if (pp[cur].first != s[i]) { flag = false; break; }
                if (pp[cur].second < 3 && j - i != pp[cur].second)
                    { flag = false; break; }
                if (pp[cur].second < j - i)
                    { flag = false; break; }
                ++cur, i = j;
            }
            if (cur != tot + 1) flag = false;
            if (flag) ++ans;
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
