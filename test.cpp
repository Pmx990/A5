#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

//#include "BinarySearchTree.h"
#include "temp.h"
#include "DataType.cpp"
using namespace std;


int main(){
	/*cout << "Loading the data..." << endl;
	//*********Check the ChooseRamNum.cpp file******************
	string rNum;
	string* ramNum = new string[1000];
	int count1 = 0;
	ifstream readFile2("100ram.txt");
	while (getline(readFile2, rNum)) {
		ramNum[count1] = rNum;
		//cout<<ramNum[count1]<<endl;
		count1++;
	}
	readFile2.close();*/
	//**********************************************************
	hashTable<string> table = hashTable<string>(1000);
	//HashTable<upc> table = HashTable<upc>;

	ifstream readFile("upc_test.txt");
	string temp2;
	string key;
	string value;
	long long int keyInt;
	int a = 0;
	while (getline(readFile, temp2)) {
		istringstream ss(temp2);

		getline(ss, key, ',');
		//read the data and insert them into the tree as type upc
		getline(ss, value, '\n');
		//upc temp(key, value);
		stringstream stream;
		stream<<key;
		stream>>keyInt;
		//keyInt = keyInt % 1000;
		//cout<<keyInt<<" ";
		stream.clear();
		table.insertItem(keyInt,value);

	}
	keyInt = 42187408163;
	cout<<keyInt<<endl;
	cout<<table.search(keyInt)<<endl;
	//cout<<table.find(temp3)<<endl;

	return 0;
}
/*
int main(){
	BinarySearchTree<int> tree;
	int x=10,y=4,t=23, k=7, m=1;
	int e = -1;
	tree.insert(x);
	tree.insert(y);
	tree.insert(t);
	tree.insert(k);
	tree.insert(m);
	cout<<"Tree Traversals:"<<endl;
	tree.printInOrder();
	cout<<endl;
	tree.printPreOrder();
	cout<<endl;
	tree.printPostOrder();
	cout<<endl;
	cout<<"Max:"<<tree.findMax(e)<<endl;
	cout<<"Min:"<<tree.findMin(e)<<endl;
	cout<<"Height:"<<tree.height()<<endl;
	tree.deletenode(x);
	tree.printInOrder();
	cout<<endl;
	cout<<"Search result(1/0):"<<tree.search(y);
}
*/
