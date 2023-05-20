//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val, bf, height;
    struct Node *left, *right;
};

struct Node *createNewNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->height = 1;
    newNode->bf = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// utitly for insert
int getHeight(struct Node *root)
{
    return (root) ? root->height : 0;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int setHeight(struct Node *root)
{
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int setBalanceFactor(struct Node *root)
{
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

// utility for rotation

struct Node *update(struct Node *root)
{
    root->height = setHeight(root);
    root->bf = setBalanceFactor(root);
    return root;
}

struct Node *leftRotate(struct Node *root)
{
    struct Node *pivot = root->right;
    struct Node *child = root->left;
    pivot->left = root;
    root->right = child;
    root = update(root);
    pivot = update(pivot);
    return pivot;
}

struct Node *rightRotate(struct Node *root)
{
    struct Node *pivot = root->left;
    struct Node *child = root->right;
    pivot->right = root;
    root->left = child;
    root = update(root);
    pivot = update(pivot);
    return pivot;
}

struct Node *rotation(struct Node *root)
{
    if (!root)
    {
        return root;
    }
    else if (root->bf < -1 && root->right->bf <= 0)
    { // rotate left
        return leftRotate(root);
    }
    else if (root->bf > 1 && root->left->bf >= 0)
    { // rotate right
        return rightRotate(root);
    }
    else if (root->bf > 1 && root->left->bf < 0)
    { // rotate left right
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    else if (root->bf < -1 && root->right->bf > 0)
    { // rotate right left
        root->right = rightRotate(root);
        return leftRotate(root);
    }
    return root;
}

struct Node *insert(struct Node *root, int val)
{
    if (!root)
        return createNewNode(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return rotation(update(root));
}

void inOrder(struct Node *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("Value : %d\nBF : %d\nHeight : %d\n\n", root->val, root->bf, root->height);
        inOrder(root->right);
    }
}

// left side once then go to the right all the way
Node *get_predecessor(Node *root)
{
    Node *curr = root->left;
    while (curr && curr->right)
    {
        curr = curr->right;
    }
    return curr;
}
// right once, then left
Node *get_successor(Node *root)
{
    Node *curr = root->right;
    while (curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

Node *Delete(int value, Node *root)
{
    if (root == NULL)
    {
        printf("Product not found\n");
        return NULL;
    }
    else if (root->val < value)
    {
        root->right = Delete(value, root->right);
    }
    else if (root->val > value)
    {
        root->left = Delete(value, root->right);
    }
    else
    {
        // have 1 child / no child
        if (root->right == NULL || root->left == NULL)
        {
            Node *temp = NULL;
            if (root->left)
            {
                temp = root->left;
            }
            else if (root->right)
            {
                temp = root->right;
            }
            free(root);
            root = temp;

            if (root == NULL)
            {
                return NULL;
            }
        }
        else
        {
            Node *candidate = get_predecessor(root);
            // overwrite the value
            root->val = candidate->val;
            // delete
            root->left = Delete(candidate->val, root->left);
        }
    }
    return rotation(update(root));
}

//Update The vlaue of the Tree
Node* update(Node* root, int oldValue, int newValue){
    root = Delete(oldValue, root);
    root = insert(root, newValue);
    
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 7);
    inOrder(root);
    puts("--------------");
    root = insert(root, 6);
    inOrder(root);
    // puts("--------------");
    // root = insert(root, 9);
    // inOrder(root);
    printf("\n Delete \n");
    root = Delete(7, root);
    inOrder(root);
    return 0;
}