//test case 1
#include "student.h"
#include "BST.h"
using namespace std;
int main()
{
	// insert
	BST<student> tree;
	student s1("Joe", 23, 4.0); // Changed by Shashank Ranjan, org: student s1 = new student("Joe", 23, 4.0);
	s1.printStudent();
	cout << endl;
    // Changed by Shashank Ranjan, added a new line to match the output
	tree.insert(s1);
	tree.printTree();
    cout << endl;
    //
	tree.insert(student("Snoopy", 1, 2.0)); // Changed by Shashank Ranjan to test insert with rvalue parameter, org: student s2 = new
	student s3("Charlie Brown", 2, 3.0); // Changed by Shashank Ranjan, org: student s3 = new student("Charlie Brown", 2, 3.0);
	tree.insert(s3);
	student s4("Lucy Brown", 372, 4.0); // Changed by Shashank Ranjan, org: student s4 = new student("Lucy Brown", 372, 4.0);
	tree.insert(s4);
	tree.printTree();
	cout << endl;
    //
	// fetch
	student temp = tree.getItem(23);
	temp.printStudent(); // Changed by Shashank Ranjan to fix the function call, org: temp.printStudent;
	cout << endl;
	temp = tree.getItem(3);
    temp.printStudent();
	cout << endl; // Changed by Shashank Ranjan, added a new line
    //

	// update: New test cases added by Shashank Ranjan
	temp = student("Snoopy", 1, 2.5);
	tree.update(temp);
	tree.printTree();
    //
	temp = student("Mary Brown", 372, 4.0);
	tree.update(temp);
	tree.printTree();
	cout <<endl;
    //
    

	//remove
	tree.remove(23); // 20 points
	tree.printTree();
	cout << endl;
    //
}
