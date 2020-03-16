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
class StreamChecker {
public:
    queue<int> q;
    vector<vector<int> > c;
    vector<int> val, fail;
    int cnt;
    vector<char> text;
    void ins(string &s){
        int len = s.size();
        int now = 0;
        for(int i = 0; i < len; ++i){
            int v = s[i] - 'a';
            if(!c[now][v]){
                c[now][v] = ++cnt;
                c.push_back(vector<int>(26, 0));
            }
            now = c[now][v];
        }
        val[now]++;
    }
    void build(){
        fail.resize(cnt + 1);
        val.resize(cnt + 1);
        for(int i = 0; i < 26; ++i)
            if(c[0][i]) 
                fail[c[0][i]] = 0, q.push(c[0][i]);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < 26; ++i)
                if(c[u][i])
                    fail[c[u][i]] = c[fail[u]][i], q.push(c[u][i]);
                else c[u][i] = c[fail[u]][i];
        }
    }
    int query(){
        int len = strlen(s);
        int now=0,ans=0;
        for(int i=0;i<len;i++){
            now=c[now][s[i]-'a'];
            for(int t=now;t&&~val[t];t=fail[t])ans+=val[t],val[t]=-1;
        }
        return ans;
    }
    StreamChecker(vector<string>& words) {
        cnt = 0;
        c = vector<vector<int> >(1, vector<int>(26, 0));
    }
    
    bool query(char letter) {
        
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
StreamChecker sol;
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
