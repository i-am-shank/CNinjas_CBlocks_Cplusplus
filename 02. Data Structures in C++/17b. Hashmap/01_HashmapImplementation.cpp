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
	ourmap<int> myMap;
	myMap.insert("abc", 2);
	myMap.insert("def", 4);
	myMap.insert("ghi", 7);
	int ans1 = myMap.getValue("def");
	myMap.insert("ghi", 6);
	int ans2 = myMap.size();
	myMap.remove("klm");
	int ans3 = myMap.size();
	myMap.remove("def");
	int ans4 = myMap.size();
	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
	return 0;
}