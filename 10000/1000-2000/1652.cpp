#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int width = 0;
    int height = 0;
    int check = 0;

    char** arr = new char*[n]; 
    for(int i = 0; i < n; i++){
        arr[i] = new char[n];
    }
    // 2차원 배열 동적할당

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    } // 방의 구조 입력

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '.'){
                check++;
                
                if(j == n - 1){
                    if(check >= 2){
                        width++;
                    }
                    check = 0;
                }
            }
            else if(arr[i][j] == 'X'){
                if(check >= 2){
                    width++;
                }
                check = 0;
            }
        }
    }
    // 가로로 누울 수 있는 곳 카운트

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(arr[i][j] == '.'){
                check++;
                
                if(i == n - 1){
                    if(check >= 2){
                        height++;
                    }
                    check = 0;
                }
            }
            else if(arr[i][j] == 'X'){
                if(check >= 2){
                    height++;
                }
                check = 0;
            }
        }
    }
    // 세로로 누울 수 있는 곳 카운트

    cout << width << " " << height;
    // 누울 수 있는 곳 출력

    for(int i = 0; i < n; i++){
	    delete[] arr[i];
    }
    delete[] arr;
    // 동적할당 해제
}