/*This is base class (Composition)
* It saved Personal Information of USM staff: Name, Staff ID, Gender.
*/
//------HEADER---------
#include <iostream>
using namespace std;
/*******************************************************************************
this class have string dataType. It resides in namespace std, the namespace 
in which all of the C++ standard library functions, classes, and objects reside
********************************************************************************/  
class personalInfo{ //Base class (Inheritance)
	protected:
		string name;
		long long int staffID;
		string gender;
	public:
		void setInfo(string,long long int,string);
		personalInfo(){name=gender="";staffID=0;}	//constructor
		~personalInfo(){name=gender="";staffID=0;;}	//destructor	
};
void personalInfo::setInfo(string namE,long long int id,string gendeR){
	name=namE;
	staffID=id;
	gender=gendeR;
}
