#include <unordered_map>
using namespace std;
struct Node {
	int key, value;
	Node* prev, * next;
	Node(int k = 0,int v = 0):key(k),value(v),prev(nullptr),next(nullptr){}
};
class LRUCache {
private:
	int capacity;
	unordered_map<int, Node*> cache;
	Node* head, * tail;
	void removeNode(Node* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void addToHead(Node* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
public:
	LRUCache(int capacity) :capacity(capacity) {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (cache.find(key) == cache.end()) return -1;
		Node* node = cache[key];
		removeNode(node);
		addToHead(node);
		return node->value;
	}
	void put(int key, int value) {
		if (cache.count(key)) {
			Node* node = cache[key];
			node->value = value;
			removeNode(node);
			addToHead(node);
		}
		else {
			if (cache.size() == capacity) {
				Node* last = tail->prev;
				cache.erase(last->key);
				removeNode(last);
				delete last;
			}
			Node* newNode = new Node(key, value);
			cache[key] = newNode;
			addToHead(newNode);
		}
	}
};