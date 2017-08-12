#include<bits/stdc++.h>

using namespace std;

#define pb push_back()
#define mod 1000000007LL
#define ll long long 
#define eps 1e-10
#define inf 1e6
#define f first 
#define s second

struct seg{
    int l, h;
};

struct interval{
    seg *s;
    int max;
    interval *left, *right, *parent;
};

seg *newseg(int l, int h){
    seg *s = new seg();
    s->l = l;
    s->h = h;
    return s;
}

class Tree{
private :
    interval *root;

public:
    Tree(seg *s){
        root = new interval();
        root->s = s;
        root->max = max(s->l, s->h);
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
    
    interval* createnode(seg *s){
        interval *node = new interval();
        node->s = s;
        node->max = max(s->l, s->h);
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    void insert(seg *s){
        interval *current = createnode(s);
        insertinterval(root, current);
    }

    void insertinterval(interval *root, interval *current){
        if (!this->root){
            this->root = current;
            this->root->parent = NULL;
        }else{
            root->max = max(root->max, current->max);   
            if (current->s->l < root->s->l){
            
                if (!root->left){
                    root->left = current;
                    current->parent = root;
                }else{
                    insertinterval(root->left, current);
                }
            }else{
                if(!root->right){
                    root->right = current;
                    current->parent = root;
                }else{
                    insertinterval(root->right, current);
                }
            }
        }
    }

    bool find(seg *s1, seg *s2){
        if (s1->l == s2->l && s1->h == s2->h)
            return true;
        else    
            return false;
    }



    bool isLeftChild(interval *t){
        if (t->parent->left == t)
            return true;
        else        
            return false;
    }
    
    void deletenode(seg *s){
        deletenode(root, s);
    }
    void deletenode(interval *root, seg *s){
        if(!root){
            cout<<"No such interval exists"<<endl;
            return;
        }

        if (find(root->s, s)){
            
            if (root->right){
                interval *rep = root;
                interval *temp = root->right;
                while(temp){
                    rep = temp;
                    temp = temp->left;
                }
                if (isLeftChild(rep)){
                    rep->parent->left = rep->right;
                    if (rep->right) rep->right->parent = rep->parent;
                }else{
                    rep->parent->right = rep->right;
                    if (rep->right) rep->right->parent = rep->parent;
                } 
            
                temp = rep->parent;
                while(temp!=root){
                    if (temp->left) temp->max = root->left->max;
                    if (temp->right) temp->max = max(root->max, root->right->max);
                    temp = temp->parent;
                }
            
                root->s = rep->s;
                root->max = rep->max;
                if (root->left) root->max = max(root->max, root->left->max);
                if (root->right) root->max = max(root->max, root->right->max);
            }else{
                if (isLeftChild(root)){
                    root->parent->left = root->left;
                    if (root->left) root->left->parent = root->parent;
                }else{
                    root->parent->right = root->left;
                    if (root->left) root->left->parent = root->parent;
                } 
            }

            interval *temp = root->parent;
            while(temp != NULL){
                temp->max = temp->s->h;
                if (temp->left) temp->max = max(temp->left->max, temp->max);
                if (temp->right) temp->max = max(temp->right->max, temp->max);
                temp = temp->parent;
            }

        }else{
            if (s->l < root->s->l)
                deletenode(root->left, s);
            else deletenode(root->right, s);
        }

    }

    bool doOverlap(seg *s1, seg *s2){
        if (s1->h < s2->l || s1->l > s2->h)
            return false;
        else        
            return true;
    }
        seg* searchOverlap(seg *i){
        return searchOverlap(root, i);
    }
   

    seg* searchOverlap(interval *root, seg *s){
        if (!root)
            return NULL;

        if (doOverlap(root->s, s))
            return root->s;

        if (root->left && s->l <= root->left->max)
            return searchOverlap(root->left, s);
        else return searchOverlap(root->right, s);
    }
};
int main(){
    Tree IT(newseg(15,20));
    seg ints[] = {{15,20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {16, 40}
    };
    
    
    for (int i = 0; i < 6; i++)
        IT.insert(newseg(ints[i].l, ints[i].h));

    seg *match = IT.searchOverlap(newseg(14, 19));
    if(match)
        cout<<"Overlaps with ("<<match->l<<","<<match->h<<")"<<endl;
    else cout<<"No Overlap";

    match = IT.searchOverlap(newseg(21, 23));
    if(match)
        cout<<"Overlaps with ("<<match->l<<","<<match->h<<")"<<endl;
    else cout<<"No Overlap";    

    return 0;
}
