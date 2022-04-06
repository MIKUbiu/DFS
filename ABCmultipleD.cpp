#include<iostream>
#include<vector>
using namespace std;
int a[10];
int book[10];
int n;
int b[10];
int maxn = 0;int res = 0;
void dfs(int k) {
	if (k >= n) {
		res = (a[0] * 100 + a[1] * 10 + a[2]) * a[3];//记录分支的值
		if (maxn<= res)maxn= res;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (book[i] == 1)continue;
		a[k] = b[i];
		book[i] = 1;//表示该数字已经被使用过
		dfs(k + 1);
		book[i] = 0;//此分支已经已经退出，重置book[i]的状态
	}

}
int main() {
	n = 4;
	while (cin >> b[0] >> b[1] >> b[2] >> b[3]) {
		maxn = 0;
		dfs(0);
		cout << maxn << endl;
	}

	return 0;
}
