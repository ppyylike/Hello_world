#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#define Elm int
using namespace std;
typedef struct BiNode *PtrNode;
typedef struct BiNode *Bitree;
struct BiNode{
	Elm data;
	BiNode* lcd,*rcd;
};
void Intial_BiTree(Bitree &bt){
	BiNode *temp=new BiNode;
	temp->data=0;
	temp->lcd=NULL;
	temp->rcd=NULL;
	bt=temp;
}
void Insert_Bitree(Elm e,Bitree &bt){
	BiNode *temp=new BiNode;
	BiNode *pt=bt->lcd;
	temp->data=e;
	temp->lcd=NULL;
	temp->rcd=NULL;
	if(bt->lcd==NULL){
		bt->lcd=temp;
		bt->data++;
	}
	else{
		while(pt->data>temp->data&&pt->lcd!=NULL){
			pt=pt->lcd;
		}
		while(pt->data<=temp->data&&pt->rcd!=NULL){
			pt=pt->rcd;
		}
		if(pt->data>=temp->data)pt->lcd=temp;
		else pt->rcd=temp;
		bt->data++;
	}
	
}
int main(){
	Bitree NewBiTree;
	Elm i=0;size_t t=0;
	Intial_BiTree(NewBiTree);
	vector<Elm> vi;
	while(i!=20){
		vi.push_back(rand()%50);
		i++;
	}
	while(t!=vi.size()){
		Insert_Bitree(vi[t],NewBiTree);
		t++;
	}
	cout<<NewBiTree->data<<endl;
	cout<<NewBiTree->lcd->data<<endl;
	cout<<"elements of Binary tree is: "<<NewBiTree->data<<endl;
	return 0;
}
