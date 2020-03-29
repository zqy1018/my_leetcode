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

class UndergroundSystem {
    map<int, pair<string, int> > mp;
    map<pair<string, string>, pair<int, int> > mp2; 
public:
    UndergroundSystem() {
        mp.clear();
        mp2.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &p = mp[id];
        auto pp = make_pair(p.first, stationName);
        if (!mp2.count(pp)){
            mp2[pp] = make_pair(t - p.second, 1);
        }else {
            mp2[pp].first += t - p.second;
            ++mp2[pp].second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &p = mp2[make_pair(startStation, endStation)];
        return 1.0 * p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
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
