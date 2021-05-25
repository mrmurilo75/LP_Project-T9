/*
 * Define types and respective functions
 */

#include <stddef.h>
#include <stdio.h>

#define byte char

#ifndef INTEGER_TYPE_INCLUDED
#define INTEGER_TYPE_INCLUDED
	typedef int* Integer;

	Integer new_Integer();
		// new Integer with undefined value

#endif // INTEGER_TYPE_INCLUDED


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
	
	void* String_toStringT9(String value);		//
		// value: the string to be transforme into t9
		// returns the corresponding StringT9
		// 	or NULL if theres is no equivalent (ex. if contains special characters)

#endif // STRING_TYPE_INCLUDED		--


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

	int StringT9_getIntHead(StringT9 a);		//
		// a: the string to get the head from
		// return an int correspondig to the first 5 elements
		//	or 0 if it has no head (length <= 5)

#endif // STRING_T9_TYPE_INCLUDED		--


#ifndef BSTREEMAP_TYPE_INCLUDED
#define BSTREEMAP_TYPE_INCLUDED

	typedef struct bstmnode_t* BSTMNode;

	struct bstmnode_t {
		BSTMNode rightNode;
		BSTMNode leftNode;


		void* key;
		void* value;
	};

	BSTMNode new_BSTMNode(void* key, void* value);
		// key: the key to be associated with this node
		// value: value to which the key will be mapped
		// (all other values NULL)

	void* BSTMNode_getRightNode(BSTMNode node);
		// node: node in which to get the right node

	void BSTMNode_setRightNode(BSTMNode node, BSTMNode right);
		// node: node in which to set the right node
		// right: node be set on the rightNode

	void* BSTMNode_getLeftNode(BSTMNode node);
		// node: node in which to get the left node

	void BSTMNode_setLeftNode(BSTMNode node, BSTMNode left);
		// node: node in which to set the left node
		// left: node be set on the leftNode

	void* BSTMNode_getValue(BSTMNode node);
		// node: node from which to get the value

	void BSTMNode_setValue(BSTMNode node, void* value);
		// node: node in which to set the value
		// value: value to set

	void* BSTMNode_getKey(BSTMNode node);
		// node: node from which to get the key

	int BSTMNode_compareKey(BSTMNode node, void* key);
		// node: node with which to compare
		// key: the key to compare
		// return -1 if given key is sorted to the left
		// 	0 if the node's key is equal to the given key
		//	1 if the given key is sorted to the left


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

	void BSTreeMap_insert(BSTreeMap tree, void* key, void* value); 		// DOING (murilo)
		// tree: the tree to insert in
		// key: the object to be mapped
		// value: the value to which the key will be mapped

	void* BSTreeMap_remove(BSTreeMap tree, void* key);		// TO/DO (if necessary)
		// tree: the tree to search in
		// key: the key of the mapping to be removed
		// returns the value removed

#endif // BSTREEMAP_TYPE_INCLUDED		--DONE


#ifndef HASHMAP_TYPE_INCLUDED
#define HASHMAP_TYPE_INCLUDED

	typedef void* HashMap; // implemented as an array (! use calloc)

	HashMap new_HashMap();		// TODO
		// create an empty HashMap

	void* HashMap_get(HashMap map, void* key);		// TODO
		// map: the map in which to search
		// key: the key to find 
		// returns a void* to the value mapped to this key

	void HashMap_insert(HashMap map, void* key, void* value);		// TODO
		// map: the map in which to insert
		// key: the key to insert
		// value: the value to be mapped to the respect key

	void HashMap_remove(HashMap map, void* key);		// TODO
		// map: the map in which to search
		// key: the key of value to remove the value

#endif // HASHMAP_TYPE_INCLUDED		--TODO


