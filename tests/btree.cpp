#include <alchemy/util/btree.hpp>

int main() {
	Alchemy::Util::BTree<int, int> tree(3);
	tree.insert(1, 2);
	return 0;
}
