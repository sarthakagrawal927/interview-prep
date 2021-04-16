//https://www.codechef.com/AUG20B/problems/CHEFWARS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> win1, score1;
    int t; cin >> t;
    while (t--)
    {
        int chef, rick;
        cin >> chef >> rick;
        int chef_score = (int)chef / 9;
        int rick_score = (int)rick / 9;

        if (chef % 9 != 0)
            chef_score += 1;

        if (rick % 9 != 0)
            rick_score += 1;

        int win=0, score=0;

        if (rick_score <= chef_score)
        {
            win = 1;
            score = rick_score;
        }
        else
        {
            win = 0;
            score = chef_score;
        }
        win1.push_back(win); score1.push_back(score);
    }
    for (auto i = win1.begin(); i < win1.end(); i++)
        cout << *i << " " << *(i - win1.begin() + score1.begin()) << endl;

    return 0;
}