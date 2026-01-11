#include <iostream>
using namespace std;

int main(){
    int n[9];
    int s[9];
    int temp;
    int sum = 0;
    int r = 0;
    int memory[2];

    for(int i = 0; i < 9; i++){
        cin >> n[i];
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8 - i; j++){
            if(n[j] > n [j + 1]){
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(j == i){
                continue;
            }
            for(int k = 0; k < 9; k++){
                if(k == j || k == i){
                    continue;
                }
                else{
                    sum += n[k];
                }
            }

            if(sum == 100){
                for(int k = 0; k < 9; k++){
                    if(k == i || k == j){
                        continue;
                    }
                    else{
                        cout << n[k] << endl;
                    }
                }
                return 0;
            }
            else{
                sum = 0;
            }
        }
    }
}

// #include <iostream>
// using namespace std;

// int main(){
//     int n[9];
//     int s[9];
//     int temp;
//     int sum = 0;
//     int r = 0;
//     int memory[2];

//     for(int i = 0; i < 9; i++){
//         cin >> n[i];
//     }


//     for(int i = 0; i < 9; i++){
//         for(int j = 0; j < 9; j++){
//             if(j == i){
//                 r++;
//                 continue;
//             }
//             else if(j == i + 1){
//                 r++;
//                 continue;
//             }
//             else if(i == 8){
//                 if(j == 0){
//                     r++;
//                     continue;
//                 }
//                 else{
//                     while(r != 9){
//                         if(r == i || r == j){
//                             r++;
//                             continue;
//                         }
//                         else{
//                             sum += n[r];
//                             r++;
//                         }
                        
//                         if(sum == 100){
//                             memory[0] = i;
//                             memory[1] = j;
//                             break;
//                         }
//                     }
//                 }
//             }
//             else{  
//                 while(r != 9){
//                     if(r == i || r == j){
//                         r++;
//                         continue;
//                     }
//                     else{
//                         sum += n[r];
//                         r++;
//                     }
                    
//                     if(sum == 100){
//                         memory[0] = i;
//                         memory[1] = j;
//                         break;
//                     }
//                 }
//             }

//             r = 0;
//         }

//         if(sum == 100){
//             for(int k = 0; k < 9; k++){
//                 if(k == memory[0] || k == memory[1]){
//                         s[k] = 0;
//                         continue;                    
//                     }
//                     else{
//                         s[k] = n[k];
//                     }
//                 }

//                 break;
//             }

//         r = 0;
//         sum = 0;
//     }

//     for(int i = 0; i < 8; i++){
//         for(int j = 0; j < 8 - i; j++){
//             if(n[j] > n [j + 1]){
//                 temp = n[j];
//                 n[j] = n[j + 1];
//                 n[j + 1] = temp;
//             }
//         }
//     }

//     for(int i = 2; i < 9; i++){
//         cout << s[i] << endl;
//     }
// }