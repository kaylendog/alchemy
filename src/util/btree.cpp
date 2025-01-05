#include <util/btree.hpp>

template <typename K, typename V> BTree<K, V>::BTree(int order) {
	this->order = order;
	// alloc
	this->keys = new K[order - 1];
	this->values = new V[order - 1];
	this->children = new BTree<K, V> *[order];
}

template <typename K, typename V> BTree<K, V>::~BTree() {
	// dealloc
	delete[] this->keys;
	delete[] this->values;
	delete[] this->children;
}

template <typename K, typename V> void BTree<K, V>::insert(K key, V value) {
	// for each key
	for (int i = 0; i < this->order - 1; i++) {
		if (this->keys[i] <= key) {
			this->values[i] = value;
			return;
		}
	}
}
