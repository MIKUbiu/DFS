#include<iostream>
using namespace std;
int book[10];
int a[10];
bool judge() {
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++) {
            //对第i皇后后面每一个皇后都与之不同
            if (j - i == abs(a[i] - a[j]))return false;

        }
}
void dfs(int k) {
    if (k >= 8) {
        if (judge()) {
            copy(a, a + 8, ostream_iterator<int>(cout, ""));
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (book[i])continue;
        book[i] = 1;
        a[k] = i;
        dfs(k + 1);
        book[i] = 0;
    }
}
int main()
{
    dfs(0);

    return 0;
}