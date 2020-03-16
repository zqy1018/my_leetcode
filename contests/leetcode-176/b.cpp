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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

const int p = 2147483647;
class ProductOfNumbers {
    vector<int> mul;
    int inv(int x){
        int res = 1, b = p - 2;
        while (b > 0){
            if (b & 1) res = 1ll * res * x % p;
            x = 1ll * x * x % p, b >>= 1;
        }
        return res;
    }
public:
    ProductOfNumbers() {
        mul.clear();
        mul.push_back(1);
    }
    
    void add(int num) {
        if (!num) {
            mul.clear();
            mul.push_back(1);
        }else {
            mul.push_back(1ll * mul.back() * num % p);
        }
    }
    
    int getProduct(int k) {
        int t = mul.size();
        if (t < k + 1) return 0;
        return 1ll * mul[t - 1] * inv(mul[t - 1 - k]) % p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
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
