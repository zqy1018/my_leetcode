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


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<const vector<NestedInteger>*> nst;
    stack<vector<NestedInteger>::const_iterator> iter; 

    void findNext(){
        while (!nst.empty()){
            vector<NestedInteger>::const_iterator& cur_iter = iter.top();
            const vector<NestedInteger>& cur = *nst.top();
            if (cur_iter == cur.end()){
                nst.pop(), iter.pop();
            }else if(!iter.top()->isInteger()){
                nst.push(&(iter.top()->getList()));
                iter.push(nst.top()->begin());
            }else break;
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty()){
            nst.push(&nestedList);
            iter.push(nestedList.begin());
            findNext();
        }
    }

    int next() {
        int res = iter.top()->getInteger();
        vector<NestedInteger>::const_iterator& cur_iter = iter.top();
        iter.pop(), iter.push(cur_iter + 1);
        findNext();
        return res;
    }

    bool hasNext() {
        return !nst.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
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
