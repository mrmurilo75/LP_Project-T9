/*
 * Define types and respective functions
 */

#include <stddef.h>

#define byte char

#ifndef STRING_TYPE_INCLUDED
#define STRING_TYPE_INCLUDED

	typedef struct string_t* String;

	struct string_t {
		int length;
		int* value; // char[] equivalent
	};

	String new_String(int length, int* value);
		// create a new String object

	int String_compare(String a, String b);
		// compare String objects
		// return -1 if a < b
		// 	0 if equal
		// 	1 if a > b

	int String_equals(String a, String b);
		// return non-zero int if the value of the Strings *are* the same

#endif // STRING_TYPE_INCLUDED


#ifndef STRING_T9_TYPE_INCLUDED
#define STRING_T9_TYPE_INCLUDED

	typedef struct stringt9_t* StringT9;

	struct stringt9_t {
		int length;
		byte* value;
	};

        StringT9 new_StringT9(int length, byte* value);
		// create a new StringT9 object

	int StringT9_compare(StringT9 a, StringT9 b);
		// compare StringT9 objects
		// return -1 if a < b
		// 	0 if equal
		// 	1 if a > b

	int StringT9_equals(StringT9 a, StringT9 b);
		//returns non-zero if the value Strings *are* the same

#endif // STRING_T9_TYPE_INCLUDED


#ifndef BSTREEMAP_TYPE_INCLUDED
#define BSTREEMAP_TYPE_INCLUDED

	typedef struct bstmnode_t* BSTMNode;

	struct bstmnode_t {
		BSTMNode rightNode;
		BSTMNode leftNode;

		void* value;
	};

	BSTMNode new_BSTMNode();
		// create an empty node
		// (all values NULL)

	void* BSTMNode_getRightNode(BSTMNode node);
		// node: node in which to get the right node

	void* BSTMNode_setRightNode(BSTMNode node, BSTMNode right);
		// node: node in which to set the right node
		// right: node be set on the rightNode

	void* BSTMNode_getLeftNode(BSTMNode node);
		// node: node in which to get the left node

	void* BSTMNode_setLeftNode(BSTMNode node, BSTMNode left);
		// node: node in which to set the left node
		// left: node be set on the leftNode

	void* BSTMNode_getValue(BSTMNode node);
		// node: node from which to get the value

	void* BSTMNode_setValue(BSTMNode node, void* value);
		// node: node in which to set the value
		// value: value to set


	typedef struct bstreemap_t* BSTreeMap;

	struct bstreemap_t {
		BSTMNode root;
	};

        BSTreeMap new_BSTreeMap();
		// create a new empty BSTreeMap

        void* BSTreeMap_find(BSTreeMap tree, void* key);
		// tree: the tree to search in
		// key: the object to find
		// returns a void* to the value to which this object is mapped
		// returns NULL if theres no such object in tree

	void BSTreeMap_insert(BSTreeMap tree, void* key, void* value);
		// tree: the tree to insert in
		// key: the object to be mapped
		// value: the value to which the key will be mapped

	void BSTreeMap_remove(BSTreeMap tree, void* key);
		// tree: the tree to search in
		// key: the key of the mapping to be removed

#endif // BSTREEMAP_TYPE_INCLUDED


#ifndef HASHMAP_TYPE_INCLUDED
#define HASHMAP_TYPE_INCLUDED

	typedef void* HashMap; // implemented as an array (! use calloc)

	HashMap new_HashMap();
		// create an empty HashMap

	void* HashMap_get(HashMap map, void* key);
		// map: the map in which to search
		// key: the key to find 
		// returns a void* to the value mapped to this key

	void HashMap_insert(HashMap map, void* key, void* value);
		// map: the map in which to insert
		// key: the key to insert
		// value: the value to be mapped to the respect key

	void HashMap_remove(HashMap map, void* key);
		// map: the map in which to search
		// key: the key of value to remove the value

#endif // HASHMAP_TYPE_INCLUDED


#ifndef LINKEDLISTMAP_TYPE_INCLUDED
#define LINKEDLISTMAP_TYPE_INCLUDED

	typedef struct llmnode_t* LLMNode;

	struct llmnode_t {
		LLMNode next;
		LLMNode previous;

		void* value;
	};

	typedef struct linkedlistmap_t* LinkedListMap;

	struct linkedlistmap_t {
		LLMNode root;
	};

	LinkedListMap new_LinkedListMap();

	void LinkedListMap_sort(LinkedListMap list);
		// list: the LinkedList to be organized by key

        void* LinkedListMap_find(LinkedListMap list, void* key);
		// list: the list in which to search
		// key: the key to find
		// returns a void* to the value mapped by this key
		// or NULL if theres no such mapping


        void LinkedListMap_add(LinkedListMap list, void* key, void* value);
		// list: the list in which to add
		// key: the key to which the value will be mapped
		// value: the value of the mapping

        void* LinkedListMap_find(LinkedListMap list, void* key);
		// list: the list in which to search
		// key: the key to be removed

#endif // LINKEDLISTMAP_TYPE_INCLUDED

