
//
//  main.cpp
//  implmentationBinaryTree
//
//  Created by fahad on 11/14/19.
//  Copyright © 2019 fahad. All rights reserved.
//


#include <iostream>

using namespace std;


struct Tree_node{
    
    int number;
    Tree_node *right;
    Tree_node *left;
    Tree_node *prev;
};


class BinaryTree{
    
private:
    void insert(int num);
public:
    
    Tree_node* insert(Tree_node* node,int num);
    void printTree(struct Tree_node* node);
    Tree_node* search_n(Tree_node* node,int num);
    Tree_node* delete_n(Tree_node* node,int num);
    void inOrder_(struct Tree_node* node);
    void preOrder_(struct Tree_node* node);
    void postOrder_(struct Tree_node* node);
    
    
    int menu();
    
};

int BinaryTree::menu()
{
    int action;
    cout << endl << endl << endl;
    cout << "       BINARY SEARCH TREE" << endl << endl;
    cout << "   1.  Insert a number in the tree" << endl;
    cout << "   2.  Delete a number from the tree" << endl;
    cout << "   3.  Search for a number in the tree" << endl;
    cout << "   4.  Print the tree in order" << endl;
    cout << "   5.  pre-order" << endl;
    cout << "   6.  post-order" << endl;
    cout << "   7.  in-order" << endl;
    cout << "   8.  Exit the program" << endl;
    cout << "       Please enter your selection:  ";
    cin >> action;
    return action;
}


Tree_node*
BinaryTree::insert(Tree_node* node,int num){
    
    if (node == nullptr){
        
        node = new Tree_node;
        node->number = num;
        node->left = nullptr;
        node->right = nullptr;
        node->prev = node;
        
    }else{
        
        if(node->prev->number > num){
            
            (*node).left = insert(node->left,num);
            
        }else{
            (*node).right = insert((*node).right,num);
            
        }
        
    }
    return node;
}

void
BinaryTree::printTree(struct Tree_node* node) {
    if (node == nullptr)
        return;
    printTree(node->left);
    cout << node->number << endl;
    printTree(node->right);
    
}

Tree_node*
BinaryTree::search_n(Tree_node* node,int num){
    
    if(node != nullptr){
        
        if(node->number == num){
            
            cout << "got it " << endl;
            
            return 0;
        }
        if(node->number > num){
            
            (*node).left = search_n((*node).left,num);
            
            
        }else{
            
            search_n(node->right,num);
            
        }
    }else{
        
        cout << "sorry cannot find it" << endl;
    }
    
    return node;
}

Tree_node*
BinaryTree::delete_n(Tree_node* node,int num)
{
    if (node == NULL)
        return node;
    else if (num < node->number)
        node->left = delete_n(node->left, num);
    else if (num > node->number)
        node->right = delete_n(node->right, num);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        else if (node->left == NULL)
        {
            Tree_node *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL)
        {
            Tree_node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            while (node->left != NULL)
                node = node->left;
            Tree_node* min = node;
            node->number = min->number;
            node->right = delete_n(node->right, min->number);
        }
    }
    return node;
}

void
BinaryTree::inOrder_(Tree_node* node){
    //Tree example 4,3,2,5,1,9
    //inOrder print it like this 1,2,3,4,5,9
    
    if(node != nullptr){
        
        inOrder_(node->left);
        cout << node->number << endl;
        inOrder_(node->right);
    }
}
//Preorder (Root, Left, Right)

void
BinaryTree::preOrder_(Tree_node* node){
    //input 4,3,2,1,5,9
    //it supposed to print 4,3,2,1,5,9
    
    if(node != nullptr){
        
        cout << node->number << endl;
        preOrder_(node->left);
        preOrder_(node->right);
    }
    
}


void
BinaryTree::postOrder_(Tree_node* node){
    if(node != nullptr){
        
        postOrder_(node->left);
        postOrder_(node->right);
        cout << node->number << endl;
        
    }
}

int main(int argc, const char * argv[]) {
    
    Tree_node* head = NULL;
    BinaryTree* binary = new BinaryTree;
    
    int num;
    int i = 0,sum = 0;
    while(1)
    {
        switch(binary->menu())
        {
             case 1 : cout<<endl;
                cout<<" Type a negative number when you finished "<<endl;
                do
                {
                   sum +=i;
                   cout<<"Enter a Number: ";
                   scanf("%i",&i);
                    if (i > -1) {
                        head = binary->insert(head,i);
                    }
                }
                
                while(i > -1);
                
                break;
            
             case 2 : cout<<" Enter a number to deleted : ";
                
                    cin>>num;
                    head = binary->delete_n(head, num);
                    break;
                
             case 3 : cout<<" Enter a Number to Search : ";
                
                    cin>>num;
                    head = binary->search_n(head,num);
                    break;
                
             case 4 : cout<<endl;
                
                    binary->printTree(head);
                    break;
                
             case 5 : cout<<endl;
                       
                    binary->inOrder_(head);
                    break;
                
             case 6 : cout<<endl;
                        
                    binary->preOrder_(head);
                    break;
                
             case 7 : cout<<endl;
                
                    binary->postOrder_(head);
                    break;
                
            case 8 : cout<<endl;
                    return 0;
        
        }
    }

    
}
