// https://www.acmicpc.net/problem/10026
// 2026-01-12
#include <iostream>

using namespace std;

// 그리드 최대 크기
char greed[101][101];

// 방문 체크
int vis[101][101];

// 탐색 방향 지정 배열
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 탐색 함수
void find(int x, int y, char color, int n) {
    // x, y 범위 체크
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= n) return;

    // 방문 확인 및 색 확인
    if (vis[x][y] || greed[x][y] != color) return;

    // 방문 체크
    vis[x][y] = 1;

    // 탐색 재귀
    for (int i = 0; i < 4; i++) {
        find(x + dx[i], y + dy[i], color, n);
    }
}

// 영역 카운트 함수
int Acount(int n) {
    int count = 0; // 영역 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) { // 방문 하지 않은 곳 찾기
                find(i, j, greed[i][j], n);
                count++;
            }
        }
    }

    // 영역 개수 반환
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) { cin >> greed[i][j]; }

    // 일반인 영역 개수 출력
    cout << Acount(n) << " ";

    // 적록색약 -> G를 R로 바꾸기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
            if (greed[i][j] == 'G') greed[i][j] = 'R';
        }
    }

    // 적록색약 영역 개수 출력
    cout << Acount(n);
}