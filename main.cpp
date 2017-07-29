// dynamic implementation of a simple binary tree
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
};

class Tree {
private:
    Node* root;

public:
    Node* insert(int data, Node* root){
        if (root == nullptr){
            return makeNode(data);
        } else {
            if (root->data > data){
                root->left = insert(data, root->left);
            } else {
                root->right = insert(data, root->right);
            }
        }
        return root;
    }

    void display(Node* root){
        // uses inorder traversal
        Node *now = root;
        if (now == nullptr){
            return;
        }
        stack<Node*> nodes;
        while (!nodes.empty() || now != nullptr){
            if (now != nullptr){
                nodes.push(now);
                now = now->left;
            } else {
                now = nodes.top();
                nodes.pop();
                cout << now->data << " ";
                now = now->right;
            }
        }
        cout << endl;
    }

    void morrisInorder(Node* root){
        Node *current = root;
        while (current != nullptr){
            if (current->left == nullptr){
                cout << current->data << " ";
                current = current->right;
            } else {
                Node *inorderPredecessor = current->left;
                for(;inorderPredecessor->right != nullptr && inorderPredecessor->right != current;
                    inorderPredecessor = inorderPredecessor->right){}

                if (inorderPredecessor->right == nullptr){
                    inorderPredecessor->right = current;
                    current = current->left;
                } else {
                    inorderPredecessor->right = nullptr;
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }
        cout << endl;
    }

    Node* search(Node* root, int key){

        /*
         * TODO
         * implement an iterative method for it
         *
         */

        if (root == nullptr){
            cout << "element not found in tree " << endl;
            exit(1);
        }
        if (root->data == key){
            return root;
        } else {
            if (root->data < key){
                return search(root->right, key);
            } else {
                return search(root->left, key);
            }
        }
    }

    void deleteNode(Node* tree, int key){
        if (tree == nullptr){
            cout << "Empty tree : cannot delete" << endl;
            return;
        }

        Node *parent = tree, *top = tree;
        while (top != nullptr){
            if (top->data == key){
                break;
            }
            parent = top;
            if (top->data > key){
                top = top->left;
            } else {
                top = top->right;
            }
        }

        if (top == nullptr){
            cout << "No matching element found " << endl;
            return;
        }

        cout << "top data " << top->data << endl;
        cout << "parent data " << parent->data << endl;

        if (top->left == nullptr && top->right == nullptr){
            if (parent->left == top){
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            cout << "I am at leaf node " << endl;
        } else if (top->left != nullptr && top->right == nullptr){
            if (parent->left == top){
                parent->left = top->left;
            } else {
                parent->right = top->left;
            }
            cout << "I have only a left child " << endl;
        } else if (top->right != nullptr && top->left == nullptr){
            if (parent->left == top){
                parent->left = top->right;
            } else {
                parent->right = top->right;
            }
            cout << "I have only a right child " << endl;
        } else {
            cout << "I have two child " << endl;
            Node *minRight = top->right, *parentMinRight = top->right;

            for (; minRight->left != nullptr; minRight = minRight->left){
                parentMinRight = minRight;
            }

            cout << "minRight data " << minRight->data << endl;
            cout << "parentMinRight data " << parentMinRight->data << endl;

            if (top->right == minRight){
                minRight->left = top->left;
            } else {
                parentMinRight->left = minRight->right;
                minRight->right = top->right;
                minRight->left = top->left;
            }
            if (top != tree)
                if (parent->left == top){
                    parent->left = minRight;
                } else {
                    parent->right = minRight;
                }
        }
        delete top;
    }


    int height(Node* root){
        /*
         * TODO
         * implement an iterative method for it
         *
         */

        if (root == nullptr){
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    Node* maxElement(Node* root){
        Node* current = root;
        if (current == nullptr){
            cout << " empty tree : no max found " << endl;
            exit(1);
        }

        if (current->left == nullptr && current->right == nullptr){
            return current;
        }

        for (; current->right != nullptr; current = current->right){}
        return current;
    }

    Node* minElement(Node* root){
        Node* current = root;
        if (current == nullptr){
            cout << " empty tree : no max found " << endl;
            exit(1);
        }

        if (current->left == nullptr && current->right == nullptr){
            return current;
        }

        for (; current->left != nullptr; current = current->left){}
        return current;
    }

    void breadthFristSearch(Node* root){
        if (root == nullptr){
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* top = q.front();
            cout << top->data << " ";
            q.pop();

            if (top->left != nullptr){
                q.push(top->left);
            }
            if (top->right != nullptr){
                q.push(top->right);
            }
        }
        cout << endl;
    }

    Node* makeNode(int key){
        Node* newNode = new Node();
        newNode->data = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
};

int main(){
    Tree t;
    Node* root = nullptr;
    //vector<int> a = {3, 5, 99, 34, 1, 4, 67, 47};
    vector<int> a = {8, 15, 6, 3, 12, 16, 2, 4, 18, 7};
    for (size_t i = 0; i < a.size(); i++){
        root = t.insert(a[i], root);
    }
    t.display(root);
    t.breadthFristSearch(root);
    t.morrisInorder(root);
    cout << "max: " << t.maxElement(root)->data << endl;
    //cout << "min: " << t.minElement(root) << endl;
    cout << "height: " << t.height(root) << endl;
    t.deleteNode(root, 8);
    t.display(root);
    cout << "Breadth first search: " << endl;
    t.breadthFristSearch(root);
    return 0;
}
