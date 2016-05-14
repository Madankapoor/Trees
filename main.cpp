#ifdef __GNUC__
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <deque>
using namespace std;
#else
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iomanip.h>
typedef int bool;
#define true 1
#define false 0
#endif
template <class typ2>
    class snode 
    {   public:
        typ2 d;
        snode * next;
    } ;
template <class type>
class Stack 
{   
  typedef snode<type>* Node;
   Node top;
public:
   
    Stack():top(NULL){}
    ~Stack()
    {
        while(top!=NULL)
        {
            Node t=top->next;
            delete top;
            top=t;
            }
    }
    void push(type e)
    {
        if(top==NULL){ 
            top=new snode<type>;
            top->d=e;
            top->next=NULL;
        }
        else{
            Node t=top;
            top= new snode<type>;
            top->d=e;
            top->next=t;
            }
        
    }

    type pop()
    {   type p=0;
        if(top==NULL){ 
        return p;}
        else 
        {
            p=top->d;
            Node t=top;
            top=top->next;
            delete t;
        }
        return p;
    }
    
    bool isempty()
    {
        return (top==NULL)?true:false;
    }
    type Top()
    {   if(top==NULL) return NULL;
        return top->d;
        }
    
};


template <class type>
class Queue
{
   typedef snode<type>* Node;
public:
    Node front,back;
    Queue()
    {
        front=back=NULL;
    }
    
    ~Queue()
    {
        while(front!=NULL)
        {
            Node temp=front->next;
            delete front;
            front=temp;
        }
    }
    
    void queue(type e)
    {
        if(back==NULL){ 
            front=back=new snode<type>;
            back->d=e;
            back->next=NULL;
        }
        else{
            Node t;
                           
            t=new snode<type>;
            t->d=e;
            t->next=NULL;
            back->next=t;
            back=t;
            }
        
    }

    type dequeue()
    {   type p;
        if(front==NULL){ 
        return p;}
        else 
        {
            p=front->d;
            Node t=front;
            front=front->next;
            delete t;
        }
        return p;
    }
    
    bool isempty()
    {
        return (top==NULL)?true:false;
    }
        
     type top()
     {
         if(front==NULL) return NULL;
         else return front->d;
        }
     type bottom()
     {
         if(back==NULL) return NULL;
         else return back->d;
         }



};


template <class Q>
class node
{
 public:
	Q d;
	int height;
    int bal;
    bool color;
	node<Q> *left,*right,*parent;
    
    node<Q>(Q a=0,node<Q>* p=NULL,node<Q>* l=NULL,node<Q>*r=NULL){
        bal=height=color=0;
        parent=p;
        left=l;
        right=r;
        d=a;
        color=true;
        }
    
};



template <class T>
class Bst
{       protected:
	typedef node<T>* Node;
	Node root;
	int count;
	public:
	//constructor
	Bst():root(NULL),count(0){}
	~Bst()
	{
	   clear();
	}
	Bst(Bst<T>& R)
	{       root=NULL;
		count=0;
	      //	double x = log(double(R.count+1)) / log(2.0);

		Node* a=new Node[R.count];
		for(int i=0;i<R.count;i++) a[i]=NULL;
		int front=0,back=0;
		a[back++]=R.root;
		while( front < back )
		{       if(a[front]!=NULL)
		       {   if(a[front]->left!=NULL)
			   a[back++]=a[front]->left;
			   if(a[front]->right!=NULL)
			   a[back++]=a[front]->right;
		       }
			front++;
		}
		cout << "Inserting In COPY" << endl;
		for(front=0;front<back;front++)
			if(a[front]!=NULL)
			   {    cout << a[front]->d << " ";
				insert(a[front]->d);
			   }
		cout << endl;
		delete[] a;
	}
	void clear()
	{   Node* a=new Node[count];
		for(int i=0;i<count;i++) a[i]=NULL;
		int front=0,back=0;
		a[back++]=root;
		while( front < back )
		{       if(a[front]!=NULL)
		       {   if(a[front]->left!=NULL)
			   a[back++]=a[front]->left;
			   if(a[front]->right!=NULL)
			   a[back++]=a[front]->right;
		       }
			front++;
		}
		for(front=0;front<back;front++)
			delete a[front];
	       delete[] a;
	}
       virtual	void insert(T a)
	{	count++;
		root=insertNode(root,a);
	}
	
