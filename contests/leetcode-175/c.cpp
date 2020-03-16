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
class TweetCounts {
    unordered_map<string, int> mp;
    set<int> st[10005];
    string t1, t2, t3;
    int cnt;
public:
    TweetCounts() {
        mp = unordered_map<string, int>();
        cnt = 0;
        for (int i = 1; i <= 10000; ++i)
            st[i] = set<int>();
        t1 = string("day");
        t2 = string("minute");
        t3 = string("hour");
    }
    
    void recordTweet(string tweetName, int time) {
        if (!mp.count(tweetName))
            mp[tweetName] = ++cnt;
        st[mp[tweetName]].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int gap = 0;
        if (freq == t1) gap = 86400;
        if (freq == t2) gap = 60;
        if (freq == t3) gap = 3600;
        int timegap = endTime - startTime + 1;
        vector<int> ans((timegap - 1) / gap + 1, 0);
        
        if (!mp.count(tweetName)) return ans;
        int iid = mp[tweetName];
        auto& s = st[iid];
        if (s.empty()) return ans;

        auto iter = s.lower_bound(startTime);
        
        while (iter != s.end()){
            int t = *iter;
            if (t > endTime) break;
            int id = (t - startTime) / gap;
            ++ans[id];
            ++iter;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
void init(){
    TweetCounts a;
    a.recordTweet("a", 12);
    a.recordTweet("b", 39);
    a.recordTweet("a", 12);
    a.recordTweet("b", 39);
    a.recordTweet("a", 12);
    a.recordTweet("b", 39);
    a.recordTweet("a", 10);
    cout << a.getTweetCountsPerFrequency("day", "a", 0, 59);
    a.recordTweet("a", 120);
    cout << a.getTweetCountsPerFrequency("hour", "a", 0, 210);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
