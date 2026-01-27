// https://www.acmicpc.net/problem/1700
// 2026-01-27
#include <iostream>
#include <vector>

using namespace std;

/*
    전략 구상

    멀티탭 자리 개수와, 사용 횟수를 입력받음
    사용 용도는 번호로 구분됨. 멀티탭의 자리는 한정되있으므로, 
    가장 콘센트를 적게 빼고 끼는 횟수를 구해야 함

    상황: 멀티탭 구멍이 2개이고, 현재 [드라이기, 노트북]이 꽂혀 있음
    이제 [고데기]를 꽂아야 해서 하나를 뽑아야 함

    앞으로의 사용 계획표:
    (지금) 고데기
    (10분 뒤) 드라이기 사용 예정
    (3시간 뒤) 노트북 사용 예정

    드라이기 보다는 노트북을 빼는 것이 횟수를 줄이는 데 더 유리함
        -> 기준은, "더 늦게 사용하는 것". 배열의 순서가 이를 결정함
*/

vector<int> multap; // 멀티탭 사용 정보
vector<int> use; // 사용 횟수를 기록할 벡터
int cnt = 0; // 콘센트를 뺀 횟수

int main(){
    // 멀티탭 구멍 개수 및 전기용품 사용 횟수
    int n, k;
    cin >> n >> k;

    // 사용 횟수를 기록할 벡터
    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        use.push_back(temp);
    }

    // 멀티탭 스케쥴 시작
    for(int i = 0; i < k; i++){
        bool isIn = false; // 내가 쓸 것이 꽂혀 있나?
        for(auto x : multap){
            if(use[i] == x){ // 꽂혀 있음 확인
                isIn = true;
                break; 
            }
        }

        if(isIn){ // 꽂혀 있다면,
            continue;
        }
        else { // 안꽂혀있다면,
            // 우선 빈 자리가 있는 지 검사.
            if(multap.size() < n){ // 있다면,
                multap.push_back(use[i]); // 꽂기
                continue;
            }
            else{ // 없다면,
                // 내가 사용 중인 콘센트 중에,
                // 앞으로 사용할 기록 중, 가장 늦게 쓰이거나 안쓰이는 걸 새로 덮어 씌우기
                int u_temp = -1; // use : 가장 나중에 사용되는 인덱스 저장
                int mul_temp = -1; // mul : 멀티탭에서 뺄 자리
                // 위의 두 변수가 -1로 초기화 된 이유는, 최솟값이 0인 경우를 대비하고자 함

                for(int idx = 0; idx < multap.size(); idx++){ // 멀티탭을 둘러보고,
                    int temp = 0; // i번 용도가 언제 다시 쓰일 지 저장
                    for(int j = i + 1; j < k; j++){ // 사용 기록을 확인하면서, 
                        if(multap[idx] == use[j]){ // 지금 꽂혀 있는 콘센트가 나중에 또 쓰이면,
                            temp = j; // 해당 인덱스 저장
                            break; // 가장 가까운, 재사용 시점만 찾기
                        }
                    }
                    
                    if(temp == 0){ // 현재 번호가 앞으로도 안쓰이는 경우
                        mul_temp = idx; // 교체할 멀티탭 자리 갱신
                        break;
                    }

                    if(temp > u_temp){ // 쓰이긴 하지만, 더 늦는 타이밍이 있을 경우
                        u_temp = temp; // 가장 늦는 인덱스 갱신
                        mul_temp = idx; // 교체할 멀티탭 자리 갱신
                    }
                }

                multap[mul_temp] = use[i]; // 해당 멀티탭 자리에 덮어 쓰기
                cnt++;
            }

        }
    }

    // 출력
    cout << cnt;
}