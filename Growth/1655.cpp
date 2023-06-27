#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int n;
    cin >> n;
    int d;

    int a;
    int b;
    while(n--){
        cin >> d;
        if(max.size() > min.size()){
            min.push(d);
        }
        else{
            max.push(d);
        }

        if(!max.empty() && !min.empty()){
            if(max.top() > min.top()){
                a = max.top();
                max.pop();
                b = min.top();
                min.pop();

                max.push(b);
                min.push(a);
            }
        }

        cout << max.top() << endl;
    }
}
