#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 전역 변수로 캔버스 선언
vector<string> canvas;

void draw_tree(int row, int left, int right) {
    if (left > right) return;  // 탈출 조건

    int mid = (left + right) / 2;  // 중간 지점 계산
    canvas[row][mid] = 'x';  // 현재 위치에 'x' 노드 그리기

    if (row + 1 < canvas.size()) {  // 다음 행이 존재하는 경우
        draw_tree(row + 1, left, mid - 1);  // 왼쪽 자식 재귀 호출
        draw_tree(row + 1, mid + 1, right);  // 오른쪽 자식 재귀 호출
    }
}

int main() {
    int height = 4;  // 트리의 높이
    int width = (1 << height) - 1;  // 가장 마지막 레벨에 노드가 위치할 수 있는 최대 범위 계산

    // 캔버스 초기화
    canvas.resize(height);
    for (int i = 0; i < height; ++i) {
        canvas[i] = string(width, '-');  // 각 행을 '-'로 채움
    }

    draw_tree(0, 0, width - 1);  // 트리 그리기 시작

    // 결과 출력
    for (auto& line : canvas) {
        cout << line << endl;
    }

    return 0;
}