      virtual void print()
         {
              Node ar[10000];
              Node LevelChange=new node<T>(0);
              int front=0,back=0;
              int level_count=2;
              int curlevel_count=2;
              int node_count=0;
              if(root==NULL) return;
              
              ar[back++]=root;
              node_count++;
              ar[back++]=LevelChange;
              while(front < back)
              {
                  if(ar[front]==LevelChange)
                      { 
                          while(curlevel_count--)   ar[back++]=NULL;
                          ar[back++]=LevelChange;
                      }
                   else if(ar[front]!=NULL)
                      {     if(ar[front]->left!=NULL) node_count++;    
                            ar[back++]=ar[front]->left;
                            if(ar[front]->right!=NULL) node_count++;   
                            ar[back++]=ar[front]->right;
                            curlevel_count-=2;
                      }
                    else 
                    {   ar[back++]=NULL;
                        ar[back++]=NULL;
                        curlevel_count-=2;
                        }
                    
                    if(curlevel_count<=0 && node_count == count )  
                    break;
                    
                    if(curlevel_count<=0 && ar[front]==LevelChange) 
                        {   level_count=2*level_count;
                            curlevel_count=level_count;}
                front++;
                }
             
              front=0;
              int levelone=0;
              char space[4]="   ",blank[4]="___";
              int leftside=level_count-1;
              int rightside=level_count-1;
              while(front<back)
              {   if(levelone>=2) rightside=(rightside+1)/2-1;   
                  int l=leftside,r=rightside;
                  while(l--) cout << space;
                  while(front < back && ar[front]!=LevelChange)
                    {   if( ar[front]!=NULL) 
                          cout << ar[front]->d ;
                        else cout << blank ;
                        
                        while(r--) cout << space;
                            r=rightside;
                        front++;
                    }
                                     
                    cout << endl;
                    leftside=(leftside+1)/2-1;
                    levelone++;
                    front++;
              }
                  
         delete LevelChange;
        }
            


	void Display_PreOrder(ostream & O=cout)
	{       O << "PreOrder Display " ;
		Display_Pre(root, O);
		O << endl;
	}

	void Display_PostOrder(ostream & O=cout)
	{       O << "Post Order Display " ;
		Display_Pos(root, O);
		O << endl;
	}

       T find_max()
	{
		if(root==NULL) return 0;
		return maxfind(root)->d;
	}


	T find_min()
	{       if(root==NULL) return 0;
		return minfind(root)->d;
	}
	Node& Search(T a)
	{

	   return Search_tree(root,a);

	}

   virtual void Remove(T d)
    {   
        root=deleteNode(root,d);
    }
 

	protected:
   
    virtual Node deleteNode(Node root, T key)
    {
        // base case
        if (root == NULL) return root;
     
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        if (key < root->d)
            root->left = deleteNode(root->left, key);
     
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (key > root->d)
            root->right = deleteNode(root->right, key);
     
        // if key is same as root's key, then This is the node
        // to be deleted
        else
        {
            // node with only one child or no child
            if (root->left == NULL)
            {
                Node temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node temp = root->left;
                delete root;
                return temp;
            }
     
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node temp = minfind(root->right);
     
            // Copy the inorder successor's content to this node
            root->d = temp->d;
     
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->d);
        }
        return root;
    }

	
	Node& Search_tree(Node& R,T a)
	{
	     if(R==NULL) return R;
	     else if(R->d==a) return R;
	     else if(R->d > a) return Search_tree(R->left,a);
	     else return Search_tree(R->right,a);
	}

	virtual Node insertNode(Node Root,T a)
	{   if(Root==NULL)
		{	Root=new node<T>;
			Root->d=a;
			Root->left=Root->right=NULL;
		}
	   else if(Root->d> a)
		{
		     Root->left=insertNode(Root->left,a);
		}
	   else  Root->right=insertNode(Root->right,a);
       return Root;
	}

	void Display_Pre(const Node& Ts,ostream & O)
	{
	      if(Ts==NULL) return;
	    O << Ts->d << "->";

	      Display_Pre(Ts->left,O);

	      Display_Pre(Ts->right,O);
	  }
	void Display_Pos(const Node& Ts,ostream & O)
	{
	      if(Ts==NULL) return;

	      Display_Pos(Ts->left,O);

	      Display_Pos(Ts->right,O);

	      O << "->" <<Ts->d;
	}
	Node maxfind(const Node& R)
	{
		if(R->right==NULL) return R;
		else return maxfind(R->right);
	}
	Node minfind(const Node& R)
	{
		if(R->left==NULL) return R;
		else return minfind(R->left);
	}


};


