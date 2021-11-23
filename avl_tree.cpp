#include <iostream> 
using namespace std; 

class TreeNode
{
  public:
    int value;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode()
    {
       left = NULL;
       right = NULL;
    }
};

class Avl
{
   public:
    
   TreeNode *root = NULL;
   
    int height(TreeNode *curr)
    {
        int lheight, rheight;
        if(curr == NULL)
           return -1;
        
        lheight = height(curr->left);
        rheight = height(curr->right);
        
        if(lheight>rheight)
            return lheight+1;
        
        else
            return rheight+1;
           
    }
    
    
    int bFactor(TreeNode *curr)
    {
      if(curr == NULL)
        return -1;
        
      else 
        return (height(curr->left) - height(curr->right));
    }
    
    // left Rotation
    TreeNode *leftRotate(TreeNode *critical_node)
    {
        TreeNode * mid_node = critical_node->right;
        TreeNode *mid_left = mid_node->left;
        
        // swaping
        mid_node->left = critical_node;
        critical_node->right = mid_left;
        
        return mid_node;
    }
    
    // right Rotation
    TreeNode *rightRotate(TreeNode *critical_node)
    {
       TreeNode *left_node = critical_node->left;
        TreeNode *below_node= left_node->right;
        
        // swaping 
        left_node->right = critical_node;
        critical_node->left = below_node;       
        
        return left_node;
    }
    
    TreeNode *insertRecursive(TreeNode * parent,TreeNode *new_node)
    {
       if(parent == NULL)
       {
          parent = new_node;
          cout<<"node inserted"<<endl;
          return parent;   
       }  
        
       else if(new_node->value < parent->value)
       {
          parent->left = insertRecursive(parent->left,new_node); 
       }
        
       else if(new_node->value > parent->value)
       {
          parent->right = insertRecursive(parent->right,new_node); 
       } 
       
       else
       {
          cout<<"Duplicates not allowed"<<endl;
            return parent; 
       } 
        
        int bf = bFactor(parent);
        
        if(bf > 1 and new_node->value < parent->left->value)
        {
            return rightRotate(parent);
        }        
        
        else if(bf < -1 and new_node->value > parent->right->value)
        {
            return leftRotate(parent);
        }
        
        else if(bf > 1 and new_node->value > parent->left->value)
        {
            parent->left = leftRotate(parent->left);
            return rightRotate(parent);
        }
        
        else if(bf < -1 and new_node->value < parent->right->value)
        {
            parent->right = rightRotate(parent->right);
            return leftRotate(parent);
        }
        return parent;
    }
    
   void print2D(TreeNode *curr, int space)
   {
      if(curr == NULL)
        return;
        
       space = space + 5;
        
       print2D(curr->right,space);
       cout<<"\n";
       
        for(int i = 5; i<space; i++)
        {
           cout<<" ";
        } 
        cout<<curr->value<<endl;       
        
        print2D(curr->left,space);    
   }
    
    
    // method required in deleteNode
    TreeNode *minRight(TreeNode *n)
    {
       while(n->left!=NULL)
        {
            n = n->left; 
         }
        return n;
    }
   
    TreeNode *deleteNode(TreeNode *curr,int key)
    {
        if(curr == NULL)
         {
           cout<<"Node doesn't exists"<<endl;
            return curr;
          }
        
        else if(key < curr->value)
        {
             curr->left = deleteNode(curr->left,key);
        }
         
        else if(key > curr->value)
        {
             curr->right = deleteNode(curr->right,key);
        }   
        
        else
        {
           if(curr->left == NULL)
            {
               TreeNode *right_node = curr->right;
                delete curr;
                return right_node;
             }
            
            else if(curr->right == NULL)
            {
               TreeNode *left_node = curr->left;
                delete curr;
                return left_node;
             }     
             
            else 
            {
                TreeNode *min_node = minRight(curr->right);
                curr->value = min_node->value;
                curr->right = deleteNode(curr->right,min_node->value);
            }  
            
        }
        
        int bf = bFactor(curr);
        
        if(bf == 2 and bFactor(curr->left) >=0)
        {
            return rightRotate(curr);
        }
        
        else if(bf == 2 and bFactor(curr->left)== -1)
        {
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }        
        
        else if(bf == -2 and bFactor(curr->right)<=0)
        {
             return leftRotate(curr);
        }
        
        else if(bf == -2 and bFactor(curr->right) == 1)
        {
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }
        return curr;
    }
};


int main()
{  
    int option;
    Avl avl;
    int key;
    
    do
    {
      TreeNode *node = new TreeNode(); 
      cout<<"1. insert a node"<<endl;
      cout<<"2. print the nodes"<<endl;
      cout<<"3. height of the tree"<<endl;
      cout<<"4. Delete a node"<<endl;
      cout<<"0. exit"<<endl;
      cin>>option;
      switch(option)
      {
       case 0: 
           cout<<"see you next time"<<endl;
        break;   
        
       case 1:
         cout<<"let's insert a node"<<endl;
         cout<<"Enter the value";
         cin>>key;   
         node->value = key;
         avl.root = avl.insertRecursive(avl.root,node);         
        break;
        
        case 2:
            avl.print2D(avl.root,5);
           break;
    
        case 3:
            cout<<avl.height(avl.root)<<endl;
           break;
        
        case 4:
            cout<<"enter the key to delete a node"<<endl;
            cin>>key;
            avl.root = avl.deleteNode(avl.root,key);
           break;
    
         default:
            cout<<"input the right choice"<<endl;
    }   
    }while(option!=0);
    
   return 0;   
}