int minValue(Node* root) {
   Node* current = root;

while (current->left != NULL)
{
    current = current->left;
}
return(current->data);
}