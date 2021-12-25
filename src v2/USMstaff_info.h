/* This is the derived class.
*  It combines two classes. (Inheritance: personalInfo. Composition: fitnessInfo)
*  This class is mostly used for calculation and display the data.
*  Calculation: BMI,BMR,RMR,Age.
*  Display: Data from personalInfo's class and fitnessInfo's class, Category of BMI, Date of Birth.
*/
//------HEADER---------
#include <iostream>
#include <iomanip> //fixed pointer
using namespace std;
class USMstaff_info: public personalInfo{ //Derived class
	private:
		fitnessInfo fit; //composition from class fitnessInfo
		long long int temp=0;
		int identity[5] ={0};
		int j=100;
		int age;
		float bmi;
		float bmr;
		float rmr;
		string category;
		
	public:
		void setData_all(string,long long int,string,float,float);
		int calAge();
		void calDOB();
		float calBMI();
		string getCategory();
		float calBMR();
		float calRMR();
		string getName(){return name;}
		long long int getstaffID(){return staffID;}
		string getGender(){return gender;}
		float getWeight(){return fit.getWeight();}
		float getHeight(){return fit.getHeight();}
		void Display();
		USMstaff_info(){age=bmi=bmr=rmr=0;category="";}
		~USMstaff_info(){age=bmi=bmr=rmr=0;category="";}
		
		//-----FRIEND FUNCTION-------
		friend void combinationData(int &arraySize,USMstaff_info ob[]);
		friend void statistic(int &arraySize,USMstaff_info ob[]);
		friend void targetWeight(int &arraySize,USMstaff_info ob[]);
		friend void outputFile(int &arraySize,USMstaff_info ob[]);
};
//-------set ALL data-------
void USMstaff_info::setData_all(string namE,long long int id,string gendeR,float Weight,float Height){
	setInfo(namE,id,gendeR);
	fit.setFit(Weight,Height);
}
//-------Calculate Age using Staff ID-------
int USMstaff_info::calAge(){
	temp=staffID;
	age=0;
	
/*********************************************
split the staff ID into 2 digits in an array. 
example: 99 07 12 01 88 13
identity[2]= 01
**********************************************/
	for(int i=0; i<6; i++){
		identity[i] = temp%j;
		temp=temp/j;
	}
	if (identity[5]>0){
		identity[5]=1900+identity[5];
		age=2020-identity[5];							
	}
	return age;
}
//-------Calculate Date of Birth using Staff ID-------
void USMstaff_info::calDOB(){
	temp=staffID;

/*************************************************
	split the staff ID into 2 digits in an array.
	example: 99 07 12 01 88 13					 
	identity[5]= 99							     
**************************************************/	
	for(int i=0; i<6; i++){
		identity[i] = temp%j;
		temp=temp/j;
	}
	if (identity[5]>0){
		identity[5]=1900+identity[5];
		cout << "DOB: " << identity[3] <<"/"<< identity[4] <<"/"<< identity[5] << endl;
	}
}
//-------calculate BMI---------
float USMstaff_info::calBMI(){
	bmi=fit.getWeight()/((fit.getHeight()/100)*(fit.getHeight()/100));
	return bmi;
}
//-----Determine BMI category------
string USMstaff_info::getCategory(){
	if (bmi<20)
		category="underweight";
	else if (bmi>=20.0 && bmi<25.0)
		category="normal";
	else if (bmi>=25.0 && bmi<30.0)
		category="overweight";
	else if(bmi>=30.0)
		category="obese";
	return category;
}
//-------calculate BMR---------
float USMstaff_info::calBMR(){
	if(gender=="Male")
		bmr= 10 * fit.getWeight() + 6.25 * fit.getHeight() - 5 * age+ 5;
	else if(gender=="Female")
		bmr= 10 *  fit.getWeight()  + 6.25 *  fit.getHeight() - 5 * age - 161;
	return bmr;
}
//-------calculate RMR---------
float USMstaff_info::calRMR(){
	if(gender=="Male")
		rmr= 88.362 + (13.397 * fit.getWeight()) + (4.799 * fit.getHeight()) - (5.677 * age) ;
	else if(gender=="Female")
		rmr= 447.593 + (9.247 * fit.getWeight()) + (3.098 * fit.getHeight()) - (4.330 * age) ;
	return rmr;
}
//-------Display data-------
void USMstaff_info::Display(){ 
	cout.width(40);cout<<left<<name;
	cout.width(7);cout<<calAge();
	cout.width(10);cout<<gender;
	cout.width(8);cout<<staffID;
	cout<<fixed<<showpoint<<setprecision(2);
	cout.width(10);cout<<right<<fit.getWeight();
	cout.width(10);cout<<fit.getHeight();
	cout.width(10);cout<<calBMI();
	cout.width(15);cout<<getCategory();
	cout.width(10);cout<<calBMR();
	cout.width(10);cout<<calRMR()<<endl;
}
