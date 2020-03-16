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
    long long gcd(long long a, long long b){
        return (b == 0 ? a : gcd(b, a % b));
    }
    vector<int> fraction(vector<int>& cont) {
        long long fz = 1, fm = cont.back();
        int n = cont.size();
        for (int i = n - 2; i >= 0; --i){
            long long nfz = fm, nfm = cont[i] * fm + fz;
            long long g = gcd(nfz, nfm);
            nfz /= g, nfm /= g;
            fz = nfz, fm = nfm;
        }
        long long g = gcd(fz, fm);
        fz /= g, fm /= g;
        vector<int> vec;
        vec.push_back(fz);
        vec.push_back(fm);
        return vec;
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
