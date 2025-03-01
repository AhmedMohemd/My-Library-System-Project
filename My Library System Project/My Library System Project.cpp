#include <iostream>
#include <string>
using namespace std;

const int numbook = 10;
int Id[numbook] = { 1, 22, 35, 46, 58 };
string Title[numbook] = { "World", "sky", "pepole", "life", "moon" };
string Author[numbook] = { "Ali", "Nourhan", "Mohamed", "Ahmed", "Malak" };
bool Available[numbook] = { true, true  , true, true, true };
int bookcount = 5;

void add(int id, string title, string author) {
	if (bookcount >= numbook) {
		cout << " num of books is full " << endl;
		return;
	}
	for (int i = 0; i < numbook; i++) {
		if (Id[i] == id) {
			cout << " there is Book with this id " << endl;
			return;
		}
	}
	for (int i = 0; i < numbook; i++) {
		if (Id[i] == 0) {
			Id[i] = id;
			Title[i] = title;
			Author[i] = author;
			Available[i] = true;
			bookcount++;
			cout << " you added a book successfully " << endl;
			return;
		}
	}
}
int sreach(int id) {
	for (int i = 0; i < numbook; i++) {
		if (Id[i] == id) {
			return i;
		}
	}
	return -1;
}
void remove(int id) {
	int numid = sreach(id);
	if (numid == -1) {
		cout << " The book not here " << endl;
		return;
	}
	for (int i = numid; i < numbook - 1; i++) {
		Id[i] = Id[i + 1];
		Title[i] = Title[i + 1];
		Author[i] = Author[i + 1];
		Available[i] = Available[i + 1];
	}
	bookcount--;
	cout << " the book removed successfully " << endl;
}
void update(int id, string newtitle, string newauthor) {
	int numid = sreach(id);
	if (numid == -1) {
		cout << " The book not here " << endl;
		return;
	}
	Title[numid] = newtitle;
	Author[numid] = newauthor;
	cout << " The book updated successfully " << endl;
}
void borrow(int id) {
	int numid = sreach(id);
	if (numid == -1) {
		cout << " The book not here " << endl;
		return;
	}
	if (!Available[numid]) {
		cout << " the book not available now " << endl;
		return;
	}
	Available[numid] = false;
	cout << " you borrowed the book successfully " << endl;
}
void retUrn(int id) {
	int numid = sreach(id);
	if (numid == -1) {
		cout << " The book not here " << endl;
		return;
	}
	if (Available[numid]) {
		cout << " the book here " << endl;
		return;
	}
	Available[numid] = true;
	cout << " you borrowed the book successfully " << endl;
}
void display() {
	cout << " The available books: " << endl;
	for (int i = 0; i < numbook; i++) {
		if (Id[i] != 0) {
			cout << " Id: " << Id[i] << "    ";
			cout << " Title: " << Title[i] << "    ";
			cout << " Author: " << Author[i] << "    ";
			cout << " Available: " << (Available[i] ? "Yes" : "No") << endl;
		}
	}
}
int main() {
	int id;
	string title, author;

	cout << " The mino of library " << endl;
	cout << " 1:Shwo the books: " << endl;
	cout << " 2:Borrow a book: " << endl;
	cout << " 3:Return a book: " << endl;
	cout << " 4:Add a book: " << endl;
	cout << " 5:Ubdate a book: " << endl;
	cout << " 6:Search of a book: " << endl;
	cout << " 7:Remove a book: " << endl;
	cout << " 8: If you need to go out: " << endl;

	int choice;
	while (true) {
		cout << " Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: display();
			break;
		case 2:cout << " Enter the Id of the book: " << endl;
			cin >> id;
			borrow(id);
			break;
		case 3:cout << " Enter the Id of the book: " << endl;
			cin >> id;
			retUrn(id);
			break;
		case 4:cout << " Enter the id: " << endl;
			cin >> id;
			cout << " Enter the Title: " << endl;
			getline(cin >> ws, title);
			cout << " Enter the Author: " << endl;
			getline(cin >> ws, author);
			add(id, title, author);
			break;
		case 5:cout << " Enter the id: " << endl;
			cin >> id;
			cout << " Enter the new Title: " << endl;
			getline(cin >> ws, title);
			cout << " Enter the new Author: " << endl;
			getline(cin >> ws, author);
			update(id, title, author);
			break;
		case 6: cout << " Enter the Id of the book: " << endl;
			cin >> id;
			if (sreach(id) != -1) {
				int info = sreach(id);
				cout << " The book exists in the library: " << endl;
				cout << " Id: " << Id[info] << "    ";
				cout << " Title: " << Title[info] << "    ";
				cout << " Author: " << Author[info] << "    ";
				cout << " Available: " << (Available[info] ? "Yes" : "No") << endl;
			}
			else
				cout << " The book not here " << endl;
			break;
		case 7:cout << " Enter the Id of the book: " << endl;
			cin >> id;
			remove(id);
			break;
		case 8:cout << " Good bay " << endl;
			return 0;
		default:
			cout << " your choice not found try again: ";
			break;
		}
	}
}