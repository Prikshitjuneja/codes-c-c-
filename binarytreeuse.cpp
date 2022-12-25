#include<iostream>
#include<queue>
#include"binarytree.h"
using namespace std;
//1 2 3 4 5 -1 -1 -1 6 -1 -1 -1 -1
BinaryTreeNode<int>*takeinputlevelwise()
{
    cout<<"enter the root data:"<<endl;
    int rootdata;
    cin>>rootdata;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode<int>*frontnode=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter the left child of"<<frontnode->data<<":"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1)
        {
            BinaryTreeNode<int>*leftchild=new BinaryTreeNode<int>(leftchilddata);
            frontnode->left=leftchild;
            pendingnodes.push(leftchild);
        }

        cout<<"enter the right child of"<<frontnode->data<<":"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1)
        {
            BinaryTreeNode<int>*rightchild=new BinaryTreeNode<int>(rightchilddata);
            frontnode->right=rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;


}
void printlevelwise(BinaryTreeNode<int>*root)
{
    queue <BinaryTreeNode<int>*>pendingnodes;

    pendingnodes.push(root);

    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode<int>*frontnode=pendingnodes.front();
        cout<<frontnode->data<<":";
        if(frontnode->left!=NULL)
        {
            cout<<"L:"<<frontnode->left->data<<",";
            pendingnodes.push(frontnode->left);
        }
        if(frontnode->right!=NULL)
        {
            cout<<"R:"<<frontnode->right->data;
            pendingnodes.push(frontnode->right);
        }
        cout<<endl;
         pendingnodes.pop();

}
}
int countnodes(BinaryTreeNode<int>*root)
{
    if(root==NULL)
        return 0;
    int ans=1;
    ans+=countnodes(root->left);
    ans+=countnodes(root->right);
    return ans;
}
pair<int,int>get_heightdiameter(BinaryTreeNode<int>*root)
{     //diameter is max distance between any 2 nodes
    //diameter=max(left height+right height,max(left diameter,right diameter))
    if(root==NULL)
    {
       pair<int,int> p;    // here we use inbuilt pair class having first and second as element
       p.first=0;
       p.second=0;    //base case height =0 and diameter =0 for NUL tree
       return p;
    }
    pair<int,int> p_left=get_heightdiameter(root->left);
    pair<int,int> p_right=get_heightdiameter(root->right);

    int height_left=p_left.first;
    int diameter_left=p_left.second;
    int height_right=p_right.first;
    int diameter_right=p_right.second;

    int height=1+max(height_left,height_right);
    int diameter=max(height_left+height_right,max(diameter_left,diameter_right));
    pair<int,int> ans;
    ans.first=height;
    ans.second=diameter;    //pair class ans contains the final height and diameter of tree
    return ans;
}
int main()
{
    BinaryTreeNode<int>*root=takeinputlevelwise();
    printlevelwise(root);
    pair<int,int> p=get_heightdiameter(root);
    cout<<"height: "<<p.first<<endl;
    cout<<"diameter: "<<p.second<<endl;
    delete root;
}
  
//binarytreeheaderfile
template <typename T>
class BinaryTreeNode
{
  public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T>* right;

  BinaryTreeNode(T data)
  {
      this->data=data;
      left=NULL;
      right=NULL;

  }
  ~BinaryTreeNode()
  {
      delete left;
      delete right;
  }

};
