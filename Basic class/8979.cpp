// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Country{
// private:
//     int cNumber; // 국가 번호
//     // 각 메달 개수
//     int gold; 
//     int silver;
//     int bronze; 
    

// public:
//     Country() {}
//     ~Country() {}

//     void setGold(int n){
//         gold = n;
//     }
    
//     void setSilver(int n){
//         silver = n;
//     }

//     void setBronze(int n){
//         bronze = n;
//     }

//     void setCNumber(int n){
//         cNumber = n;
//     }
    
//     int getGold() { return gold; }
//     int getSilver() { return silver; }
//     int getBronze() { return bronze; }
//     int getCNumber() { return cNumber; }
    
// };

// bool compare(int a, int b){ // 내림차순 정렬 기준
//     return a > b;
// }

// int main(){
//     int country; // 국가 수
//     int whtGrade; // 등수를 알고싶은 국가 번호
//     int cNumber; // 국가 번호
//     // 각 메달 개수
//     int gold;
//     int silver;
//     int bronze;
//     int rank = 1; //target country의 등수

//     vector<int> medal;

//     // 예제 입력 받기
//     cin >> country >> whtGrade;

//     // Country 객체 배열 선언 후, 각 배열에 정보 저장
//     Country *countries = new Country[country];
//     for(int i = 0; i < country; i++){
//         cin >> cNumber >> gold >> silver >> bronze;
//         (countries + i)->setCNumber(cNumber);
//         (countries + i)->setGold(gold);
//         (countries + i)->setSilver(silver);
//         (countries + i)->setBronze(bronze);
//     }

//     /*
//     각 메달마다 내림차순 정렬
//     메달 개수와 국가 매칭
//     순위 결정
//     */
   
//     vector<int> targetCountry; // 등수를 알고싶은 국가의 메달 개수 저장

//     for (int i = 0; i < country; i++){ 
//         if(countries[i].getCNumber() == whtGrade){
//             targetCountry.push_back(countries[i].getCNumber());
//             targetCountry.push_back(countries[i].getGold());
//             targetCountry.push_back(countries[i].getSilver());
//             targetCountry.push_back(countries[i].getBronze());
//             break;
//         }
//     }

//     for(int i = 0; i < country; i++){
//         medal.push_back((countries + i)->getCNumber());
//         medal.push_back((countries + i)->getGold());
//         medal.push_back((countries + i)->getSilver());
//         medal.push_back((countries + i)->getBronze());
//     }
    
    
//     cout << rank;

//     delete[] countries;
// }

#include <iostream>
using namespace std;
 
int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];
int res = 0;
 
int main() {
 
    //입력
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int index;
        cin >> index;
        cin >> gold[index] >> silver[index] >> bronze[index];
    }
 
    //1번 국가부터 N번 국가까지 K번 국가보다 더 잘한 국가일 경우 res++
    for (int i = 1; i <= N; i++) {
        if (gold[i] > gold[K]) {
            res++;
        }
        else if (gold[i] == gold[K]) {
            if (silver[i] > silver[K]) {
                res++;
            }
            else if (silver[i] == silver[K]) {
                if (bronze[i] > bronze[K]) {
                    res++;
                }
            }
        }
    }
 
    //출력
    cout << res + 1;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <tuple> // std::tie를 사용하기 위해 포함

// using namespace std;

// class Country{
// private:
//     int cNumber; // 국가 번호
//     int gold;    // 각 메달 개수
//     int silver;
//     int bronze; 

// public:
//     Country() : cNumber(0), gold(0), silver(0), bronze(0) {}
//     ~Country() {}

//     void setGold(int n){ gold = n; }
//     void setSilver(int n){ silver = n; }
//     void setBronze(int n){ bronze = n; }
//     void setCNumber(int n){ cNumber = n; }
    
//     // const 멤버 함수로 변경하여 sort의 람다식에서 사용할 수 있도록 함
//     int getGold() const { return gold; }
//     int getSilver() const { return silver; }
//     int getBronze() const { return bronze; }
//     int getCNumber() const { return cNumber; }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n; // 국가 수
//     int k; // 등수를 알고싶은 국가 번호
//     cin >> n >> k;

//     vector<Country> countries(n);
//     for(int i = 0; i < n; i++){
//         int num, g, s, b;
//         cin >> num >> g >> s >> b;
//         countries[i].setCNumber(num);
//         countries[i].setGold(g);
//         countries[i].setSilver(s);
//         countries[i].setBronze(b);
//     }

//     // 람다식을 사용하여 금, 은, 동 순으로 내림차순 정렬
//     sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
//         // std::tie를 사용하면 튜플처럼 묶어서 한 번에 비교할 수 있어 코드가 간결해집니다.
//         return tie(a.getGold(), a.getSilver(), a.getBronze()) > 
//                tie(b.getGold(), b.getSilver(), b.getBronze());
//     });

//     // 정렬된 리스트에서 k 국가의 인덱스 찾기
//     int target_idx = 0;
//     for(int i = 0; i < n; i++){
//         if(countries[i].getCNumber() == k){
//             target_idx = i;
//             break;
//         }
//     }

//     // 동점자 처리: k 국가와 메달 수가 같은 첫 번째 국가를 찾음
//     for(int i = target_idx - 1; i >= 0; i--){
//         if (countries[i].getGold() == countries[target_idx].getGold() &&
//             countries[i].getSilver() == countries[target_idx].getSilver() &&
//             countries[i].getBronze() == countries[target_idx].getBronze()) {
//             target_idx = i;
//         } else {
//             break;
//         }
//     }

//     // 등수는 인덱스 + 1
//     cout << target_idx + 1 << endl;

//     return 0;
// }