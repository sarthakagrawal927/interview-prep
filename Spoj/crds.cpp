#include <iostream>
using namespace std;

int main(){
   long long int t;
    cin >> t;
    long long int a[t];
    for (int i = 0; i < t; i++){
        cin >> a[i];
    }
        for (int i = 0; i < t; i++)
        {
            long long int n = a[i];
            long long int n1 = n, n2 = 3 * n + 1;
            if (n % 2 == 0)
                n1 /= 2;
            else
                n2 /= 2;
            long long int ans = ((n1 % 1000007) * (n2 % 1000007)) % 1000007;
            cout << ans << '\n';
        }
    return 0;
}