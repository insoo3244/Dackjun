#include <iostream>

int main(void)
{
int val1;
int val2;
int val3;
int val4;
int val5;

 std::cout<<"1: "<<std::endl;
 std::cin>>val1;

  std::cout<<"2: "<<std::endl;
 std::cin>>val2;

  std::cout<<"3: "<<std::endl;
 std::cin>>val3;

  std::cout<<"4: "<<std::endl;
 std::cin>>val4;

  std::cout<<"5: "<<std::endl;
 std::cin>>val5;
int result=val1+val2+val3+val4+val5;
std::cout<<"result: "<<result<<std::endl;
return 0;

}
// int main(){
//     int n;
//     int d;
//     int sum = 0;

//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cout << i << "st input: ";
//         cin >> d;
//         sum += d;
//     }

//     cout << "sum: " << sum;
// }