template <class type>
class AVL :public Bst<type>// Georgy Adelson Velsky and Evgenii Landis tree
//Read the wiki page about AVL trees.To know about terminology and rotations.
//It is a self balancing tree.
//try to understand the insertion using the test case here:
//1,2,3,4,5,6,7,8,9,15,14,13,12,11,10
//try to delete some too .
{    
#ifdef __GNUC__
    typedef node<type>* Node;
#endif
    public:
    AVL():Bst<type>()
    {

    }
    void Display()
	{
#ifdef __GNUC__
        print(Bst<type>::root);
#endif
		}

    void insert(type a)
    {   
#ifdef __GNUC__
        Bst<type>::count++;
        insertBal_Node(Bst<type>::root,a);
#endif
#ifndef __GNUC__
        count++;
        insertBal_Node(root,a);
#endif
    }
    
    void Remove(type a)
    {
    #ifdef __GNUC__
   
    Bst<type>::root=deleteNode(Bst<type>::root,a);
    
    #else
    root=deleteNode(root,a);
    #endif
   
    }
    protected:
    Node deleteNode(Node R,type d)
    {
        
       if(R==NULL) return NULL;
       else if(d < R->d)
        R->left=deleteNode(R->left,d);
       else if(d > R->d)
        R->right=deleteNode(R->right,d);
       else
       {
           Node temp;
           if(R->left==NULL)
           {   
               temp=R->right; 
               delete R;
               Bst<type>::count--;
               return temp;
            }
           else if(R->right==NULL)
            {
               temp=R->left; 
               delete R;
               Bst<type>::count--;
               return temp;
            }
            else 
            {   
                temp=Bst<type>::maxfind(R->left);
                R->d=temp->d;
                R->left=deleteNode(R->left,R->d);
           
            }  
        }
        if (R == NULL)
        return R;
        UpdateHeight(R);
        int bal=R->bal=getbalance(R);
        if (bal > 1 && getbalance(R->left)>=0) // left left case
        //      Z      RIGHT ROTATION   
        //    Y   D    -->          Y    
        //  X   C                 X     Z    
        //A   B                 A  B   C  D 
        {
            RightRotation(R);
            
            }
            
        if(bal > 1 && getbalance(R->left)<0)
        {   LeftRotation(R->left);
            RightRotation(R);
            }
            
        if(bal < -1 && getbalance(R->right)<=0)
        {
            LeftRotation(R);
            
            }
        if(bal < -1 && getbalance(R->right)>0)
        {   RightRotation(R->right);
            LeftRotation(R);
            }
        
        
       return R;
    }  

    int height(Node & A)
    {  return (A==NULL)?-1:A->height;
    }

    int max(int a,int b){return (a>b)?a:b;}

    int getbalance(Node & S)
    {   if(S==NULL) return 0;
        return height(S->left)-height(S->right);
    }
    void UpdateHeight(Node & R)
    {   if(R==NULL) return;
        R->height=max(height(R->left),height(R->right))+1;
    }
    
    void RightRotation(Node& k2)
    { /*       k2                 
            k1   C    --->      K1  
          A   B               A      K2
                                   B     c
          */
        Node  k1=k2->left; 
        Node  B=k1->right;
        k2->left=B;
        UpdateHeight(k2);
        k1->right=k2;
        UpdateHeight(k1);
        k2=k1;   
     
    }
    void LeftRotation(Node& k1)
    {   //     R                 y
        //   T1   y     -->   R       T3
        //       T2  T3     T1   T2
           Node  k2=k1->right;
           Node  B=k2->left;
           k1->right=B;
           UpdateHeight(k1);
           k2->left=k1;
           UpdateHeight(k2);
           k1=k2;
    }



    void insertBal_Node(Node& R, type a)
    {
         if(R==NULL) {  R=new node<type>;
                R->d=a;
                R->left=R->right=NULL;
                 }
         else if(R->d < a) insertBal_Node(R->right,a);

         else insertBal_Node(R->left,a);

         //Updating the Height
         UpdateHeight(R);

        //Getting the balance
         int bal=R->bal=getbalance(R);

         //case 1 : LL RightRotaton of x with respect to y
         //       x   -->  y
         //     y        z   x
         //   z
         if( bal > 1 && a < R->left->d )
         {
             RightRotation(R);
         }
         else if(   bal > 1 && a > R->left->d)  //case 2 : LR
         {    //   x  leftRotation of y with respect to z       x
              // y    -->                                     z
              //   z                                        y



            LeftRotation(R->left) ;
            RightRotation(R);

         }
         else if(   bal < -1 && a > R->right->d)  //case 3 :RR
         {   //        Left rotation of x with respect to y
             //  x      -->                                  y
             //    y                                     x      z
              //      z
             LeftRotation(R);
         }
         else  if(   bal < -1 && a < R->right->d) // case 4 : RL
         {
               //    x     RightRotation og z with respect to y   x
               //      y  -->                                        z
               //    z                                                  y
                  RightRotation(R->right);
              LeftRotation(R);

	 }
     R->bal=getbalance(R);
    }
};


