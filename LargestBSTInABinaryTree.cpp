//https://practice.geeksforgeeks.org/problems/largest-bst/1

struct Node
 {
     int data;
     struct Node* left, *right;
};*/
/*You are required to complete this method */

struct minmax{
  int min;
  int max;
  bool isBST;
  int size;
};

int max(int a,int b){
    return a>b?a:b;
}

int largestBstUtil(Node *root, int &min, int &max, bool &isBST){
    if(root == NULL){
        min = INT_MAX;
        max = INT_MIN;
        isBST = true;
        return 0;
    }
    
    if(root->left==NULL && root->right==NULL){
        min  = root->data;
        max = root->data;
        isBST = true;
        return 1;
    }
    
    
    int Lmin,Lmax, Rmin, Rmax;
    bool LisBST,RisBST;
    int lSize  = largestBstUtil(root->left, Lmin, Lmax, LisBST);
    int rSize = largestBstUtil(root->right, Rmin, Rmax, RisBST);
    if(LisBST && RisBST){
        if(root->data >= Lmax && root->data <= Rmin){
            isBST = true;
            min = Lmin;
            max = Rmax;
            return lSize+rSize+1;
        }else{
            isBST = false;
            min = 0;
            max = 0;
            return lSize>rSize?lSize:rSize;
            
        }
    }else{
        isBST = false;
        min = 0;
        max = 0;
        return lSize>rSize?lSize:rSize;
    }
    
    
}

int largestBst(Node *root)
{
int min,max;
bool isBST;
return  largestBstUtil(root,min,max,isBST);
    
    
    
}
