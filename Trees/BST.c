#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
struct node{
    int data;
    struct node *left,*right;
}*root=NULL;
void create()
{
    struct node *newnode,*temp,*par;
    int nodes,data;
    printf("Enter number of nodes:");
    scanf("%d",&nodes);
    for(int i=0;i<nodes;i++)
    {
        printf("Enter data:");
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
            if(temp->data>data)
            {
                par=temp;
                temp=temp->left;
            }
            else 
            {
                par=temp;
                temp=temp->right;
            }
            }
            if(par->data>data)
            {
                par->left=newnode;
            }
            else
            {
                par->right=newnode;
            }
        }
        
    }
}
void insert()
{
    struct node *newnode,*temp,*par;
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
        if(temp->data>data)
        {
            par=temp;
            temp=temp->left;
        }
        else 
        {
            par=temp;
            temp=temp->right;
        }
        }
         if(par->data>data)
        {
            par->left=newnode;
        }
        else
        {
            par->right=newnode;
        }
    }
}
void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        inorder(temp->left);
        inorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        inorder(temp->right);
        printf("%d\t",temp->data);
    }
}
int totalnodes(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else 
    {
        return totalnodes(temp->left)+totalnodes(temp->right)+1;
    }
}
int internalnodes(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else if(temp->left==NULL && temp->right==NULL)
    {
        return 0;
    }
    else 
    {
        return internalnodes(temp->left)+internalnodes(temp->right)+1;
    }
}
int externalnodes(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else if(temp->left==NULL && temp->right==NULL)
    {
        return 1;
    }
    else 
    {
        return externalnodes(temp->left)+externalnodes(temp->right);
    }
}
void mirrorimage(struct node *temp)
{
    struct node *t1;
    if(temp!=NULL)
    {
        mirrorimage(temp->left);
        mirrorimage(temp->right);
        t1=temp->left;
        temp->left=temp->right;
        temp->right=t1;
    }
}
void delete()
{
    int val;
    struct node *temp, *parent, *ps, *succ;
    printf("Enter the value to be deleted:\n");
    scanf("%d", &val);
    temp = root;
    while (temp != NULL && temp -> data != val)
    {

        if (temp -> data <= val)
        {
            parent = temp;
            temp = temp -> right;
        }
        else
        {
            parent = temp;
            temp = temp -> left;
        }
    }
    if (temp == NULL)
    {
        printf("Value not Found!");
    }
    // leaf node
    else if (temp -> right == NULL && temp -> left == NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = NULL;
            free(temp);
        }
        else
        {
            parent -> right = NULL;
            free(temp);
        }
    }
    // single child
    else if (temp -> left != NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = temp -> left;
            free(temp);
        }
        else
        {
            parent -> right = temp -> left;
            free(temp);
        }
    }
    else if (temp -> right != NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = temp -> right;
            free(temp);
        }
        else
        {
            parent -> right = temp -> right;
            free(temp);
        }
    }
    else 
        {
            succ = temp -> left;
            ps = temp;
            while (succ -> right != NULL)
            {
                ps = succ;
                succ = succ -> right;
            }
            if (ps == temp)
            {
                temp -> data = succ -> data;
                temp -> left = NULL;
                free(succ);
            }
            else
            {
                temp -> data = succ -> data;
                ps -> right = succ -> left;
                free(succ);
            }
        }
}
int maxDepth(struct node* temp)
{
    if (temp == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(temp->left);
        int rDepth = maxDepth(temp->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void main()
{
    int depth;
    while(1)
    {
    int choice;
    printf("----MENU----\n");
    printf("1.Create\n");
    printf("2.Delete\n");
    printf("3.Totalnodes\n");
    printf("4.Internalnodes\n");
    printf("5.Externalnodes\n");
    printf("6.Inorder\n");
    printf("7.Postorder\n");
    printf("8.Preorder\n");
    printf("9.MirrorImage\n");
    printf("10.Insert\n");
    printf("11.Exit\n");
    printf("12.Height");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        delete();
        break;
    case 3:
        printf("Total nodes are %d.\n",totalnodes(root));
        break;
    case 4:
        printf("Internal nodes are %d.\n",internalnodes(root));
        break;
    case 5:
        printf("External nodes are %d.\n",externalnodes(root));
        break;
    case 6:
        inorder(root);
        printf("\n");
        break;
    case 7:
        postorder(root);
        printf("\n");
        break;
    case 8:
        preorder(root);
        printf("\n");
        break;
    case 9:
        mirrorimage(root);
        break;
    case 10:
        insert();
        break;
    case 11:
        exit(0);
        break;
    case 12:
        depth=maxDepth(root);
        printf("%d",depth);
    default:
        break;
    }
    }
}