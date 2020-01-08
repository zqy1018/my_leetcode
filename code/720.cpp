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
    string longestWord(vector<string>& words) {
        int n = words.size();
        if (!n) return string("");
        vector<int> vec(n, 0);
        for (int i = 0; i < n; ++i) vec[i] = i;
        sort(vec.begin(), vec.end(), [&words](int x, int y)
            { return words[x].length() == words[y].length() ?
                words[x] < words[y]: words[x].length() < words[y].length(); });
        if (words[vec[0]].length() > 1) return string("");
        int ans = vec[0], i = 0, lst = 0;
        while (i < n && words[vec[i]].length() == 1) ++i;
        for (int len = 2; i < n; ++len){
            if (words[vec[i]].length() != len) break;
            int j = i; 
            while (j < n && words[vec[j]].length() == len)
                ++j;
            for (int k = i; k < j; ++k){
                char c = words[vec[k]].back();
                words[vec[k]].pop_back();
                bool flag = false;
                for (int t = lst; t < i; ++t){
                    if (words[vec[k]] == words[vec[t]]){
                        flag = true;
                        if (words[ans].length() < len) ans = vec[k];
                        break;
                    }
                }
                if (flag)
                    words[vec[k]].push_back(c);
            }
            lst = i, i = j;
        }
        return words[ans];
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