template <class type>
class Splay :public Bst<type>
{
#ifdef __GNUC__
    typedef node<type>* Node;
#endif
public:
    
  
    Splay():Bst<type>()
    {
        
    }
    
    void printRoot()
    {
        if(Bst<type>::root!=NULL)
            cout << "Root :" <<Bst<type>::root->d<<endl;
        
        }
    void Splays( Stack<Node>& S,Node x)
    {
         Node G=NULL;
         Node P;
        while(!S.isempty())
        {
            G=NULL;
           
            P=S.pop();
            if(!S.isempty())
                G=S.pop();
            if(G==NULL)
            {
                if(P->left==x)
                {  x=ZagorZig(P,x); // zig 
                    }
                else 
                {   x=ZagorZig(P,x);//zag
                    }
            }
            else
            {
                if(G->left==P)
                {
                    if(P->left==x)
                    {   P=ZagorZig(G,P);  //zig
                        x=ZagorZig(P,x);  //zig
                                          //                  G                                 x
                                          //              P     A  ---->         P      -->   D     P
                                          //           x    B                x      G            C     G
                                          //         D  C                   D  C   B A               B   A
                    }
                    else
                    {
                        G->left=ZagorZig(P,x); //zag
                        x=ZagorZig(G,x); //zig
                                        //               G                 G
                                        //             P   A   -->       X  A  -->     X  
                                        //           B   X             P   D         P   G
                                        //             C   D          B C           B C D A
                    }
                }
                else
                {
                     if(P->left==x)
                    {   
                        G->right=ZagorZig(P,x);
                        x=ZagorZig(G,x);
                    }
                    else
                    {
                        P=ZagorZig(G,P);
                        x=ZagorZig(P,x);
                        }
                    
                    }
            
            }
            
            P=S.Top();
            if(P!=NULL)
            {
                
                if(P->d > x->d)                    
                    P->left=x;
                else P->right=x;   

                }
            else Bst<type>::root=x;
            
        }
    }
      void insert(type a)
    {   Bst<type>::count++;
        Stack<Node>  S;
        Node temp=Bst<type>::root;
        if(temp==NULL)
        {
            Bst<type>::root=new node<type>(a);
            return;
            }
        while(temp!=NULL)
        {
            if(temp->d==a) return;
            else if(a < temp->d) 
                {   S.push(temp);
                    temp=temp->left;
                }
            else 
                {   S.push(temp);
                    temp=temp->right;
                }
        }
        temp=S.Top();
        Node x=NULL;
        if( a < temp->d) x=temp->left=new node<type>(a);
        else x=temp->right=new node<type>(a);
        
        Splays(S,x);
        
    }
    
    /*
    void Remove(type a)
    {
        Stack<Node>  S;
        Node temp=Bst<type>::root;
         if(temp==NULL)
        {
            return;
            } 
            
        while(temp!=NULL)
        {
            if(temp->d==a) break;
            else if(a < temp->d) 
                {   S.push(temp);
                    temp=temp->left;
                }
            else 
                {   S.push(temp);
                    temp=temp->right;
                }
        }
        Node x=temp;
        temp=S.Top();
        if(temp==NULL && x!=NULL) 
            {   delete x;
                Bst<type>::root=NULL; 
            }
        else
            {
                
             Bst<type>::root=Bst<type>::deleteNode(Bst<type>::root,a);   
              temp=S.pop();
              Splays(S,temp);  
            }
        
        Bst<type>::count--;
        }
  */
protected:
        
        Node ZagorZig(Node P,Node x)
        {
            if(P->left==x)
            {   
                //          P           X
                //      X    C  --->  A     P
                //     A  B                B   C
                Node B=x->right;
                     x->right=P;
                     P->left=B;
                }
            else
                {
                //    P             x
                //  A    x  -->  P    C
                //      B C     A  B
                
                Node B=x->left;
                    P->right=B;
                    x->left=P;
                }
            
                return x;
            }
        
        
 
};


