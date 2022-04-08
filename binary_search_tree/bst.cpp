#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;

    Node()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
    public:
    int rotLeft, rotRight, index;
    bool avl, direction;
    int *preOrder;
    Node *root, *parent;
    Tree()
    {
        rotLeft = 0, rotRight = 0, index = 0;
        avl = true;
        direction = true;
        root = nullptr;
        preOrder = nullptr;
        parent = new Node();
    }

    Node* insertNode(Node *root, int value)
    {
        if (root == nullptr)
        {
            Node *n = new Node(value);
            return n;
        }
        if (value < root->val)
        {
            root->left = insertNode(root->left, value);
            return root;
        }
        else
        {
            root->right = insertNode(root->right, value);
            return root;
        }        
    }

    Node* rotateLeft(Node *root)
    {
        Node *r = new Node();
        Node *rl = new Node();
        r = root->right;
        rl = r->left;
        r->left = root;
        root->right = rl;
        rotLeft++;
        return r;
    }

    Node* rotateRight(Node *root)
    {
        Node *l = new Node();
        Node *lr = new Node();
        l = root->left;
        lr = l->right;
        l->right = root;
        root->left = lr;
        rotRight++;
        return l;
    }

    void etapa1(Node *root)
    {
        if (root->right == nullptr && root->left == nullptr)
            return;
        
        if (root->right == nullptr)
        {
            parent = root;
            etapa1(root->left);
            this->root = root;
        }
        else
        {
            root = rotateLeft(root);
            parent->left = root;
            etapa1(root);
        }
    }

    void etapa2(Node* root)
    {
        if (root->val == preOrder[index])
        {
            index++;
            if (root->right == nullptr && root->left == nullptr)
                return;
            else
            {
                parent = root;
                direction = true;
                if (root->left != nullptr)
                    etapa2(root->left);
                direction = false;
                parent = root;
                if (root->right != nullptr)
                    etapa2(root->right);
                this->root = root;
            }
        }            
        else if (direction)
        {
            root = rotateRight(root);
            parent->left = root;
            etapa2(root);
        }
        else
        {
            root = rotateLeft(root);
            parent->right = root;
            etapa2(root);
        }
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        if (root->val == preOrder[0])
            cout << root->val;
        else
            cout << root->val << " ";
    }

    int AVL(Node *root)
    {
        int hLeft, hRight, bf;
        if (root == nullptr)
            return 0;
        hLeft = AVL(root->left);
        hRight = AVL(root->right);
        bf = abs(hRight - hLeft);
        if (bf>1)
            avl = false;
        
        return 1 + max(hLeft, hRight);
        
    }
};

int main()
{
    int nodes, value, i;

    while (cin >> nodes)
    {
        Tree *tree = new Tree();
        for (i = 0; i < nodes; i++)
        {
            cin >> value;
            tree->root = tree->insertNode(tree->root, value);
        }
        tree->preOrder = (int*) realloc(tree->preOrder, nodes * sizeof(int));
        for (i = 0; i < nodes; i++)
            cin >> tree->preOrder[i];

        
        tree->parent->left = tree->root;
        tree->etapa1(tree->root);
        Node *temp = new Node();
        tree->parent = temp;
        tree->etapa2(tree->root);

        cout << tree->rotLeft << " " << tree->rotRight << endl;

        //Printar a árvore em pós-ordem
        tree->postOrder(tree->root);
        cout << endl;

        //Checar se é AVL e retornar bool (printar "true" ou "false")
        tree->AVL(tree->root);
        if (tree->avl)
            cout << "true" << endl << endl;
        else        
        cout << "false" << endl << endl;

        free(tree->preOrder);
        delete tree->parent;
        delete tree;
        delete temp;
    }
    return 0;
}