#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k];
}

// #include<iostream>
// #include<algorithm>
// using namespace std;

// int N, K;
// int DP[101][100001];
// int W[101];
// int V[101];

// // 점화식 max(DP[i-1][j], DP[i-1][j-W[i]])

// int main()
// {
// 	cin >> N >> K;

// 	for (int i = 1; i <= N; i++)
// 		cin >> W[i] >> V[i];

// 	for (int i = 1; i <= N; i++)
// 	{
// 		for (int j = 1; j <= K; j++)
// 		{
			 
// 			 if (j - W[i] >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
// 			 else DP[i][j] = DP[i - 1][j];
// 		}
// 	}

// 	cout << DP[N][K];

// }



// #include <iostream>
// #include <vector>
// using namespace std;

// int find(vector<int> vec, int order, int ing, int count, int end){
    
// }

// /*
//     vec: 무게 벡터를 전달 받은 파라미터
//     order: order번째 인덱스가 기준
//     n: 물건의 개수
// */
// vector<int> sumweight(vector<int> vec, int n, int order){
//     int sum = 0;
//     int max = 0;
//     sum += vec[order];
//     int temp = sum;
//     vector<int> sumarray;

//     for(int i = 0; i < n; i++){
//         if(i == order){
//             continue;
//         }
        
//         sum += vec[i];
//         sumarray.push_back(sum);
//         sum = temp;
//     }

//     return sumarray;
// }

// vector<int> findwhere(){

// }

// int sumvalue(){

// }

// int main(){
//     int n, k, w, v;
//     cin >> n >> k;
//     int temp = n;
//     vector<int> weight;
//     vector<int> value;

//     while(temp--){
//         cin >> w >> v;
//         weight.push_back(w);
//         value.push_back(v);
//     }

//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(weight[j] > weight[j + 1]){
//                 temp = weight[j];
//                 weight[j] = weight[j + 1];
//                 weight[j + 1] = temp;

//                 temp = value[j];
//                 value[j] = value[j + 1];
//                 value[j + 1] = temp;
//             }
//         }
//     }
    
//     vector<int> maxarray;
//     vector<int> sumarray;
//     for(int i = 0; i < n; i++){
//         sumarray = sumweight(weight, n, i);
//         for(int j = 0; j < n; j++){
//             if(sumarray[j] > k){
//                 continue;
//             }
//             else if(sumarray[j] == k){
//                 maxarray.push_back(sumarray[j]);
//             }
//             else{
//                 for(int l = 0; l < n; l++){
                    
//                 }
//             }
//         }
//     }
// }

// // vector<int> find(vector<int> vec, int n, int k, int sum, vector<int> maxarray, int check, int count, int order){
// //     int temp = 0;
// //     int max = 0;

// //     // 각각 검사하기
// //     if(check == 0){
// //         for(int i = 0; i < n; i++){
// //             if(vec[i] >= max && vec[i] <= k){
// //                 max = vec[i];
// //             }
// //         }

// //         maxarray.push_back(max);
// //         check++;
// //     }
// //     else{
// //         if(count == 0){
// //             sum += vec[order];
// //             // 서로 더하기
// //             for(int i = 0; i < n; i++){
// //                 if(i == order){
// //                     continue;
// //                 }
// //                 else{
// //                     // 탈락의 경우
// //                     if(sum + vec[i] > k){
// //                         continue;
// //                     }
// //                     // 최댓값 찾기
// //                     else{
// //                         if(sum + vec[i] >= max){
// //                             max = sum + vec[i];
// //                         }
// //                     }
// //                 }
// //             }

// //             // 최댓값 반환
// //             max != 0 ? maxarray.push_back(max) : max = 0;    
// //             count++;
// //         }
// //         else{
// //             // n개의 수를 합하고 서로 더하기
// //             int r = 0;
// //             temp = sum;
// //             int* rarr = new int[count];
            
// //             for(int i = 0; i < n; i++){
// //                 if(i == order){
// //                     continue;
// //                 }
                
// //                 // n개의 수 합하기
// //                 for(int j = 0; j < n; j++){
// //                     if(j == order){
// //                         continue;
// //                     }

// //                     if(r == count){
// //                         break;
// //                     }

// //                     sum += vec[j];
// //                     r++;
// //                     if(sum > k){
// //                         sum = temp;
// //                         continue;
// //                     }
// //                 }
// //             }
            
// //             // 최댓값 반환
// //             max != 0 ? maxarray.push_back(max) : max = 0;
// //             count++;
// //         }
// //     }

// //     return check == n ? maxarray : find(vec, n, k, sum, maxarray, check, count, order);
// // }

// // int main(){
// //     int n, k, w, v;
// //     cin >> n >> k;
// //     int count = n;

// //     vector<int> maxweight;
// //     vector<int> maxvalue;

// //     int sum = 0;
// //     while(n--){
// //         cin >> w >> k;
// //         maxweight.push_back(w);
// //         maxvalue.push_back(v);
// //         sum += maxweight.back();
// //     }
// // }

// // class bag{
// // public:
// //     int weight;
// //     int value;

// //     bag(){

// //     }

// //     ~bag(){

// //     }

// //     void setMaxweight(int k){
// //         maxweight = k;
// //     }

// //     void setWeight(int a){
// //         weight = a;
// //     }

// //     void setValue(int a){
// //         value = a;
// //     }

// // private:
// //     int maxweight;
// // };

// // int main(){
// //     int n, k, w, v;
// //     cin >> n >> k;
// //     bag *a = new bag[n];

// //     for(int i = 0; i < n; i++){
// //         cin >> w >> v;
// //         a[i].setWeight(w);
// //         a[i].setValue(v);
// //     }

// //     int sum = 0;
// //     vector<int> max;
// //     for(int i = 0; i < n; i++){
// //         sum = 0;
// //         if(a[i].weight > k){
// //             continue;
// //         }
// //         else if(a[i].weight == k){
// //             max.push_back(sum);
// //             break;
// //         }
        
// //         sum += a[i].weight;

// //         for(int j = 0; j < n; j++){
// //             if(j == i){
// //                 continue;
// //             }

// //             if(sum + a[j].weight > k){
// //                 continue;
// //             }
// //             else if(a[j].weight == k){
// //                 max.push_back(sum);
// //                 break;
// //             }
// //             sum += a[j].weight;

// //             for(int K = 0; K < n; K++){
// //                 if(K == i){
// //                     continue;
// //                 }
                
// //                 if(sum + a[K].weight > k){
// //                     continue;
// //                 }
// //                 else if(a[K].weight == k){
// //                     max.push_back(sum);
// //                     break;
// //                 }

// //                 sum += a[K].weight;
// //                 for(int m = 0; m < n; m++){
// //                     if(m == i){
// //                         continue;
// //                     }
            
// //                     if(sum + a[m].weight > k){
// //                         continue;
// //                     }
// //                     else if(a[m].weight == k){
// //                         max.push_back(sum);
// //                         break;
// //                     }
// //                     sum += a[m].weight;
// //                 }
// //             }
// //         }
// //     }
// // }