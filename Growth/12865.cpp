#include <iostream>
#include <vector>
using namespace std;

class bag{
public:
    int weight;
    int value;

    bag(){

    }

    ~bag(){

    }

    void setMaxweight(int k){
        maxweight = k;
    }

    void setWeight(int a){
        weight = a;
    }

    void setValue(int a){
        value = a;
    }

private:
    int maxweight;
};

int main(){
    int n, k, w, v;
    cin >> n >> k;
    bag *a = new bag[n];

    for(int i = 0; i < n; i++){
        cin >> w >> v;
        a[i].setWeight(w);
        a[i].setValue(v);
    }

    int sum = 0;
    vector<int> max;
    for(int i = 0; i < n; i++){
        sum = 0;
        if(a[i].weight > k){
            continue;
        }
        else if(a[i].weight == k){
            max.push_back(sum);
            break;
        }
        
        sum += a[i].weight;

        for(int j = 0; j < n; j++){
            if(j == i){
                continue;
            }

            if(sum + a[j].weight > k){
                continue;
            }
            else if(a[j].weight == k){
                max.push_back(sum);
                break;
            }
            sum += a[j].weight;

            for(int K = 0; K < n; K++){
                if(K == i){
                    continue;
                }
                
                if(sum + a[K].weight > k){
                    continue;
                }
                else if(a[K].weight == k){
                    max.push_back(sum);
                    break;
                }

                sum += a[K].weight;
                for(int m = 0; m < n; m++){
                    if(m == i){
                        continue;
                    }
            
                    if(sum + a[m].weight > k){
                        continue;
                    }
                    else if(a[m].weight == k){
                        max.push_back(sum);
                        break;
                    }
                    sum += a[m].weight;
                }
            }
        }
    }
}