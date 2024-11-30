
#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char name[30];
    int num;
    float mark;
}Data;

typedef struct node{

    Data data;
    struct node* left, *right;
}Node;

int insert_node(Node**, Data*);
void preorder(const Node*);
Node* search(Node*, int);
int delete_node(Node**, int);

int main() {

    Node* root = NULL;
    Data* buffer = (Data*)malloc(sizeof(Data));
    if(!buffer)
        return -1;
    
    char ans = 'Y';
    do{
        
        printf("Enter name: ");
        scanf(" %[^\n]s", buffer->name);
        printf("Enter num: ");
        scanf(" %d", &buffer->num);
        printf("Enter mark: ");
        scanf(" %f", &buffer->mark);

        insert_node(&root, buffer);
        printf("Do you want to add an element to binary search tree Y/N ? ");
        scanf(" %c", &ans);
    }while(ans == 'Y');

    printf("\n");
    preorder(root);

    Node* found = search(root, 1);
    if(found)
        printf("Number 1 name: %s\n", found->data.name);
    
    printf("delete_node(&root, 8) returned: %d\n", delete_node(&root, 8));

    printf("\n");
    preorder(root);

    return 0;
}

// data->num - unique key
int insert_node(Node** root, Data* data) {

    if((*root) == NULL){

        *root = (Node*)malloc(sizeof(struct node));
        (*root)->data = *data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 0;
    }
    else{

        if((*root)->data.num > data->num)
            return insert_node(&(*root)->left, data);
        else if((*root)->data.num < data->num)
            return insert_node(&(*root)->right, data);
        else 
            return -1;
    }
}

void preorder(const Node* root) {

    if(root){

        printf("Name: %s\n", root->data.name);
        printf("Num: %d\n", root->data.num);
        printf("Mark: %.2f\n", root->data.mark);
        printf("\n");
        preorder(root->left);
        preorder(root->right);
    }
}

Node* search(Node* root, int number) {

    if(root == NULL)
        return NULL;
    if(root->data.num == number)
        return root;
    if(root->data.num > number)
        return search(root -> left, number);
    else
        return search(root->right, number);
}


int delete_node(Node** root, int number) {

    if(*root == NULL)
        return -1;

    else{

        if((*root)->data.num > number)
            return delete_node(&(*root)->left, number);
        else if((*root)->data.num < number)
            return delete_node(&(*root)->right, number);
        
        else{

            // most left node in the right subtree
            if((*root)->left && (*root)->right){

                Node* temp = (*root)->right;
                while(temp->left)
                    temp = temp->left;
                
                (*root)->data = temp->data;
                delete_node(&(*root)->right, temp->data.num);
            }
            // it has only one child or is a leaf
            else{

                Node* temp = *root;
                if(temp->left)
                    *root = temp->left;
                else
                    *root = temp->right;
                
                free(temp);
                return 0;
            }
        }
    }
}