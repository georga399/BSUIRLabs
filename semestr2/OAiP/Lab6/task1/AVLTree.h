#pragma once
#include <memory>
#include <string>

class AVLTree
{
public:
    struct Node
    {
        friend AVLTree;
    private:
        int key;
        int height = 0;
    public:
        Node(){}
        Node(int nKey, std::string nValue): 
            key(nKey), value(nValue){}    
        int GetKey() {return key;}        
        std::shared_ptr<Node> left, right;
        std::string value;

    };
    std::shared_ptr<Node> root;
protected:
    int getHeight(std::shared_ptr<Node> node)
    {
        if (!node)
        return 0;
        return node->height;
    }
    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> node) 
    {
        std::shared_ptr<Node> x = node->left;
        std::shared_ptr<Node> T2 = x->right;

        // Perform rotation 
        x->right = node;
        node->left = T2;

        // Update heights 
        node->height = std::max(getHeight(node->left),
            getHeight(node->right)) + 1;
        x->height = std::max(getHeight(x->left),
            getHeight(x->right)) + 1;
        // Return new root 
        return x;
    }
    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> node)
    {
        std::shared_ptr<Node> y = node->right;
        std::shared_ptr<Node> T2 = y->left;

        // Perform rotation 
        y->left = node;
        node->right = T2;

        // Update heights 
        node->height = std::max(getHeight(node->left),
            getHeight(node->right)) + 1;
        y->height = std::max(getHeight(y->left),
            getHeight(y->right)) + 1;

        // Return new root 
        return y;
    }
    int getBalance(std::shared_ptr<Node> node)
    {
        if (!node)
            return 0;
        return getHeight(node->left) -
            getHeight(node->right);
    }
    // Вставка
    std::shared_ptr< Node> insert(std::shared_ptr<Node> node, int key, std::string value)
    {
        if (!node)
            return(std::shared_ptr<Node>(new Node(key, value)));
        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else 
            return node;
            // node->value = value;

        node->height = 1 + std::max(getHeight(node->left),
            getHeight(node->right));
        return _balance_tree(node);
    }
    std::shared_ptr< Node> deleteNode(std::shared_ptr<Node> root, int key)
    {
        if (!root)
            return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((!root->left) ||
                (!root->right))
            {
                std::shared_ptr<Node> temp = root->left ?
                    root->left :
                    root->right;
                if (!temp)
                {
                    temp = root;
                    root = std::shared_ptr<Node>();
                }
                else // One child case 
                    *root = *temp; // Copy the contents of 
                // the non-empty child 
            }
            else
            {
                std::shared_ptr<Node> temp = minValueNode(root->right);

                // Copy the inorder successor's 
                // data to this node 
                root->key = temp->key;

                // Delete the inorder successor 
                root->right = deleteNode(root->right,
                    temp->key);
            }
        }

        // If the tree had only one node
        // then return 
        if (!root)
            return root;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
        root->height = 1 + std::max(getHeight(root->left),
            getHeight(root->right));
        //STEP 3: BALANCE 
        return _balance_tree(root);
    }
    std::shared_ptr<Node> minValueNode(std::shared_ptr<Node> node)
    {
        std::shared_ptr<Node> current = node;
        while (current->left)
            current = current->left;

        return current;
    }
    //tree traversals
    void _pref_foreach(std::shared_ptr<Node> node, void (*foo)(const int key, std::string& val))
    {
        if(!node) return;
        foo(node->key, node->value);
        _pref_foreach(node->left, foo);
        _pref_foreach(node->right, foo);
    }
    void _infix_foreach(std::shared_ptr<Node> node, void (*foo)(const int key, std::string& val))
    {  
        if(!node) return;
        _infix_foreach(node->left, foo);
        foo(node->key, node->value);
        _infix_foreach(node->right, foo); 
    }
    void _postfix_foreach(std::shared_ptr<Node> node, void (*foo)(const int key, std::string& val))
    {
        if(!node) return;
        _postfix_foreach(node->left, foo);
        _postfix_foreach(node->right, foo); 
        foo(node->key, node->value);

    }
    std::shared_ptr<Node> _balance_tree(std::shared_ptr<Node> node)
    {
        if(!node) return node;
        int balance = getBalance(node);
        if (balance >= 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        if (balance >= 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance <= -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        if (balance <= -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
public:
    AVLTree(){};
    void insert(int key, std::string val)
    {
        root = insert(root, key, val);
    }
    void remove(int key)
    {
        root = deleteNode(root, key);
    }
    std::shared_ptr<Node> find(int key)
    {
        std::shared_ptr<Node> node = root;
        while (true)
        {
            if(node == nullptr) return node;
            if(node->key > key) node = node->left;
            else if(node->key < key) node = node->right;
            else return node;
        }
        
    }
    void prefix_foreach(void (*foo)(const int key, std::string& val))
    {
        _pref_foreach(root, foo);
    }
    void infix_foreach(void (*foo)(const int key, std::string& val))
    {
        _infix_foreach(root, foo);
    }
    void postfix_foreach(void (*foo)(const int key, std::string& val))
    {
        _postfix_foreach(root, foo);
    }
    void balance_tree()
    {
        _balance_tree(root);
    }
};
