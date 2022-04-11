#include<iostream>
#include<vector>
using namespace std;
int a[10];
int book[10];
int n;
void dfs(int k) {
	if (k >= n) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		}
	cout << endl;
	return;
	}
	for (int i = 0; i < n; i++) {
		if (book[i] == 1)continue;//如果父节点使用过该数，就不继续这个分支
		a[k] = i+1;
		book[i] = 1;//表示该数字已经被使用过
		dfs(k + 1);
		book[i] = 0;//此分支已经已经退出，重置book[i]的状态//在进行下一层分支后，修改回原来状态，保证兄弟节点不受干扰
	}

}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}
