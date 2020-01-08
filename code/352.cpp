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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    multiset<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (st.count(val))
            return ;
        st.insert(val);
        auto iter = st.find(val);
        if (distance(st.begin(), iter) & 1) {
            st.erase(iter);
            return ;
        }
        auto iter2 = iter;
        ++iter2;
        if (iter != st.begin() && iter2 != st.end()){
            auto iter3 = iter;
            --iter3;
            int l = *iter3, r = *iter2;
            if (l == val - 1 && r == val + 1)
                st.erase(iter3), st.erase(iter2), st.erase(iter);
            else if (l == val - 1)
                st.erase(iter3);
            else if (r == val + 1)
                st.erase(iter2);
            else st.insert(val);
        }else if (iter != st.begin()){
            auto iter3 = iter;
            --iter3;
            if (*iter3 == val - 1){
                st.erase(iter3);
            }else st.insert(val);
        }else if (iter2 != st.end()){
            if (*iter2 == val + 1){
                st.erase(iter2);
            }else st.insert(val);
        }else st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        cout << st.size() << endl;
        for (auto iter = st.begin(); iter != st.end(); ++iter){
            vector<int> vec{*iter};
            ++iter;
            vec.push_back(*iter);
            ans.push_back(vec);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
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
