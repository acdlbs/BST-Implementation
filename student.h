//
//  student.h
//  
//
//  Created by Resch,Cheryl on 5/15/19.
//

#ifndef student_h
#define student_h

/***** added by Shashank Ranjan *****/
#include <string>
using namespace std;
/***********************************/

class student {
    
public:
	/***** added by Shashank Ranjan *****/
	student();
	/***********************************/
    student(string name, int uniqueID, float GPA);
    ~student();
    void printStudent() ;
    string getName();
    float getGPA();
    bool operator<(student rhs);
    bool operator>(student rhs);
    bool operator==(student rhs);

private:
std::string name;
    int uniqueID;
    float GPA;
};
#endif /* student_h */
