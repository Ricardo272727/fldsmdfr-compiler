#include <stdio.h>
#include <stdlib.h>

#define type int

typedef struct Node * pNode;
struct Node{
    type data;
    pNode left;
    pNode right;
};

typedef struct Tree * pTree;
struct Tree{
    pNode root;
    int n;
};

pNode new_node(type data){
    pNode node = (pNode)malloc(sizeof(struct Node));
    node->right = NULL;
    node->left = NULL;
    node->data = data;
    return node;
}

pTree new_tree(){
    pTree tree = (pTree)malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

void _insert_in_tree_(pNode root, type data){
    if(root->data < data){
        if(root->right == NULL){
            pNode node = new_node(data);
            root->right = node;
        } else {
            _insert_in_tree_(root->right, data);
        }
    } else {
        if(root->left == NULL){
            pNode node = new_node(data);
            root->left = node;
        } else {
            _insert_in_tree_(root->left, data);
        }
    }
}

void insert_in_tree(pTree tree, type data)
{   
    if(tree->root == NULL) {
        tree->root = new_node(data);
    } else{
        _insert_in_tree_(tree->root, data);
    }
}


void _show_tree_(pNode root){
    if(root != NULL){
        printf(" %d", root->data);
        _show_tree_(root->left);
        _show_tree_(root->right);
    }
}

void show_tree(pTree tree){
    if(tree->root == NULL)
        printf("\nTree is empty");
    else 
        _show_tree_(tree->root);
}