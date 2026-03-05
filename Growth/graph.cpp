#include <iostream>
#include <cmath>

using namespace std;

// 점 객체
class Point {
    int x, y;

public:
    Point(int pos_x, int pos_y); // 생성자

    // x, y 좌표 반환
    int getX() const { 
        return x;
    }

    int getY() const{
        return y;
    }
};

// 생성자
Point::Point(int pos_x, int pos_y){
    x = pos_x;
    y = pos_y;
}

class Geometry {
    public:
        Geometry() { // 생성자
            num_points = 0;
        }

        ~Geometry(){ // 소멸자 : AddPoint()에서 할당한 new Point 해제
            for(int i = 0; i < num_points; i++){
                delete point_array[i];
            }
        }

        // 점 추가
        void AddPoint(const Point &point) {
            point_array[num_points++] = new Point(point.getX(), point.getY());
        }

        // 현재 점의 개수 반환
        int printPoints(){
            return num_points; 
        }

        // 모든 점들 간의 거리를 출력하는 함수 입니다.
        void PrintDistance();

        // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
        // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
        // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
        // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void PrintNumMeets();

        // p1, p2를 잇는 직선이 p3를 지나는가 ?
        long long Match(long long int arr[], const Point &p3){
            long long int target_x = p3.getX();
            long long int target_y = p3.getY();

            long long int result = *(arr + 0) * target_x + *(arr + 1) * target_y + *(arr + 2);

            return result;
        }
    private:
        // 점 100 개를 보관하는 배열.
        Point* point_array[100];
        int num_points;
};

void Geometry::PrintDistance(){
    int count = 0; // 교점의 수
    for(int i = 0; i < num_points; i++){
        for(int j = i + 1; j < num_points; j++){
            long long int x1 = (*(point_array + i))->getX();
            long long int x2 = (*(point_array + j))->getX();
            long long int y1 = (*(point_array + i))->getY();
            long long int y2 = (*(point_array + j))->getY();

            double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

            cout << "Distance between \n(";
            cout << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is : ";
            cout << distance << '\n';
        }
    }
}

// 제미나이 버전
// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.

// void Geometry::PrintNumMeets() {
//     int count = 0;
//     // 점 4개면 4중 루프 돌아도 눈 깜짝할 새 끝나야 정상이야!
//     for (int i = 0; i < num_points; i++) {
//         for (int j = i + 1; j < num_points; j++) {
//             // i, j가 유효한지 체크
//             if (!point_array[i] || !point_array[j]) continue;

//             long long x1 = point_array[i]->getX();
//             long long y1 = point_array[i]->getY();
//             long long x2 = point_array[j]->getX();
//             long long y2 = point_array[j]->getY();

//             long long coef1[3] = { y1 - y2, x2 - x1, x1 * y2 - x2 * y1 };

//             for (int k = i + 1; k < num_points; k++) {
//                 for (int l = k + 1; l < num_points; l++) {
//                     // 점 4개가 겹치지 않게 철저히 방어!
//                     if (i == k || i == l || j == k || j == l) continue;
//                     if (!point_array[k] || !point_array[l]) continue;

//                     long long x3 = point_array[k]->getX();
//                     long long y3 = point_array[k]->getY();
//                     long long x4 = point_array[l]->getX();
//                     long long y4 = point_array[l]->getY();

//                     long long coef2[3] = { y3 - y4, x4 - x3, x3 * y4 - x4 * y3 };

//                     // 역참조 안전하게 호출!
//                     long long C = Match(coef1, *point_array[l]);
//                     long long D = Match(coef1, *point_array[k]);
//                     long long A = Match(coef2, *point_array[i]);
//                     long long B = Match(coef2, *point_array[j]);

//                     // 핵심: (C, D의 부호가 다름) '그리고' (A, B의 부호가 다름)
//                     bool ab_intersects_cd = (C <= 0 && D >= 0) || (C >= 0 && D <= 0);
//                     bool cd_intersects_ab = (A <= 0 && B >= 0) || (A >= 0 && B <= 0);

