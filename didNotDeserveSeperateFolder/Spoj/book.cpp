#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   long double rating; int reviews,dig=0;
   cin >> rating >> reviews;
   cout << rating << '\n';
   int r = reviews;
   rating = rating * pow(reviews, 0.0097378);
   cout << rating;
   return 0;
}