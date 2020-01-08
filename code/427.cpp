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
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
public:
    Node* build(int xx1, int yy1, int siz, vector<vector<int>>& grid){
        if(siz == 1)
            return new Node(grid[xx1][yy1], true, NULL, NULL, NULL, NULL);
        int hf = siz >> 1;
        Node *root = new Node(0, false, 
            build(xx1, yy1, hf, grid), 
            build(xx1, yy1 + hf, hf, grid),
            build(xx1 + hf, yy1, hf, grid),
            build(xx1 + hf, yy1 + hf, hf, grid));
        if(root->topLeft->isLeaf && root->topRight->isLeaf &&
            root->bottomLeft->isLeaf && root->bottomRight->isLeaf &&
            root->topLeft->val == root->topRight->val &&
            root->topLeft->val == root->bottomLeft->val &&
            root->topLeft->val == root->bottomRight->val){
                return root->topLeft;
            }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return NULL;
        return build(0, 0, n, grid);
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
