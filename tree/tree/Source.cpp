#include <iostream>
using namespace std;

struct Node 
{
	int field;
	string word;
	struct Node* left;
	struct Node* right;
};

void menu()
{
	cout << "\n1-add, 2-del, 3-show, 4-delAll, 5-search,6-print levels, 0-end\n";
}

void add(Node*& tree, int x, string lol)
{
	if (tree == NULL)
	{
		Node* temp = new Node;
		temp->field = x;
		temp->word = lol;
		temp->left = NULL;
		temp->right = NULL;
		tree = temp;
		return;
	}
	else if (x < tree->field) add(tree->left, x,lol);
	else add(tree->right, x,lol);
}

void show(Node* tree, int lvl) // когда полностью очищаю дерево, выдает ошибку при выводе
{
	if (tree != NULL)
	{
		show(tree->right, ++lvl);
		for (int i = 0; i < lvl; ++i) cout << "  ";
		cout << tree->field << "(" << tree->word << ")" << '\n';
		show(tree->left, ++lvl);
		lvl--;
	}
}

Node* del(Node* tree, int key)
{
	Node* d, * pd, * r, * pr; // d-удаляемый,pd-предыдущий от удал,r-элемент замещающий,pr- предыдущий от замещающего
	d = tree;
	pd = NULL;
	while (d != NULL && d->field != key)
	{
		pd = d;
		if (d->field > key) d = d->left;
		else d = d->right;
	}
	if (d == NULL)
	{
		cout << "net :)";
		return tree;
	}
	if (d->right == NULL) r = d->left;
	else if (d->left == NULL) r = d->right;
	else
	{
		pr = d;
		r = d->left;
		while (r->right != NULL)
		{
			pr = r;
			r = r->right;
		}
		if (pr == d) r->right = d->right;
		else
		{
			r->right = d->right;
			pr->right = r->left;
			r->left = pr;
		}
	}
	if (d == r) tree = r;
	else if (d->field < pd->field) pd->left = r;
		 else pd->right = r;
	int tmp = d->field;
	cout << "del el with key " << tmp << '\n';
	delete d;
	return tree;
}
void delAll(Node*& tree)
{
	if (!tree) return;
	delAll(tree->left);
	delAll(tree->right);
	tree = NULL;
	return;
}
Node* search(Node* tree, int key)
{
	Node* temp = tree;
	if (temp != NULL)
	{
		if (key < (key, temp->field)) temp = search(temp->left, key);
		else if (key > (key, temp->field)) temp = search(temp->right, key);
		
	}
	else cout << "net :)\n";
	return temp;
	
}
void print_lvl(Node* tree) //неправильно обходит
{
	Node* temp = tree;
	if (temp != NULL)
	{
		cout << temp->field<< "(" << tree->word << ")" <<'\n';
		if (temp->left) print_lvl(temp->left);
		if (temp->right) print_lvl(temp->right);
	}
}
int main()
{
	string ans;
	int key;
	string lol;
	Node* tmp;
	Node* tree = nullptr;
	int x;
	do
	{
		menu();
		cin >> ans;
		if (ans == "1")
		{
			cout << "write key ";
			cin >> x;
			cout << "write word ";
			cin >> lol;
			add(tree, x,lol);
		}
		else if (ans == "2")
		{
			cout << "write key ";
			cin >> key;
			tree = del(tree, key);
		}
		else if (ans == "3") show(tree, 0);
		else if (ans == "4") delAll(tree);
		else if (ans == "5")
		{
			cout << "write key ";
			cin >> key;
			tmp=search(tree, key);
			if(tmp!=NULL)
			cout << "look " << tmp->word;
		}
		else if (ans == "6")
		{
			print_lvl(tree);
		}
		else if (ans == "0") break;
		else cout << "incorrect answer\n";
	} while (true);
}