#ifndef LINKEDLISTMAP_TYPE_INCLUDED
#define LINKEDLISTMAP_TYPE_INCLUDED

	typedef struct llmnode_t* LLMNode;

	struct llmnode_t {
		LLMNode next;
		LLMNode previous;

		void* key;
		void* value;
	};

	LLMNode new_LLMNode();
		// create LLMNode
		// ALL VALUES == NULL

	void LLMNode_setNext(LLMNode this, LLMNode next);
		// this: node to set the next
		// next: node to set as next

	void LLMNode_setPrevious(LLMNode this, LLMNode previous);
		// this: node to set the previous
		// previous: node to set as previous

	void LLMNode_setKey(LLMNode this, void* key);
		// this: node to set the value
		// key: value to set as key

	void LLMNode_setValue(LLMNode this, void* value);
		// this: node to set the value
		// value: value to set as value

	LLMNode LLMNode_getNext(LLMNode this);
		// this: node from which to get the next

	LLMNode LLMNode_getPrevious(LLMNode this);
		// this: node from which to get the previous

	void* LLMNode_getValue(LLMNode this);
		// this: node from which to get the value

	void* LLMNode_getKey(LLMNode this);
		// this: node to set the value

	typedef struct linkedlistmap_t* LinkedListMap;

	struct linkedlistmap_t {
		LLMNode root;
	};

	LinkedListMap new_LinkedListMap();

	void LinkedListMap_setRoot(LinkedListMap list, LLMNode node);
		//list : the LinkedList to be set
		//node : node to set as root

	LLMNode LinkedListMap_getRoot(LinkedListMap list);
		//list : the LinkedList to get the root from

	void LinkedListMap_sort(LinkedListMap list);		// TO/DO (if necessary)
		// list: the LinkedList to be organized by key

        void* LinkedListMap_find(LinkedListMap list, void* key);
		// list: the list in which to search
		// key: the key to find
		// returns a void* to the value mapped by this key
		// or NULL if theres no such mapping

        void LinkedListMap_add(LinkedListMap list, void* key, void* value);		// TODO
		// list: the list in which to add
		// key: the key to which the value will be mapped
		// value: the value of the mapping

        void* LinkedListMap_remove(LinkedListMap list, void* key);		// TO/DO (if necessary)
		// list: the list in which to search
		// key: the key to be removed

        LLMNode LinkedListMap_getNodeByValue(LinkedListMap list, void* value);		// TODO NEW
		// list: the list in which to search
		// value: the value to find
		// returns a LLMNode that contains the value mapping
		// 	or NULL if theres no such mapping

	void LinkedListMap_updateNode(LinkedListMap list, LLMNode node);		// TODO NEW
		// list: the list in which to update
		// node: the node to be updated
		// the node should be updated by moving concating getNext/getPrevious
		// 	and if necessary reset the list root

#endif // LINKEDLISTMAP_TYPE_INCLUDED		--

#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

	struct dictionary_t {
		HashMap bigWords;	// HashMap of StringT9[head] -> (BSTreeMap of StringT9 -> (LinkedListMap of words) )
				// :maps the head of a StringT9 (the first 5 elements) to a BSTreeMap that contains the LinkedListMap of correspondig the words

		BSTreeMap smallWords;	// BSTreeMap of StringT9 -> (LinkedListMap of words)
				// skips the hashmap
	};

	typedef struct dictionary_t* Dictionary;

	Dictionary new_Dictionary();
		//create a new empty Dicitionary

	LinkedListMap Dictionary_find(Dictionary dict, StringT9 value);
		// dict: the dictionary to search in
		// value: the stringT9 to be found
		// returns the LinkedListMap corresponding to this stringT9

	void Dictionary_insert(Dictionary dict, String value);
		// dict: the dictionary to insert in
		// value: the string to be inserted (if there is no mapping, or upcount otherwise)

	Dictionary Dictionary_fillFromFile(FILE* file);		// NEW
		// file: text file to read from
		// return a filled new Dictionary
		// 	or NULL if file is NULL
#endif	// DICTIONARY_H_INCLUDED		--DONE

