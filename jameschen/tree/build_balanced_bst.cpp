Create a balanced binary tree

Problem
Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

Solution
1. Insert into the tree the middle element of the array.
2. Insert (into the left subtree) the left subarray elements
3. Insert (into the right subtree) the right subarray elements
4. Recurse

void create_balanced_bin_tree(BTNode **root, int arr[], int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end + 1) / 2;

        *root = create_bin_tree_node(arr[mid]);   
        create_balanced_bin_tree(&((*root)->left), arr, start, mid - 1);
        create_balanced_bin_tree(&((*root)->right), arr, mid + 1, end);
    }
}
