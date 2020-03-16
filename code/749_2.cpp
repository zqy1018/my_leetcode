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
	vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    void show(vector<vector<int>>& grid){
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
	int containVirus(vector<vector<int>>& grid) {
		int res = 0, tempRes = 0;
		while ((tempRes = findMaxVirus(grid))) {
			res += tempRes;
            show(grid);
            cout << res << endl;
		}
		return res;
	}
	//进行一次病毒隔离操作
	int findMaxVirus(vector<vector<int>>& grid) {
		int needNum = 0, maxVirus = 0, maxTarRow = 0, maxTarCol = 0;
		int rowSize = grid.size(), colSize = grid[0].size();
		vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
		//第一步：寻找即将扩张感染的区域最大的病毒区
		for (int row = 0; row < rowSize; ++row) {
			for (int col = 0; col < colSize; ++col) {
				if (grid[row][col] == 1 && !visited[row][col]) {
					//如果grid[row][col]是病毒区，并且没有访问过
					vector<vector<bool>> tempVisited(rowSize, vector<bool>(colSize, false));
					int virusNum = calVirus(grid, visited, tempVisited, row, col);
					if (virusNum > maxVirus) {
						maxVirus = virusNum;
						maxTarRow = row;
						maxTarCol = col;
					}
				}
			}
		}
		if (maxVirus != 0) {
			//第二步：将即将扩张感染的区域最大的病毒区隔离
			needNum = floorFill(grid, maxTarRow, maxTarCol);
			//第三步：将其他未处理的病毒区进行扩张
			vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
			for (int row = 0; row < rowSize; ++row) {
				for (int col = 0; col < colSize; ++col) {
					if (grid[row][col] == 1 && !visited[row][col]) {
						//如果grid[row][col]是病毒区，并且没有访问过
						virusExpand(grid, visited, row, col);
					}
				}
			}

		}
		return needNum;
	}
	//计算grid[row][col]这个病毒区即将感染的区域大小
	int calVirus(vector<vector<int>>& grid, vector<vector<bool>> &visited, vector<vector<bool>> &tempVisited, int row, int col) {
		visited[row][col] = tempVisited[row][col] = true;//标记访问
		int rowSize = grid.size(), colSize = grid[0].size(), tempRes = 0;
		//四个方向进行搜索
		for (auto &direction : directions) {
			int nextRow = row + direction.first;
			int nextCol = col + direction.second;
			//不能出界、不能是访问过的、不能是已经隔离了的
			if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize || tempVisited[nextRow][nextCol] || grid[nextRow][nextCol] == -1) {
				continue;
			}
			if (grid[nextRow][nextCol] == 0) {//这个区域将受到威胁
				tempRes += 1;
				tempVisited[nextRow][nextCol] = true;//标记威胁过
			}
			else {
				tempRes += calVirus(grid, visited, tempVisited, nextRow, nextCol);//继续搜索
			}
		}
		return tempRes;
	}
	//将grid[row][col]这个病毒区进行隔离
	int floorFill(vector<vector<int>>& grid, int row, int col) {
		grid[row][col] = -1;//对病毒进行隔离
		int rowSize = grid.size(), colSize = grid[0].size(), tempRes = 0;
		//四个方向进行搜索
		for (auto &direction : directions) {
			int nextRow = row + direction.first;
			int nextCol = col + direction.second;
			//不能出界、不能是访问过的、不能是已经隔离了的
			if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize || grid[nextRow][nextCol] == -1) {
				continue;
			}
			if (grid[nextRow][nextCol] == 1) {
				tempRes += floorFill(grid, nextRow, nextCol);
			}
			else {
				tempRes += 1;
			}
		}
		return tempRes;
	}
	//将grid[row][col]这个病毒区进行扩张
	void virusExpand(vector<vector<int>>& grid, vector<vector<bool>> &visited, int row, int col) {
		visited[row][col] = true;
		int rowSize = grid.size(), colSize = grid[0].size();
		//四个方向进行搜索
		for (auto &direction : directions) {
			int nextRow = row + direction.first;
			int nextCol = col + direction.second;
			if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize || visited[nextRow][nextCol] || grid[nextRow][nextCol] == -1) {
				continue;
			}
			if (grid[nextRow][nextCol] == 0) {//对病毒进行扩张
				grid[nextRow][nextCol] = 1;
				visited[nextRow][nextCol] = true;//标记已经访问过、并且是扩展的病毒（不能再次放入扩展）
			}
			else {
				virusExpand(grid, visited, nextRow, nextCol);
			}
		}
	}
};
Solution sol;
void init(){
    vector<vector<int>> vec = 
        {{0,0,1,1,1,0,1,0,0,0},{1,1,1,0,0,0,1,1,0,1},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,1,0,1,0,0,0},{1,0,0,0,1,1,1,0,0,0},{0,0,0,1,0,1,1,0,0,0},{1,0,0,0,0,1,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{0,1,0,0,0,0,0,0,1,0},{1,1,0,0,0,1,0,1,0,0}};
    cout << sol.containVirus(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
