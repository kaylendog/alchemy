#include <functional>
#include <optional>

const int BTREE_DEFAULT_ORDER = 4;
const int BTREE_DEFAULT_ITEMS = BTREE_DEFAULT_ORDER - 1;

namespace Alchemy {

namespace Util {

template <typename K, typename V> class BTree {
  public:
	BTree(int order = BTREE_DEFAULT_ORDER);
	~BTree();

	/// @brief Inserts a key-value pair into the BTree.
	/// @param key The key to insert.
	/// @param value The value to insert.
	void insert(K key, V value);

	/// @brief Removes a key-value pair from the BTree.
	/// @param key The key to remove.
	void remove(K key);

	/// @brief Gets the value associated with the given key.
	/// @param key The key to search for.
	/// @return The value associated with the key.
	std::optional<V> get(K key);

	/// @brief Gets the value associated with the given key, or returns the default value if the key is not found.
	/// @param key The key to search for.
	/// @param default_value The value to return if the key is not found.
	/// @return The value associated with the key, or the default value.
	V get_or(K key, V default_value);

	/// @brief Gets the value associated with the given key, or returns the result of the given function if the key is
	/// not found.
	/// @param key The key to search for.
	/// @param f The function to call if the key is not found.
	/// @return The value associated with the key, or the result of the function.
	V get_or_else(K key, std::function<V(K)> f);

  private:
	int order;
	K *keys;
	V *values;
	BTree<K, V> *children;
};

} // namespace Util
} // namespace Alchemy
