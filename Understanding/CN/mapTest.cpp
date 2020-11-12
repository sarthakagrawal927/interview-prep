#include "hashmap.h"
int main()
{
    ourMap<int> map;
    for (int i = 0; i < 20; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }
    cout << map.size();

    map.remove("abc2");
    map.remove("abc7");

    for (int i = 0; i < 20; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        cout << key << "  :  " << map.getValue(key) << endl;
    }

    cout << map.size();
}