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


string sl1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string sl2[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string sl3[] = {"Billion", "Million", "Thousand", "Hundred"};
int t[] = {1000000000, 1000000, 1000, 100};
class Solution {
public:
    string dfs(int num){
        for (int i = 0; i < 4; ++i)
            if (num / t[i]){
                if (num % t[i] == 0) return dfs(num / t[i]) + " " + sl3[i];
                return dfs(num / t[i]) + " " + sl3[i] + " " + dfs(num % t[i]);
            }
        if (num < 20) return sl1[num];
        if (num % 10 == 0) return sl2[num / 10 - 2];
        return sl2[num / 10 - 2] + " " + sl1[num % 10];
    }
    string numberToWords(int num) {
        if (!num) return string("Zero");
        string ans = dfs(num);
        if (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.numberToWords(123);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