template <class type>
class red_black :public Bst<type>
{
   /*
    * Properties of red black trees:
    * 
    *   1: A node is coloured either red or black
    *   2: The root node is black 
    *   3: All leaves are black
    *   4: A red Node must have only black children.(The red Rule)
    *   5:  The Number of black nodes along any path from a given node
            to the leaf must be the same.In other words the black height
            of a node must be same.The uniform number of black nodes from 
            root to the leafs is called as black height of the red black tree.
            
    */
protected:
     typedef node<type>* Node;
#define red true
#define black false

    Node currently_inserted;
public:
      red_black():Bst<type>(){
          currently_inserted=NULL;
          }
      
       void insert(type a)
       {
           
            Bst<type>::count++;
            Bst<type>::root =insertNode_parent(Bst<type>::root,a);
            
         
               /*
              * Algorithm: insertion
              * 1: A new node is inserted by following the bst insert routine
              *      # with track of parent and 
              *      # the newly inserted node is colored red.
              *  call insert_case1()
              */ 
            insert_case1(currently_inserted);
  //insert_case1():
            /*
            * case 1: 
            *  if node is root then change its color to black
            *          else insert_case2()
            *  
            * */
  //insert_case2():
           /* case 2:
            *     If inserted node's parent is red and uncle is red:
            *         then recolor inserted node's parent ,uncle and grand parent ; 
            *         call insert_case1(grandparent)
            *         end;
            *     else : insert_case3()
              */  
  //insert_case3()
               /* case 3: 
              *     
              *         if ( inserted node is left child of right child) :
              *         then  right rotate inserted node with parent   (zig rotation)
              *         else if( inserted node is right child of left child )  :          
              *         then  left rotate inserted node with parent    (zag rotation)
              *          
              *     insert_case4()
              *         
              */
//insert_case4()
              /* 
               *case 4:
               *       recolor and rotate accordingly
               **/  
            
        }

       void Display_inorder()

        { 
            inorderDisplay(Bst<type>::root);
           }
         void print()
         {
              Node ar[10000];
              Node LevelChange=new node<type>(0);
              int front=0,back=0;
              int level_count=2;
              int curlevel_count=2;
              int node_count=0;
              if(Bst<type>::root==NULL) return;
              
              ar[back++]=Bst<type>::root;
              node_count++;
              ar[back++]=LevelChange;
              while(front < back)
              {
                  if(ar[front]==LevelChange)
                      { 
                          while(curlevel_count--)   ar[back++]=NULL;
                          
                          
                          ar[back++]=LevelChange;
                      }
                   else if(ar[front]!=NULL)
                      {     if(ar[front]->left!=NULL) node_count++;    
                            ar[back++]=ar[front]->left;
                            if(ar[front]->right!=NULL) node_count++;   
                            ar[back++]=ar[front]->right;
                            curlevel_count-=2;
                      }
                    else 
                    {   ar[back++]=NULL;
                        ar[back++]=NULL;
                        curlevel_count-=2;
                        }
                    
                    if(curlevel_count<=0 && node_count == Bst<type>::count )  
                    break;
                    
                    if(curlevel_count<=0 && ar[front]==LevelChange) 
                        {   level_count=2*level_count;
                            curlevel_count=level_count;}
                front++;
                }
             
              front=0;
              int levelone=0;
              char space[4]="   ",blank[4]="_b_";
              int leftside=level_count-1;
              int rightside=level_count-1;
              while(front<back)
              {   if(levelone>=2) rightside=(rightside+1)/2-1;   
                  int l=leftside,r=rightside;
                  while(l--) cout << space;
                  while(front < back && ar[front]!=LevelChange)
                    {   if( ar[front]!=NULL) 
                          cout << ((ar[front]->color==red)?'r':'b') << ar[front]->d ;
                        else cout << blank ;
                        
                        while(r--) cout << space;
                            r=rightside;
                        front++;
                    }
                                     
                    cout << endl;
                    leftside=(leftside+1)/2-1;
                    levelone++;
                    front++;
              }
                  
         delete LevelChange;
        }
                
             
           
