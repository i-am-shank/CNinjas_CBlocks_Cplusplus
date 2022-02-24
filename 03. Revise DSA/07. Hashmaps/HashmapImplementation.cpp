#include <iostream>
using namespace std;

template <typename V>
class mapNode {
    public:
    string key;
    V value;
    mapNode <V>* next;
    mapNode (string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapNode () {
        delete next;
    }
};

template <typename V>
class ourmap {
    private:
    int count;  // Count of unique keys stored in map
    int numBuckets;  // Bucket-size
    mapNode <V>** buckets;  //  Array of Arrays .. each member is a linked list.
    
    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        buckets = new mapNode<V>* [numBuckets];
        for(int i=0; i<numBuckets; i++) {  //  Avoid garbage values.
            buckets[i] = NULL;
        }
    }
    ~ourmap() {
        for(int i=0; i<numBuckets; i++) {
            delete buckets[i];
        }
        delete []buckets;
    }

    int size() {
        return count;
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;  // HashCode .. targeted to be unique for unique keys.
        int coeff = 1;
        for(int i=key.size()-1; i>=0; i--) {
            hashCode += key[i] * coeff;
            hashCode = hashCode % numBuckets;  // compression function (modulus here)
            coeff *= 37;
            coeff = coeff % numBuckets;  // Just to keep values in range of buckets & int
        }
        hashCode = hashCode % numBuckets;  // Compression function
        return hashCode;
    }

    public:
    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head->key != key  &&  head != NULL) {
            head = head->next;
        }
        if(head == NULL) {
            return 0;
        }
        else {
            return head->value;
        }
    }

    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        mapNode <V>* head = buckets[bucketIndex];
        while(head != NULL) {
            if(head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        mapNode<V>* newNode = new mapNode<V> (key, value);
        head = buckets[bucketIndex];
        newNode->next = head;  // Insert at head.. first mapNode at bucketIndex
        buckets[bucketIndex] = newNode;
        count++;  // A Unique key added .. which isn't present in map .. Increase count
        return;
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = NULL;
        while(head != NULL) {
            if(head->key == key) {
                if(prev == NULL) {
                    buckets[bucketIndex] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                V ans = head->value;
                head->next = NULL;
                delete head;
                count --;
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};

int main() {
    return 0;
}