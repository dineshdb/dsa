#include <iostream>
using namespace std;

class NotFound{};

template<class T>
class Node{
public:
T data;
Node<T> *left = nullptr, *right = nullptr;
	Node(T d) : data(d){}
	bool isLeafNode(){
		return left == nullptr && right == nullptr;
	}
};

template<class T>
class BST{

Node<T> *root = nullptr;
	int _height(Node<T> *node = nullptr){
		return node == nullptr ? 0 : max(_height(node->left), _height(node->right)) + 1;
	}
	void _traversePreOrder(Node<T> *node = nullptr){
		if(node != nullptr){
			cout << node -> data << endl;
			_traversePreOrder(node->left);
			_traversePreOrder(node->right);
		}
	}

	void _traverseInOrder(Node<T> *node = nullptr){
		if(node != nullptr){
			_traverseInOrder(node->left);
			cout << node -> data << endl;
			_traverseInOrder(node->right);
		}
	}

	void _traversePostOrder(Node<T> *node = nullptr){
		if(node != nullptr){
			_traversePostOrder(node->left);
			_traversePostOrder(node->right);
			cout << node -> data << endl;
		}
	}

	Node<T>* _find(T key, Node<T>* root = nullptr){
		if(root = nullptr)
			throw NotFound();

		return root->data == key ? root :root->data < key ? _find(root->right,key) : _find(root->left, key);
    }

public:
	void insert(T d, Node<T> **n = nullptr){
		// User didn't specify any node, let's assume it's the root.
		if(n == nullptr){
			n = &root;
		}

		if(*n == nullptr){
			*n =  new Node<T>(d);
		} else if( (*n) -> data > d){
			insert(d, &(*n)->left);
		} else {
			insert(d, &(*n)->right);
		}
	}

	bool isEmpty(){
		return root == nullptr;
	}

	Node<T> *getRoot(){
		return root;
	}
	int height(Node<T> *node = nullptr){
		return _height(node == nullptr ? root : node);
	}
	void traversePreOrder(Node<T> *node = nullptr){
		_traversePreOrder(node == nullptr ? root : node);
	}

	void traverseInOrder(Node<T> *node = nullptr){
		_traverseInOrder(node == nullptr ? root : node);
	}

	void traversePostOrder(Node<T> *node = nullptr){
		_traversePostOrder(node == nullptr ? root : node);
	}
	void deleteNode(){

	}
	void bfs(){

	}
    Node<T>* find(T key, Node<T>* node = nullptr){
    	return _find(node == nullptr ? root : node);
    }
    Node<T>* maxNode(Node<T>* root = nullptr){
    	// If no parameter is found, assume tree root as the root.
    	if (root == nullptr){
    		root = this->root;
    	}
        if (this->isEmpty()){
			throw NotFound();
        }

        for (; root->right != nullptr; root = root->right);
        return root;
    }
    Node<T>* minNode(Node<T>* root = nullptr){
    	// If no parameter is found, assume tree root as the root.
    	if (root == nullptr){
    		root = this->root;
    	}

        if (this->isEmpty()){
			throw NotFound();
        }

        for (; root->left != nullptr; root = root->left);
        return root;
    }
};

int main(){
	BST<int> t;
	t.insert(10);
	t.insert(5);
	t.insert(15);

	cout << t.minNode()->data << endl;
}