          void remove(type a)
          { 
            Node temp=Search_tree(Bst<type>::root,a); // The function Search_tree is inherited from the 
            // the Bst class and it is used to search a node with value a;
            if(temp==NULL) return; //We return back from the remove function if the node is not found.
            
            if(temp->left!=NULL && temp->right!=NULL) 
            //Case to check for a internal node:  
            {
                Node replace=Bst<type>::minfind(temp->right);//We take the inorder succesor
                temp->d=replace->d;//replace the node to be deleted with the inorder succesor 
                temp=replace; // then delete the inorder succesor
            }
            
            //Case to check for a leaf node
            
            if(temp->color==red) /* if the color of node to be deleted is red,
             * then it is a node with no children 
             * due to the black rule (if it had one black child then it would break the black rule) */
             {
                 //We just delete the temp node and we are done
                 if(temp==temp->parent->left) temp->parent->left=NULL; 
                 else temp->parent->right=NULL; 
                 delete temp;
                 Bst<type>::count--;
                 return;
              }
              else /*
               * if the color of the node to be deleted is black
               *    then it can have a single red child alone 
               *    or it has no children
               * */
              {    
                Node C=(temp->left==NULL)? temp->right:temp->left;
                if(C!=NULL) //a red child is there
                {
                     temp->d=C->d;   
                     if(temp->left==C)
                           temp->left=NULL;
                     else temp->right=NULL;
                    delete C;
                    Bst<type>::count--;
                }
                else // deleting a node with no children
                {
                   delete_case1(temp);
                    /* Let the node to be deleted be N
                     * Let the parent of N be P
                     * Let the Sibiling of N be S
                     * Let the left and right subtrees of S be Sl and Sr
                     * Step1: if N is the root node then
                     *              goto step 7
                     * Step2: if S is  red coloured then
                     *          first recolor S and P
                     *          second rotate S to make it Parent of P
                     *                if S is left child of P
                     *                      then rotate P right
                     *                 else rotate P left
                     * 
                     * Step3: if P,S,Sl and Sr are black coloured then
                     *          repaint S
                     *          set N->P and go to step1 
                     *          
                     * Step4: if P is red and S ,its children are black then
                     *          color s as red
                     *          color p as black
                     *          goto step 7
                     * Step5: if S is black , Sl is red and Sr is black then
                     *              refer wiki
                     * Step6: if S is black , Sr is red and Sl is black then
                     *               refer wiki
                     * Step7: delete temp 
                     *  
                     * */
                        if(temp->parent==NULL) Bst<type>::root=NULL;
                        else if(temp==temp->parent->left) temp->parent->left=NULL; 
                        else temp->parent->right=NULL; 
                        delete temp;
                        Bst<type>::count--;
                }
                  
              }
          
          }
          

protected:
        Node Search_tree(Node R,type a)
	{
	     if(R==NULL) return R;
	     else if(R->d==a) return R;
	     else if(R->d > a) return Search_tree(R->left,a);
	     else return Search_tree(R->right,a);
	}
         Node grandparent(Node n)
       {
           if(n!=NULL && n->parent!=NULL)
                return n->parent->parent;
           else return NULL;
        }
      
        Node uncle(Node n)
        {
            if(n!=NULL && n->parent!=NULL)
            {
               Node g=grandparent(n);
               if(g==NULL) return NULL;
               else if(g->left==n->parent) return g->right;
               else return g->left;
             }
            else return NULL;
        }
        Node sibiling(Node n)
        {
            if(n->parent!=NULL )
                return (n->parent->left==n)?n->parent->right:n->parent->left;
            else return NULL;
        }
        
        Node insertNode_parent(Node temp,type a)
        {
             /*
              * Algorithm: insertion
              * 1: A new node is inserted by following the bst insert routine
              *      # with track of parent and 
              *      # the newly inserted node is colored red.
              *  call insert_case1()
              */ 
            if(temp==NULL) return currently_inserted=new node<type>(a); 
            else if(temp->d > a) {
                temp->left=insertNode_parent(temp->left,a);
                temp->left->parent=temp;
                }
            else {
                temp->right=insertNode_parent(temp->right,a);
                temp->right->parent=temp;
                }
            return temp;
        }
        void insert_case1(Node temp)
        {/*
         * case 1: 
         *  if node is root then change its color to black
         *          else insert_case2()
         *  
         * */
            if(temp==Bst<type>::root )  
                temp->color=black;
                
            else insert_case2(temp);    
            }
         void insert_case2(Node temp)
        {  
            /*case 2:
            *  if nodes parent is black :
                    end
                else case 3:
             * */
            if(temp->parent->color==black)
            ;//no rule broken    
            else insert_case3(temp); 
         }
        void insert_case3(Node temp)
        {
            
            
             /* 3: case 3:
              *     If inserted node's parent is red and uncle is red:
              *         then recolor inserted node's parent ,uncle and grand parent ; 
              *         insert_case1(g)    
              *         end;
              *     else : case 4:
              */
              Node g=grandparent(temp);
              Node u=uncle(temp);
              if(u!=NULL && u->color==red )
              {
                 u->color=temp->parent->color=black;
                 g->color=red;
                 insert_case1(g);
              }
              else insert_case4(temp);   
            
        }
        Node RightRotation(Node k2)
        { /*       k2                 
                k1   C    --->      K1  
              A   B               A      K2
                                       B     c
              */
              if(k2==NULL) return NULL;
              Node k1=k2->left;
              if(k1!=NULL)
              {
              
                  
                  Node B=k1->right;
                  
                  k2->left=B;
                  if(B!=NULL)
                    B->parent=k2;
                  k1->right=k2;
                  k1->parent=k2->parent;
                  k2->parent=k1;  
                  
               }
              return k1;
        }
        Node LeftRotation(Node k1)
         {   //     k1                 k2
            //   T1   k2     -->   k1       T3
            //       T2  T3     T1   T2
              if(k1==NULL) return NULL;;
              Node k2=k1->right;
              if(k2!=NULL)
              {
                  Node T2=k2->left;
                  
                  k1->right=T2;
                  if(T2!=NULL)
                    T2->parent=k1;
                  k2->left=k1;
                  k2->parent=k1->parent;
                  k1->parent=k2;  
               }
              return k2;
        }
            
        
        
