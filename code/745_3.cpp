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

class WordFilter {
    vector<string> &wds, wds_rev;
    vector<int> id, id_rev;
    unordered_set<int> st;
    int n;
public:
    WordFilter(vector<string>& words): wds(words) {
        for (auto& s: words)
            wds_rev.push_back(s), 
            reverse(wds_rev.back().begin(), wds_rev.back().end());
        n = words.size();
        for (int i = 0; i < n; ++i) 
            id.push_back(i), id_rev.push_back(i);
        sort(id.begin(), id.end(), [&words](int i, int j){
            return words[i] < words[j];
        });
        sort(id_rev.begin(), id_rev.end(), [&](int i, int j){
            return wds_rev[i] < wds_rev[j];
        });
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        int l_plb = 0, r_plb = n;
        while (r_plb > l_plb){
            int mid_plb = (l_plb + r_plb) >> 1;
            if (wds[id[mid_plb]] < prefix) l_plb = mid_plb + 1;
            else r_plb = mid_plb;
        }
        int l_pub = 0, r_pub = n;
        while (r_pub > l_pub){
            int mid_pub = (l_pub + r_pub) >> 1;
            if (wds[id[mid_pub]] <= prefix) l_pub = mid_pub + 1;
            else r_pub = mid_pub;
        }
        int l_slb = 0, r_slb = n;
        while (r_slb > l_slb){
            int mid_slb = (l_slb + r_slb) >> 1;
            if (wds_rev[id_rev[mid_slb]] < suffix) l_slb = mid_slb + 1;
            else r_slb = mid_slb;
        }
        int l_sub = 0, r_sub = n;
        while (r_sub > l_sub){
            int mid_sub = (l_sub + r_sub) >> 1;
            if (wds_rev[id_rev[mid_sub]] <= suffix) l_sub = mid_sub + 1;
            else r_sub = mid_sub;
        }
        st.clear();
        int siz1 = l_pub - l_plb, siz2 = l_sub - l_slb;
        int ans = -1;
        if (!siz1 || !siz2) return ans;
        if (siz1 < siz2){
            for (int i = l_plb; i < l_pub; ++i)
                st.insert(id[i]);
            for (int i = l_slb; i < l_sub; ++i)
                if (st.count(id_rev[i]))
                    ans = max(ans, id_rev[i]);
        }else {
            for (int i = l_slb; i < l_sub; ++i)
                st.insert(id_rev[i]);
            for (int i = l_plb; i < l_pub; ++i)
                if (st.count(id[i]))
                    ans = max(ans, id[i]);
        }
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
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
