#include <iostream> 
using namespace std; 

class TreeNode 
{   
    public: 
    TreeNode *left; 
    TreeNode *right; 
    int value; 
    
    TreeNode() 
    { 
        left = NULL; 
        right = NULL; 
        value = 0; 
     } 
    
    TreeNode(int key) 
    { 
        left = NULL; 
        right = NULL; 
        value = key; 
     } 
}; 

class BST 
{
    public: 
    // DAta members 
    TreeNode *root = NULL; 
    
    // member function 
    bool isEmpty() 
    { 
        if(root == NULL) 
            return true; 
        else 
        return false; 
     } 
     
     TreeNode *insertionRecursion(TreeNode* curr, TreeNode *new_node)
    {
      if(curr == NULL)
      {
           curr = new_node;
           cout<<"Value inserted"<<endl;
           return curr;
      }  
        
      else if(new_node->value < curr->value)
      {
         curr->left = insertionRecursion(curr->left,new_node);     
       }    
        
      else if(new_node->value > curr->value)
      {
         curr->right = insertionRecursion(curr->right,new_node);     
      }    
      
      else 
      {
            cout<<"duplicates not allowed"<<endl;
            return curr;   
      }
              
      return curr;
    }
    
    void insertNode(TreeNode *new_node)    
    { 
     if(isEmpty())
      {
          root = new_node;
          cout<<"Node inserted as a root"<<endl;      
       }
      
      else 
      {
        TreeNode *temp = root;
        
        while(temp!=NULL)
        {    
         if(new_node->value == temp->value)
          {
                    cout<<"Duplicate not allowed"<<endl;
           }
          
          else if(new_node->value < temp->value and temp->left == NULL)
            {
                  temp->left = new_node;
                  cout<<"Node inserted at the left of "<<temp->value<<endl;
                break;
            }
          
           else if(new_node->value < temp->value)
           {
             temp = temp->left;         
           }       
             
           else if(new_node->value > temp->value and temp->right == NULL)
          {
								temp->right = new_node;
            cout<<"Node inserted at the right   of "<<temp->value<<endl; 
            break;			
          }
          
          else 
          {
           temp = temp->right;     
          }
        }     
      } 
    } 
    
    TreeNode *minINRight(TreeNode *n)
    {
       while(n->left != NULL)
           n = n->left;    
        
       return n;
    }
    
    TreeNode *deleteN(TreeNode *curr, int val)
    {
       if(curr == NULL)
          return NULL;
 
        else if(val < curr->value)    
            curr->left = deleteN(curr->left,val);
        
        else if(val > curr->value)    
            curr->right = deleteN(curr->right,val);
        
        else 
        {
          if(curr->left == NULL)
            {
                TreeNode *temp = curr->right;
                return temp;
            }
            else if(curr->right == NULL)
            {
                TreeNode *temp = curr->left;
                return temp;
            }
            
            else
            {
              TreeNode *temp;
              temp=minINRight(curr->right);
              curr->value = temp->value;
              curr->right = deleteN(curr->right,temp->value);
            }
    
        }
        return curr;
    
    }
    
    void deleteNode(int data) 
    { 
        if(searchNode(data) == NULL)
            cout<<"Node doesn't exists"<<endl;
        
        else
        {
           deleteN(root,data);
           cout<<"Node deleted successfully"<<endl;
        } 
    } 
    
    // preOrder method for PrintNodes
    void preOrder(TreeNode *curr_node)
    {
        cout<<curr_node->value<<" ";
               
        TreeNode *temp;
        
        if(curr_node->left != NULL)
        {
           temp = curr_node->left; 
           preOrder(temp);
        }
        
        if(curr_node->right != NULL)
        {
           temp = curr_node->right; 
           preOrder(temp);
        }
    }
    
    // inOrder method for PrintNodes
    void inOrder(TreeNode *curr_node)
    {
        TreeNode *temp;
        if(curr_node->left != NULL)
        {
           temp = curr_node->left; 
           inOrder(temp);
        }
        
        cout<<curr_node->value<<" ";
        
        if(curr_node->right != NULL)
        {
           temp = curr_node->right; 
           inOrder(temp);
        }
    }
    
    // postOrder method for PrintNodes
    void postOrder(TreeNode *curr_node)
    {
        TreeNode *temp;
        if(curr_node->left != NULL)
        {
           temp = curr_node->left; 
           postOrder(temp);
        }
        
        if(curr_node->right != NULL)
        {
           temp = curr_node->right; 
           postOrder(temp);
        }
        cout<<curr_node->value<<" ";
    }
    
