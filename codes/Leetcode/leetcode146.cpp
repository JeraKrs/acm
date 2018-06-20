class LRUCache {
	private:
		class Node {
			public:
				Node(int key, int val): key(key), val(val), pre(NULL), nex(NULL) {}
				int key;
				int val;
				Node* pre;
				Node* nex;
		};

		Node* head;
		Node* tail;
		int capacity;
		int size;
		map<int, Node*> cached;

	public:
		LRUCache(int capacity) {
			this->size = 0;
			this->capacity = capacity;
			this->head = NULL;
			this->tail = NULL;
		}

		void moveToHead(Node* curr) {
			if (curr == head) return;

			Node* pre = curr->pre;
			Node* nex = curr->nex;

			if (pre != NULL) pre->nex = nex;
			if (nex != NULL) nex->pre = pre;

			if (tail == curr) tail = pre;
			head->pre = curr;
			curr->nex = head;
			curr->pre = NULL;
			head = curr;
		}

		int get(int key) {
			if (capacity == 0) return -1;

			if (cached.count(key)) {
				Node* temp = cached[key];
				moveToHead(temp);
				return temp->val;
			}
			return -1;
		}

		void put(int key, int value) {
			if (capacity == 0) return;

			if (cached.count(key)) {
				moveToHead(cached[key]);
				cached[key]->val = value;
				return;
			}

			Node* temp = new Node(key, value);
			temp->pre = NULL;
			temp->nex = head;

			if (head != NULL) head->pre = temp;
			head = temp;

			if (tail == NULL) tail = temp;

			cached[key] = temp;
			size++;

			if (size > capacity) {
				if (cached[tail->key] == tail)
					cached.erase(tail->key);
				Node* last = tail;
				tail = tail->pre;
				tail->nex = NULL;
				delete last;
				size--;
			}
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
