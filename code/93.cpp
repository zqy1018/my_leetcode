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

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12)
            return vector<string>();
        vector<string> ans;
        int n = s.length();
        for (int i = 1; i < n - 2 && i < 4; ++i){
            if(i > 1 && s[0] == '0')
                continue;
            for (int j = (n - i > 9) ? n: i + 1; j < n - 1 && j < i + 4; ++j){
                if(j - i > 1 && s[i] == '0')
                    continue;
                for (int k = (n - j > 6) ? n: j + 1; k < n && k < j + 4; ++k){
                    if(k - j > 1 && s[j] == '0')
                        continue;
                    if(n - k > 1 && s[k] == '0')
                        continue;
                    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
                    for (int t = 0; t < i; ++t) num4 = num4 * 10 + s[t] - '0';
                    for (int t = i; t < j; ++t) num1 = num1 * 10 + s[t] - '0';
                    for (int t = j; t < k; ++t) num2 = num2 * 10 + s[t] - '0';
                    for (int t = k; t < n; ++t) num3 = num3 * 10 + s[t] - '0';
                    if (num1 < 256 && num2 < 256 && num3 < 256 && num4 < 256)   
                        ans.push_back(s.substr(0, i) + "." + s.substr(i, j - i) 
                            + "." + s.substr(j, k - j) + "." + s.substr(k, n - k));
                }
            }
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
