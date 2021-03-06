#include <bits/stdc++.h>
using namespace std;

class node {
public:

	int data;
	node *left;
	node *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

bool search(node* root, int data) {

	//Base 
	if(root==NULL) {
		return false;
	}
	if(root->data==data) {
		return true;
	}

	//Rec 
	if(data<=root->data) {
		return search(root->left, data);
	} else {
		return search(root->right, data);
	}
}

node* insertInBst(node* root, int data) {

	if(root==NULL) {
		return new node(data);
	}

	if(data <= root->data) {
		root->left = insertInBst(root->left,data);
	} else {
		root->right = insertInBst(root->right,data);
	}
	return root;
}

node* build() {
	
	int d;
	cin>>d;

	node* root = NULL;
	while(d!=-1) {
		root = insertInBst(root, d);
		cin>>d;
	}
	return root;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	node* root = build();
	int data;
	cin>>data;

	if(search(root,data)) {
		cout<<data<<" is present";
	} else {
		cout<<data<<" is not present";
	}
	

	return 0;
}