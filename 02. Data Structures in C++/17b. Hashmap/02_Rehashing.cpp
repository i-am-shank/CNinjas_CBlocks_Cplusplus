#include <iostream>
#include <string>
using namespace std;

template <typename V>
class mapNode{
public:
	string key;
	V value;
	mapNode* next;

	// Constructor
	mapNode(string k, V val) {
		key = k;
		value = val;
		next = NULL;
	}

	// Destructor
	~mapNode() {
		delete next;
		// Recursion will delete all nodes
	}
};

template <typename V>
class ourmap{
	mapNode<V>** buckets;
	int count;
	int numBuckets;

	int getBucketIndex(string key) {
		// Get hash-code   ("abc")
		// ---->  a*(p^2) + b*(p^1) + c*(p^0)
		// Apply compression function
		// ---->  % bucketSize
		// Get index as result !
		int hashCode=0;
		int coeff = 1; // Coefficient
		for(int i=key.size()-1; i>=0; i--) {
			hashCode += (((int)key[i])*(coeff));
			coeff *= 37; // Taking prime no.
			coeff = (coeff % numBuckets);
			// .. Prime no. gives more-uniform distribution
			hashCode = (hashCode % numBuckets);
			// Keep doing modulo .. else will go out of range soon.
		}
		return (hashCode % numBuckets);
	}

	void rehash() { // Doubling bucket size
		// Insert all entries one-by-one to new bucket
		mapNode<V>** oldBucket = buckets;
		buckets = new mapNode<V>*[2*numBuckets];
		for(int i=0; i<(2*numBuckets); i++) {
			buckets[i] = NULL;
		}
		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;
		for(int i=0; i<oldBucketCount; i++) {
			mapNode<V>* head = oldBucket[i];
			while(head != NULL) {
				// count++; .. don't increase count
				// it will automatically be increased in insert()
				string key = head->key;
				V value = head->value;
				insert(key, value);
				// Inserts into new bucket .. as bucket is pointing to new bucket
				head = head->next;
			}
		}
		for(int i=0; i<oldBucketCount; i++) {
			mapNode<V>* head = oldBucket[i];
			delete head;
		}
		delete []oldBucket;
		return;
	}

public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new mapNode<V>* [numBuckets];
		// Now garbage addresses are stored in above (array of pointers)
		for(int i=0; i<numBuckets; i++) {
			buckets[i] = NULL; // to avoid garbage addresses
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

	double getLoadFactor() {
		double ans = (double)(count) / (double)(numBuckets);
		return ans;
	}

	void insert(string key, V value) {
		// Get hash-value .. from hash-function
		// Get bucket-index .. by compression of hash-value
		int bucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[bucketIndex];
		while(head != NULL) {
			if(head->key == key) {
				// Key already present
				head->value = value;
				// Just update value & return
				return;
			}
			head = head->next;
		}
		// Not present .. need to insert key
		head = buckets[bucketIndex];
		mapNode<V>* newNode = new mapNode<V>(key, value);
		newNode->next = head; // Adding at head .. O(1)
		buckets[bucketIndex] = newNode; // Change the head in array
		count++; // 1-more entry now (as key was not present)
		double loadFactor = (double)(count) / (double)(numBuckets);
		if(loadFactor > 0.7) {
			rehash();
		}
		return;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[bucketIndex];
		mapNode<V>* temp = head;
		while(temp != NULL) {
			if(temp->key == key) {
				return temp->value;
			}
			temp = temp->next;
		}
		// Key not present .. return 0 (to symbol)
		cout << "Key not present" << endl;
		return 0; // 0 will adapt according to template type V.
	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[bucketIndex];
		mapNode<V>* temp = head;
		// The check, that will be missed by following loop is
		// .. when key was present at head
		if(head!=NULL && head->key == key) {
			count--; // 1 entry removed
			mapNode<V>* targetNode = head;
			buckets[bucketIndex] = head->next;
			V ans = targetNode->value;
			targetNode->next = NULL; // Avoid whole list deletion
			delete targetNode; // ..As destructor written recursively
			return ans;
		}
		while(temp!=NULL && temp->next!=NULL) {
			if(temp->next->key == key) {
				mapNode<V>* targetNode = temp->next;
				temp->next = temp->next->next;
				V ans = targetNode->value;
				targetNode->next = NULL; // Destructor written recursively
				delete targetNode;
				count--; // 1-entry deleted
				return ans;
			}
			temp = temp->next;
		}
		// If reached till here.. means key not found
		cout << "Key not found" << endl;
		return 0;
	}
};

int main() {
	ourmap<int> map;
	for(int i=0; i<10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		int value = (i+1);
		map.insert(key, value);
		// Below line will show rehashing is happening
		cout << map.getLoadFactor() << endl;
	}

	cout << map.size() << endl;
	map.remove("abc2");
	map.remove("abc7");

	for(int i=0; i<10; i++) {
		char c = '0' + i;
		string key = "abc";
		key += c;
		cout << key << " " << map.getValue(key) << endl;
	}
	cout << map.size() << endl;
	return 0;
}