#include <iostream>
#include <vector>
using namespace std;

int main(){
   vector<int> girl;
   vector<int> boy;
   vector<int> ans;
   int g=0, b=0;
   while(g!=-1){
       cin >> g;
       cin >> b;
       girl.push_back(g);
       boy.push_back(b);
   }

   for( auto i = girl.begin(), j = boy.begin(); i < girl.end()-1; i++,j++){
       int min = (*i > *j)? *j : *i;
       min++;
       int sum = *i + *j;
       //cout << min << ' ' << sum << '\n';
       ans.push_back((int)(sum/min));
   }
   for( auto i = ans.begin(); i < ans.end(); i++) cout << *i << '\n';
    return 0;
}