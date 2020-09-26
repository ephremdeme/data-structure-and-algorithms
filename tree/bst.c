#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void tree_create(struct tree *self){
    self->root = NULL;
}

struct node *node_add(struct node *self,int value){
    if(self == NULL){
        struct node *other = malloc(sizeof(struct node));
        other->value = value;
        other->right = NULL;
        other->left = NULL;
        return other;
    }

    if(value < self->value){
        self->left = node_add(self->left,value);
        return self;
    }

    if(value > self->value){
        self->right = node_add(self->right,value);
        return self;
    }
    return self;
}

void tree_add(struct tree *self,int value){
    self->root = node_add(self->root,value);
}

void node_destroy(struct node *self){
    if(self==NULL){
        return;
    }

    node_destroy(self->left);
    node_destroy(self->right);
    free(self);
}

void tree_destroy(struct tree *self){
    node_destroy(self->root);
    
}

void print_tree_rec(struct node *self, int space) { 
    if (self == NULL){ 
        return; 
    }
  
    space += 10; 
  
    print_tree_rec(self->right, space); 
  
    printf("\n"); 

    for (int i = 10; i < space; i++){
        printf(" "); 
    }
    
    printf("[ %i ]\n", self->value); 
   
    print_tree_rec(self->left, space); 
} 

bool node_is_bst(struct node *self){
    if(self == NULL){
        return true;
    }

    if(self->right == NULL && self->left == NULL){
        return true;
    }

    if(self->left == NULL){
        return (self->value < self->right->value) && node_is_bst(self->right);
    }

    if(self->right == NULL){
        return (self->value > self->left->value) && node_is_bst(self->left);
    }

    return (self->value < self->right->value) && node_is_bst(self->right) && (self->value > self->left->value) && node_is_bst(self->left);

    
}

bool tree_is_bst(struct tree *self){
    return node_is_bst(self->root);
}

// Supprime le minimum de self, 
struct node *delete_min(struct node *self, struct node **min){
    if(self->left == NULL){
        struct node *right = self->right; 
        self->right = NULL; // suppression des fils droits de self
        *min = self; // 
        return right;
    }

    self->left = delete_min(self->left,min);
    return self;
}


struct node *node_delete(struct node *self){
    struct node *left = self->left;
    struct node *right = self->right;
    free(self);
    self = NULL;

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    right = delete_min(right,&self); // Ici on modifie self, = *min
    self->left = left;
    self->right = right;
    return self;
}



struct node *node_remove(struct node *self,int value){
    if(self == NULL){
        return NULL;
    }

    if(self->value > value){
        self->left = node_remove(self->left,value);
        return self;
    }

    if(self->value < value){
        self->right = node_remove(self->right,value);
        return self;
    }

    return node_delete(self);
}

void tree_remove(struct tree *self, int value){
   self->root = node_remove(self->root,value);
}

int node_sum(struct node *self){
    if(self == NULL){
        return 0;
    }

    return self->value + node_sum(self->left) + node_sum(self->right);
}

int tree_sum(struct tree *self){
    return node_sum(self->root);
}


int main(void){

    struct tree bst;
    tree_create(&bst);
    printf("is_bst : %d\n",tree_is_bst(&bst));

    tree_add(&bst,5);
    tree_add(&bst,2);
    tree_add(&bst,8);
    tree_add(&bst,4);
    tree_add(&bst,6);
    tree_add(&bst,7);
    tree_add(&bst,1);
    tree_add(&bst,3);
    tree_add(&bst,0);

    printf("is_bst : %d\n",tree_is_bst(&bst));
    print_tree_rec(bst.root,10);

    printf("sum : %i \n",tree_sum(&bst));

     tree_remove(&bst,7);

     printf("is_bst : %d\n",tree_is_bst(&bst));

     print_tree_rec(bst.root,10);

    tree_destroy(&bst);

    return 0;
}