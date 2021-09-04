long int sumBT(Node* root)
{
    Node* head =root;
    long int res=0;
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return res+=root->key;
    return sumBT(root->left)+sumBT(root->right)+head->key;
}