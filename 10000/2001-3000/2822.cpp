// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> sort(vector<int> target) {
//     int n = target.size();
//     int temp;

//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(target[j] > target[j + 1]){
//                 temp = target[j];
//                 target[j] = target[j + 1];
//                 target[j + 1] = temp;
//             }
//         }
//     }

//     return target;
// }

// int main(){
//     int n = 8;
//     int sum = 0;
//     vector<int> digit(8);
//     vector<int> copy(8);

//     for(int i = 0; i < 8; i++){
//         cin >> digit[i];
//         copy[i] = digit[i];
//     }

//     auto score = sort(digit);

//     for(int i = 0; i < 5; i++){
//         sum += score[7 - i];
//     }
    
//     cout << sum << endl;

//     for(int i = 0 ; i < 8; i++){
//         if(copy[i] >= score[3]){
//             cout << i + 1 << " ";
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

class problem {
public:
    int score;      // 문제 점수
    int num;        // 문제 번호
};

// 문제의 점수를 기준으로 "내림차순" 정렬 
bool cmp(problem a, problem b) {
    return a.score > b.score;
}

int main() {
    problem* p = new problem[8];
    int sum = 0;
    int arr[8];    // 문제번호를 복사해, 따로 정렬해주기 위한 배열

    for (int i = 0; i < 8; i++) {
        cin >> p[i].score;
        p[i].num = i + 1;
    }

    // 안정정렬 (기존의 문제의 번호와 점수에 대한 순서가 바뀌지 X)
    stable_sort(p, p + 8, cmp);

    for (int i = 0; i < 5; i++) {
        sum += p[i].score;
        arr[i] = p[i].num;
    }

    // 문제의 번호만 순서대로 정렬
    sort(arr, arr + 5);

    cout << sum << "\n";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}