//                     if (ab_intersects_cd && cd_intersects_ab) {
//                         count++;
//                     }
//                 }
//             }
//         }
//     }
//     cout << "NumMeets count is " << count << endl;
// }

void Geometry::PrintNumMeets(){
    int count = 0; // 교점의 수

    for(int i = 0; i < num_points; i++){ // 점 A
        for(int j = i + 1; j < num_points; j++){ // 점 B
            long long int x1 = (*(point_array + i))->getX();
            long long int x2 = (*(point_array + j))->getX();
            long long int y1 = (*(point_array + i))->getY();
            long long int y2 = (*(point_array + j))->getY();

            // 직선 AB의 방정식 계수 (a, b, c)
            long long int coef1[3] = { y1 - y2, x2 - x1, x1 * y2 - x2 * y1};

            for(int k = i + 1; k < num_points; k++){ // 점 C
                for(int l = k + 1; l < num_points; l++){ // 점 D 선택
                    if (i == k || i == l || j == k || j == l) continue; // 하나라도 같은 점이 있으면 안 됌.
                    if (!point_array[k] || !point_array[l]) continue; // Nullptr 방지
                    
                    long long int x3 = (*(point_array + k))->getX();
                    long long int x4 = (*(point_array + l))->getX();
                    long long int y3 = (*(point_array + k))->getY();
                    long long int y4 = (*(point_array + l))->getY();

                    // 직선 AB의 방정식 계수 (a, b, c)
                    long long int coef2[3] = { y3 - y4, x4 - x3, x3 * y4 - x4 * y3};

                    // 점 C와 D가 직선 AB를 기준으로 각각 반대편에 있을까?
                    long long int C = Match(coef1, *(*(point_array + l)));
                    long long int D = Match(coef1, *(*(point_array + k)));

                    // 점 A와 B가 직선 CD를 기준으로 각각 반대편에 있을까?
                    long long int A = Match(coef2, *(*(point_array + i)));
                    long long int B = Match(coef2, *(*(point_array + j)));

                    // AB와 CD가 각각 음수여야 함. 오버플로우 때문에, 부호 비교로 대체하기
                    if(((C <= 0 && D >= 0) || (C >=0 && D <= 0)) && ((A >= 0 && B <= 0) || (A <= 0 && B >= 0))){
                        count++;
                    }
                }
            }
        }
    }

    cout << "NumMeets count is ";
    cout << count << '\n';
}

int main() {
    // 입력할 점 개수 points
    int points;
    cout << "Please Enter the count of points you want to calculate : ";
    cin >> points;

    // 점 입력
    Geometry graph;

    // 계산 입력
    cout << "Now, Please Enter what you want." << '\n';
    cout << "0 : Add Points, 1 : Print Distances, 2 : Print NumMeets" << '\n';
    cout << "3 : Print points count, ctrl + z : Quit Program" << '\n';
    int cmd;

    while(cin >> cmd && points){
        switch(cmd){
            case 0:{ // 점 입력
                cout << "Enter the points : ";
                int x, y;
                cin >> x >> y;

                Point point(x, y);
                graph.AddPoint(point);

                points--;
                break;
            }
            case 1:
                graph.PrintDistance();
                break;
            case 2:
                graph.PrintNumMeets();
                break;
            case 3:
                cout << "Now, your points count is : " << graph.printPoints() << '\n';
                break;
            default:
                cout << "Wrong Number.." << '\n';
        }

        cout << "Complete." << '\n';
        // 계산 입력
        cout << "Now, Please Enter what you want." << '\n';
        cout << "0 : Add Points, 1 : Print Distances, 2 : Print NumMeets" << '\n';
        cout << "3 : Print points count, ctrl + z : Quit Program" << '\n';
    }
}