        void insert_case4(Node temp)
        {
               /* case 3: 
              *     
              *         if ( inserted node is left child of right child) :
              *         then  
              *               move the inserted node to the parent postion 
                              without breaking binary constraint and take care to prevent loss of any node.     
              *               (right rotate inserted node with parent) 
              *               It equivalent to zig rotation of splay tree.
              *         else if( inserted node is right child of left child )  :          
              *         then  
              *             move the inserted node to the parent postion 
                            without breaking binary constraint and take care to prevent loss of any node.     
              *             (left rotate inserted node with parent) 
              *             It equivalent to zag rotation of splay tree.
              *          
              *     insert_case5()
              *         
              */
              Node g=grandparent(temp);
              Node parent=temp->parent;
               if ( g!=NULL )
               {
                   
                   if( parent->left == temp &&  g->right == parent)
                   {
                     parent=g->right=RightRotation(g->right);
                     insert_case5(parent->right);
                    }
                    else if(parent->right==temp && g->left == parent)
                    {
                     parent=g->left=LeftRotation(g->left);
                     insert_case5(parent->left);
                    }
                     else insert_case5(temp);
                } 
        }
        
        
        void insert_case5(Node temp)
        {   /*
         * insert_Case4():
         *              
         * 
         * 
         *  rotate  right g for  ll 
         *  rotate  left  g for rr 
         *  
         *  and recolor respectfully
         * 
         * 
         * 
         * */
            Node g=grandparent(temp);
            Node parent=temp->parent;
            Node T;
            temp->parent->color = black;
             g->color = red;
             if(g->parent!=NULL) 
             {   if( g==g->parent->left)
                    g->parent->left=RightRotation(g);
                  else 
                    g->parent->right=LeftRotation(g);
             }
             else  
             {
                if (temp == temp->parent->left)
                Bst<type>::root=RightRotation(g);
                else
                Bst<type>::root=LeftRotation(g);
             }
            
        }
    void inorderDisplay(Node T)
    {
        if(T==NULL) return;
        inorderDisplay(T->left);
        if(T->color==red)
            cout << "(red)" << T->d << " ";
        else cout << "(black)" << T->d << " ";
        inorderDisplay(T->right);
        }
    
