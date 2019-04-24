#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode{
    int val;
    struct BSTNode* left;
    struct BSTNode* right;
}bsn;

bsn* createNode(int x)
{
    bsn* t = (bsn*)malloc(sizeof(bsn));
    t->val = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}   

bsn* insert(bsn* root, int src, int child)
{
    if(!root)
        return NULL;
    
    if(root->val == src)
    {
        if(child < src)
            root->left = createNode(child);
        else
            root->right = createNode(child);
    }

    insert(root->left, src, child);
    insert(root->right, src, child);

    return root;
}

void inorder(bsn* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

bsn* removeRange(bsn* root, int low, int high)
{
    if(!root)
        return NULL;

    root->left = removeRange(root->left, low, high);
    root->right = removeRange(root->right, low, high);

    if(root->val < low)
    {
        bsn* rch = root->right;
        free(root);
        return rch;
    } 

    if(root->val > high)
    {
        bsn* lch = root->left;
        free(root);
        return lch;
    }

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    int table[n][2];

    for(int i=0;i<n-1;i++)
        scanf("%d %d", &table[i][0], &table[i][1]);
    
    int r;
    scanf("%d", &r);
    bsn* root = createNode(r);

    int low, high;
    scanf("%d %d", &low, &high);

    for(int i=0;i<n-1;i++)
        root = insert(root, table[i][0], table[i][1]);

    root = removeRange(root, low, high);

    inorder(root);
}