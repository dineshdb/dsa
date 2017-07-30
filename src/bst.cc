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
			cout << node -> data << "\t";
			_traversePreOrder(node->left);
			_traversePreOrder(node->right);
		}
	}

	void _traverseInOrder(Node<T> *node = nullptr){
		if(node != nullptr){
			_traverseInOrder(node->left);
			cout << node -> data << "\t";
			_traverseInOrder(node->right);
		}
	}

	void _traversePostOrder(Node<T> *node = nullptr){
		if(node != nullptr){
			_traversePostOrder(node->left);
			_traversePostOrder(node->right);
			cout << node -> data << "\t";
		}
	}

	Node<T>* _find(T key, Node<T>* root){
		if(root = nullptr)
			throw NotFound();

		return root->data == key ? root :root->data < key ? _find(key,root->right) : _find(key,root->left);
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

	void insert(T d1, T d2)
	{
	    insert(d1);
	    insert(d2);
	}

	void insert(T d1, T d2, T d3)
	{
	    insert(d1);
	    insert(d2);
	    insert(d3);
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
    	return _find(key,node == nullptr ? root : node);
    }
    Node<T>* maxNode(Node<T>* root = nullptr){
        if(root == nullptr)
            root = this->root;
        if (this->isEmpty()){
			throw NotFound();
        }

        for (; root->right != nullptr; root = root->right);
        return root;
    }
    Node<T>* minNode(Node<T>* root = nullptr){
        if(root == nullptr)
            root = this->root;
        if (this->isEmpty()){
			throw NotFound();
        }
        for (; root->left != nullptr; root = root->left);
        return root;
    }
    Node<T>* _deleteNode(Node<T>* root, T key)
    {
        if(root==nullptr) return root;
        if (key < root->data)
            root->left = _deleteNode(root->left, key);
        else if (key > root->data)
            root->right = _deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            Node<T>* temp = minNode(root->right);
            root->data = temp->data;
            root->right = _deleteNode(root->right, temp->data);
        }
        return root;
    }
    Node<T>* deleteNode(T key, Node<T>* root = nullptr)
    {
        if(root == nullptr) {
            root = this->root;
            if (root == nullptr)
                return root;
        }
        _deleteNode(root, key);
    }
};

int main(){
	BST<int> t;
	t.insert(10, 5, 15);
	t.insert(20, 25);
	t.insert(25);
	t.traverseInOrder();
	cout<<endl<<endl;
	cout<<t.height()<<endl<<endl;
	t.deleteNode(15);
	t.traversePreOrder();
	cout<<endl<<endl;
	cout<<t.maxNode()->data<<endl<<endl;
	cout<<t.minNode()->data<<endl<<endl;
	t.traversePostOrder();
	return 0;

	//cout << t.minNode()->data << endl;
}
