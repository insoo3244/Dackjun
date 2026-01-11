 #include <iostream>
 using namespace std;

 int main(){
    int a = 300;
    int b = 60;
    int c = 10;
    int t;

    cin >> t;
    int cnt[3]{ 0 };

    if(t % 10 != 0){
        cout << "-1";
    }
    else{
        while(t != 0){
            if(t >= a){
                t -= a;
                cnt[0]++;
            }
            else if(t >= b){
                t -= b;
                cnt[1]++;
            }
            else{
                t -= c;
                cnt[2]++;
            }
        }
        
        cout << cnt[0] << " " << cnt[1] << " " << cnt[2];   
    } 
 }