    // finding the height of the tree
    int heightOfTree(TreeNode *curr)
    {
        if(curr == NULL)
             return -1;
        
        int lheight = heightOfTree(curr->left);    
        int rheight = heightOfTree(curr->right);
        
        if(lheight > rheight)
            return lheight+1;    
        
        return rheight+1;
    }
    
    void bfs(TreeNode *n, int level)
    {
       if(n == NULL)
          return;
        
        else if(level == 0)
           cout<<n->value<<" ";
        
        else
        {
           bfs(n->left,level-1);
           bfs(n->right,level-1);
        } 
    }
    
    void printbfs(TreeNode *curr_node)
    { 
        int h = heightOfTree(curr_node);   
        
        for(int i=0; i<=h; i++)
           bfs(curr_node,i);
    }
        
        
    void print2D(TreeNode *curr_node, int space)
    {
      // 5 space is added after every node so that we can make a perfect format
       if(curr_node == NULL)
          return; 
        
        space = space + 5;
        print2D(curr_node->right,space);
        cout<<"\n";
        for(int i=5; i<space; i++)
           cout<<" "; 
        
        cout<<curr_node->value<<endl;
        print2D(curr_node->left,space);
    }
    
    void printNodes() 
    { 
        int want;
        cout<<"In which order you want"<<endl;
        cout<<"1. PreOrder"<<endl;
        cout<<"2. InOrder"<<endl;
        cout<<"3. PostOrder"<<endl;
        cout<<"4. BFS order"<<endl;
        cout<<"5. Print2D"<<endl;
        cin>>want;
        
        switch(want)
        {
          case 1: cout<<"PreOrder"<<endl; 
                  preOrder(root);
                  break;
            
           case 2: cout<<"InOrder"<<endl; 
                   inOrder(root);
                  break;
            
          case 3: cout<<"PostgOrder"<<endl; 
                  postOrder(root);
                  break;
          
          case 4: cout<<"Printing in row wise matter"<<endl; 
                  printbfs(root);
                  break;
     
            
          case 5: cout<<"Printing in 2d"<<endl; 
                  print2D(root,5);
                  break;
    
        }
    } 
    
    TreeNode *searchNode(int key) 
    { 
       TreeNode *temp = root;
             
       if(root==NULL)
           return root;
        
        else
        {
            while(temp != NULL)
            {
                if(temp->value == key)
                {
                    return temp;
                }
                    
                else if(key < temp->value)
                     temp = temp->left;
                
                else 
                   temp = temp->right;            
            }
        }   
      return temp; 
    } 

}; 

  int main() 
  { 
    int option, key; 
    BST bs; // object of BST 
     
    
    do 
    { 
        TreeNode *new_node = new TreeNode();
        cout<<"Enter your choose by selecting respective numbers "<<endl;
        cout<<"1.Empty or node"<<endl;
        cout<<"2.Insert the new Node"<<endl;
        cout<<"3.Insert a new node using recursion"<<endl;
        cout<<"4.Print the nodes"<<endl;
        cout<<"5.delete a node"<<endl;
        cout<<"6.Search a node"<<endl;
                
        cin>>option; 
        
        switch(option) 
        { 
            case 1: 
            if(bs.isEmpty()) 
            {
               cout<<"Tree is empty"<<endl;
            }
            else 
            {
                cout<<"Tree is not empty"<<endl;
            }
            break;
            
           case 2: cout<<"Insert a new node "<<endl; 
            cout<<"Enter the data"<<endl;
            cin>>key;
            new_node->value = key;
            bs.insertNode(new_node); 
            break; 
           
            case 3: cout<<"Insert a new node "<<endl; 
            cout<<"Enter the data"<<endl;
            cin>>key;
            new_node->value = key;
            bs.root = bs.insertionRecursion(bs.root,new_node); 
            break; 
            
            case 4: cout<<"Print the BST "<<endl; 
            bs.printNodes(); 
            break; 
            
            case 5: cout<<"To delete a Node please enter a key"<<endl;
            cin>>key; 
            bs.deleteNode(key); 
            break; 
            
            case 6: cout<<"Search in BST "<<endl; 
            cout<<"Enter the key"<<endl;
            cin>>key;
            if(bs.searchNode(key) == NULL)
                  cout<<"Node doesn't exists"<<endl;
        
            else
            {
               cout<<"Node exists"<<endl;
            }
            break;
         
            default: cout<<"Please enter a valid choice"; 
            } 
        }while(option!=0); 
    return 0; 
    }