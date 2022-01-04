#include <string>
#include <iostream>
using namespace std;

template <typename T>
class MapNode {
    public:
    string key;
    T value;
    MapNode *next;

    MapNode(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode () {
        delete next;
    }
};

template <typename T>
class ourmap {
    MapNode <T>* buckets;
    int size;
    int numBuckets;
    int count;

    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode <T>* [numBuckets];
    }

    ~ourmap() {
        for(int i=0; i<numBuckets; i++) {
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size() {
        return count;
    }

    T getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<T>* curr = buckets[bucketIndex];
        while(curr!=NULL && curr->key != key) {
            curr = curr->next;
        }
        if(curr == NULL) {
            return 0;    // Key not present in Hashmap, so returning value 0.
        }
        else {
            return curr->value;
        }
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;
        int coeff = 1;
        for (int i=key.length()-1; i>=0; i--) {
            hashCode += key[i] * coeff;
            hashCode %= numBuckets;
            coeff *= 37;
            coeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }

    public:
    void insert(string key, T value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<T>* head = buckets[bucketIndex];
        while(head != NULL) {
            if(head->key = key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<T>* node = new MapNode<T> (key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count ++;
    }

    T remove(string key) {
        int bucketIndex = getBucketIndex(key);
        T ans = 0;
        MapNode<T>* prev = NULL;
        MapNode<T>* curr = buckets[bucketIndex];
        while(curr!=NULL && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL) {
            count--;
            return 0;    // Key not present in Hashmap, so returning value 0.
        }
        else {
            if(prev == NULL) {
                buckets[bucketIndex] = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            ans = curr->value;
            curr->next = NULL;
            delete curr;
            count--;
            return ans;
        }
    }
};

int main() {

}