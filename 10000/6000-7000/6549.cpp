#include <iostream>
#include <vector>

using namespace std;


void enterGraph(int n); // 그래프 입력 함수

int main(){
    int repeat = 0; // 반복계수

    while(1){ 
        cin >> repeat; // 0 입력시 종료 / 동시에 입력할 정수 개수 입력
        if(repeat == 0) { break; }
        enterGraph(repeat); 
    }
}

void enterGraph(int n){
    int *height = new int [n]; // 높이 저장 배열
    for(int i = 0; i < n; i++){
        cin >> height[i]; // 그래프 정보 저장
    }
    
    vector<int> stack;
    long long max_area = 0; // 최대 넓이
    // height는 각 막대의 높이를 저장, stack은 막대의 인덱스 번호를 저장할 것임

    // i 번째 막대 = 현재 탐색 중인 막대
    // 스택이 비어있지 않을 때, i 번째 막대가 기준 막대보다 클 때 : 스택에 막대의 인덱스 번호 저장
    // 스택이 빌 때 까지, i 번째 막대가 기준 막대보다 작을 때 (i 번째 막대보다 큰 막대를 전부 제거)
    // : 기준 막대의 정보를 저장하고, 스택에서 제거 (top = stack.back() 이후, pop_back())
    // width(너비) = 스택이 비어있다면 현재 탐색 번호, 비어있지 않다면 i - 이전 막대 인덱스 번호 - 1. (너비를 구하는 방법)
    // 넓이 = height[top]  * width
    // 만약 스택에 현재 탐색 막대보다 더 높은 막대가 남아있다면 위 반복문 재실행

    // 모든 작업이 끝나면 스택에 현재 탐색 인덱스 번호 push. 

    for (int i = 0; i <= n; i++) {
        int current_height = (i == n) ? 0 : height[i]; // 현재 탐색 막대 높이
        // i == n 인 경우는 왜 만들어져있나 ? 
        // i를 배열 끝까지 순회했음에도 불구하고 스택에 남아있는 값들을 계산하지 못할 수 있음
        // 일부러 길이가 0인 막대를 마지막에 추가해서 남은 값까지 계산하기 위함
        
        while (!stack.empty() && current_height < height[stack.back()]) { 
            int top = stack.back();
            stack.pop_back();

            int width = stack.empty() ? i : i - stack.back() - 1;
            long long area = (long long)height[top] * width;
            max_area = max(max_area, area);
        }

        stack.push_back(i);
    }

    cout << max_area << "\n";
}