         void delete_case1(Node n) // Check if node is a root
         {
             if(n->parent!=NULL) 
                delete_case2(n);
        }
         void delete_case2(Node n) //Remove S's red color
        {   //tested
            Node s=sibiling(n);
            Node p=n->parent;
            if(s!=NULL && s->color==red)
            {
                s->color=black;
                p->color=red;
                
                if(s==p->left)
                    {   if(p->parent==NULL) Bst<type>::root=RightRotation(p);
                        else s->right=RightRotation(p);
                    }
                else {
                     if(p->parent==NULL) Bst<type>::root=LeftRotation(p);
                    else s->left=LeftRotation(p);
                }
            }
             delete_case3(n);
        }
         void delete_case3(Node n) //tested
        {    Node s=sibiling(n);
             Node p=n->parent;
             bool condition=( s->color==black);
             condition = condition &&  (s->left==NULL || s->left->color==black);
             condition = condition &&  (s->right==NULL || s->right->color==black);
             condition = condition && (p->color == black) ;
             if(condition)
             {
                s->color=red; 
                insert_case1(p); 
             }
             else 
               delete_case4(n);  
        }
         void delete_case4(Node n) // tested
         {   //tested
             Node s=sibiling(n);
             Node p=n->parent;
             bool condition=( s->color==black);
             condition = condition &&  (s->left==NULL || s->left->color==black);
             condition = condition &&  (s->right==NULL || s->right->color==black);
             condition = condition && (p->color == red) ;
             if(condition)
             {
              s->color=red;
              p->color=black;
             }
             else delete_case5(n);
        }
         void delete_case5(Node n) //tested
        {
             Node s=sibiling(n);
             Node p=n->parent;
             if(n==p->left && 
               (s->left!=NULL && s->left->color==red) && 
               (s->right==NULL || s->right->color==black  ) )
             {
                 s->color=red;
                 s->left->color=black;
                 p->right=RightRotation(s);
             }
             else if( n==p->right && 
                    (s->right!=NULL && s->right->color==red) && 
                    (s->left==NULL || s->left->color==black  )) 
             {
                 s->color=red;
                 s->right->color=black;
                 p->left=LeftRotation(s);
             }
             delete_case6(n);
        } 
         void delete_case6(Node n) //tested
        {    //tested
             Node s=sibiling(n);
             Node p=n->parent;
             s->color=p->color;
             p->color=black;
             if(n==p->left)
             {
                 s->right->color=black;
                 if(p->parent==NULL)
                  Bst<type>::root=LeftRotation(p);
                 else  
                     {  Node g=p->parent;
                        if(p==g->right)
                         g->right=LeftRotation(p);
                        else g->left=LeftRotation(p);
                     }
                     
             }
             else 
             {  if(s->left!=NULL)
                 s->left->color=black;
                  if(p->parent==NULL)
                  Bst<type>::root=RightRotation(p);
                  else {
                        Node g=p->parent;
                        if(p==g->right)
                         g->right=RightRotation(p);
                        else g->left=RightRotation(p);
                  }
             }
        }
    };
template <class coordinate_type>
class interval
{
public:
    coordinate_type * values;
    int no_of_coordinates; 
    interval()
    {
        values=NULL;
        no_of_coordinates=0;
    }
    interval(int no,coordinate_type* a)
    {   no_of_coordinates=no;
        values=new coordinate_type[no];
        for(int i=0;i<no;i++)
                values[i]=a[i];
    }
    ~interval()
    {
        if(values) delete values;
    }
    
    
};

template <class type>
class Interval_tree_Node
{  
   public: 
   type centre;
   int interior_no_of_intervals;
   Interval_tree_Node<type>* left,*right;      
   type* beginpoints;
   type* endpoints; 
   Interval_tree_Node():centre()
   {   left=right=NULL ;
       beginpoints=endpoints=NULL;
       interior_no_of_intervals=0;
   }
   Interval_tree_Node(type c,
    Interval_tree_Node<type>* l=NULL,
    Interval_tree_Node<type>* r=NULL,
    type * b=NULL,
    type * e=NULL,
    int no=0):centre(c)
   {   interior_no_of_intervals=no;
       left=l;
       right=r;
       beginpoints=new type[no];
       endpoints=new type[no];
       for(int i=0;i<no;i++)
           beginpoints[i]=b[i],endpoints[i]=e[i];
    }
};
int test_red_black_trees()
{
    int i;
    clock_t t=clock();

    int k;

	red_black<int> mytree;


		mytree.insert(5);
        mytree.insert(9);
        mytree.insert(4);
        mytree.insert(98);
        mytree.insert(1);
        
        mytree.remove(1);
        mytree.print();
	cout << endl;
    

    
    cout << endl <<   "Execution Time of test for red black trees is  :" ;
    #ifndef __GNUC__ 
	cout.flags(ios::fixed|ios::showpoint);
    #endif
	cout <<  setprecision(10) <<   (double(clock()-t)/CLOCKS_PER_SEC) <<endl;
    

	return 0;
    
    
    
    }
 void testavl()
 {
     AVL<int> t;
    for(int i=1;i<=10;i++)
  {   cout << "Inserting " << i << endl;
      t.insert(i);
      t.print();
      cout << endl;
  }
    for(int i=10;i>=1;i--)
        {   cout << "Deleting " << i << endl;
      t.Remove(i);
      t.print();
      cout << endl;
  }
    }


 int main()
 {  
     cout << "Testing red black trees" << endl;
    test_red_black_trees();
    //testavl();
	return 0;
 }