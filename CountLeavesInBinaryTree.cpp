int countLeaves(Node* root)
{
    int noOfLeaves=0;
    if(root==NULL) return 0;
    if(root->left ==NULL && root->right==NULL) return 1;
    return countLeaves(root->left)+countLeaves(root->right);
}