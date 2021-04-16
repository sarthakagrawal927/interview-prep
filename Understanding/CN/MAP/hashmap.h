#include <string>
#include <iostream>

using namespace std;
template <typename V>

class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename V>

class ourMap
{
    MapNode<V> **buckets;
    int count, numBuckets;

public:
    ourMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }

    ~ourMap()
    {
        for (int i = 0; i < numBuckets; i++)
            delete buckets[i];
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key) //O(length of string)
    {
        int hashcode = 0;
        int currentCoefficient = 1;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentCoefficient;
            hashcode %= numBuckets;
            currentCoefficient *= 37; // prime number give best distribution
            currentCoefficient %= numBuckets;
        }
        return hashcode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
            buckets[i] = NULL;
        int oldBucketCount = numBuckets;
        numBuckets *= 2; // numBuckets updated
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (count * 1.0) / numBuckets;
    }
    void insert(string key, V value) // load factor = each box entries = number of entries / number of boxes - we limit it to 0.7
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        // cout << node->value << " ";
        double loadFactor = (count * 1.0) / numBuckets;
        // cout << loadFactor << "endl";
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head)
        {
            if (head->key == key)
            {
                if (!prev)
                    buckets[bucketIndex] = head->next;
                else
                    prev->next = head->next;
                head->next = NULL; // recursive delete function hai, so next NULL will stop
                V value = head->value;
                delete head;
                count--; // update count
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // value not found
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex]; // go to head of that key
        while (head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0; // ni mila
    }
};