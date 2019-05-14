/*
Nama : Muhamad Farid Ridho Rambe
NPM : 140810180033
Deskripsi : Exercise 3
*/
#include <iostream>
using namespace std;

struct simpul{
	int info;
	simpul* left;
	simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void createSimpul(pointer& pBaru){
	pBaru=new simpul;
	cout<<"Masukkan simpul : ";cin>>pBaru->info;
	pBaru->left=NULL;
	pBaru->right=NULL;
}

void insertBST(tree& root,pointer pBaru){
	if(root==NULL){
		root=pBaru;
	}
	else if(pBaru->info<root->info){
		insertBST(root->left,pBaru);
	}
	else if(pBaru->info>root->info){
		insertBST(root->right,pBaru);
	}
	else{
		cout<<"sudah ada"<<endl;
	}
}

void preOrder(tree root){
	if(root!=NULL){
		cout<<root->info<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder (tree root) {
	if (root != NULL){
		inOrder(root->left);
		cout<< root->info <<" ";
		inOrder(root->right);
	}
}

void postOrder (tree root) {
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<< root->info <<" ";
	}
}

void notasiKurung(tree root){
	if(root!=NULL){
		cout<<"(";
		cout<<root->info<<" ";
		notasiKurung(root->left);
		notasiKurung(root->right);
		cout<<")";
	}
}

main(){
	pointer pb;
	tree t;
	int pil,n;\
	t=NULL;
	
	cout<<"Masukkan bayak simpul : ";cin>>n;
	
	for(int i=0;i<n;i++){
		createSimpul(pb);
		insertBST(t,pb);
	}	
	
	system("cls");
	
	cout<<"Tampilkan secara : "<<endl;
	cout<<"1.Pre Order \t2.In Order"<<endl;
	cout<<"3.Post Order\t4.Notasi Kurung"<<endl;
	cout<<"Pilihan : ";cin>>pil;
	
	if(pil==1){
		preOrder(t);
	}
	else if(pil==2){
		inOrder(t);
	}
	else if(pil==3){
		postOrder(t);
	}
	else if(pil==4){
		notasiKurung(t);
	}
	else{
		return 0;
	}
}
