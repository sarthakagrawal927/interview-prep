#include <iostream>
#include <string>
using namespace std;

int main(){
    string s ;
    cin >> s;
    int t = (int)s[s.length() - 1] - 48;
    int a = (t != 0) ? 1 : 2;
    cout << a;
    if(a==1) cout << '\n' << t;
    return 0;
}
