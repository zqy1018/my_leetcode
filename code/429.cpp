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
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<Node *> f[2];
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        f[0].push_back(root);
        for (int i = 0; !f[i & 1].empty(); ++i){
            ans.push_back(vector<int>());
            for (Node *t: f[i & 1]){
                ans[i].push_back(t->val);
                for (Node *c: t->children)
                    f[(i & 1) ^ 1].push_back(c);
            }
            f[i & 1].clear();
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
