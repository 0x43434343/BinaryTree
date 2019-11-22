# BinaryTree

You are to create a program to implement a binary search tree using a linked list.  The structure of the linked list will have a node to store the number, a left link, right link and a previous link.  The structure that you MUST use is a follows:

```c++
struct tree_node
	{
		int number;
		tree_node *left;
		tree_node *right;
		tree_node *prev;
	};

```



Each section of the menu will run according to the following specifications:

- Insert numbers in the tree until the user types a negative number. Additionally, as you move through the tree to find the place to insert the number, print the number at the node you pass through and it’s position in the tree (left, right etc…)

- Delete a number from the tree.  Additionally, you will print each number at each node that is passed through as you search for the number.  You will also print all information concerning the position of the node, (left or right of the parent, if it has children, what number took it’s place etc …)  If it had 2 children, you must also search for the number that you will replace it with along with the numbers and their positions in the tree as you passed through them to find the proper number to replace the deleted one.

- Search for the number in the tree. Additionally, you will print each number at each node that is passed through as you search along with all information concerning the position of the node, (left or right of the parent).   If the number is not in the tree, print a message, saying it is not found.

- Print the (partial) tree in order
  - Print the root and the left main trunk of the tree
  - Print the root and the right main trunk of the tree

