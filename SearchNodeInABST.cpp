bool search(Node* root, int x) {
    if (root == NULL)
        return false;
 
    if (root->data == x)
        return true;
    bool res1 = search(root->left, x);
    if(res1) return true;
 
    bool res2 = search(root->right, x);
    return res2;
}