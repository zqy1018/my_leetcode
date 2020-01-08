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
    vector<int> preorder(Node* root) {
        stack<Node *> st;
        vector<int> ans;
        if(root == NULL) return ans;
        st.push(root);
        while(!st.empty()){
            root = st.top(), st.pop();
            ans.push_back(root->val);
            for (Node *t: root->children)
                st.push(t);
        } 
        reverse(ans.begin(), ans.end());
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
