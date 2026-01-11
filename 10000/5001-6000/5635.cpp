#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string name;
    string uname;
    string oname;

    int d, m, y;
    int md{0}, mm{0}, my{0};
    int nd{0}, nm{0}, ny{0};

    while(n--){
        cin >> name >> d >> m >> y;
        
        if(y > my){
            my = y;
            mm = m;
            md = d;
            uname = name;
            if(ny == 0){
                ny = y;
                nm = m;
                nd = d;
                oname = name;
            }
        }
        else if(y == my){
            if(m > mm){
                my = y;
                mm = m;
                md = d;
                uname = name;
            }
            else if(m == mm){
                if(d > md){
                    my = y;
                    mm = m;
                    md = d;
                    uname = name;
                }
            }
        }
        else{
            if(y == ny){
                if(m < nm){
                    ny = y;
                    nm = m;
                    nd = d;
                    oname = name;
                }
                else if(m == nm){
                    if(d < nd){
                        ny = y;
                        nm = m;
                        nd = d;
                        oname = name;
                    }
                }
            }
            else if(y < ny){
                ny = y;
                nm = m;
                nd = d;
                oname = name;
            }
        }
    }

    cout << uname << endl;
    cout << oname;
}