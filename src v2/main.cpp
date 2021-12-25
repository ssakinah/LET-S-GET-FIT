/* Name: Siti Sakinah Binti Ahmad Sanusi
*  Date Update: 7/4/2020
*  Purpose of the program: A program that design for fitness track of USM staff.
*							- by using the program, the user can saved the personal Information and Fitness Information.
*							- it can calculate bmi(also shows the category of bmi), bmr and rmr
*							- it can show the statistic of USM staff BMI category
*							- it can helps the user to get their desire weight (gain/loss) by sowing the calorie consuming one can take a day.
*/
//------HEADER---------
#include<iostream> 		      //input output
#include"personalInfo.h"     //base class: inheritance
#include"fitnessInfo.h"     //base class: composition
#include"USMstaff_info.h"  //derived class
using namespace std; 	  //cin, cout
#include<fstream>		 //for read textfile
#include<string> 		//textfile also
#include<windows.h>    //feature that available in windows e.g. system("pause");
#include <iomanip> 	  //fixed pointer,width
//--------Function Prototype----------------
void menureadData();
void menuOthers();
void exit(); 
void readData(int&,USMstaff_info[]);
void addData(int&,USMstaff_info[]);
void displayData(int&,USMstaff_info[]);
void modifyData(int&,USMstaff_info[]);
void searchData(int&,USMstaff_info[]);
//-----friend function---------------
void combinationData(int&,USMstaff_info[]); 
void statistic(int&,USMstaff_info[]);
void outputFile(int&,USMstaff_info[]);
void targetWeight(int&,USMstaff_info[]);
//------------Main Function----------------
int main(){
	int arraySize=0,option;
	USMstaff_info ob[500];//object declaration
	char proceed;
	//note: have two menu function because want to rid of read Data function. (The user need to read Data once)
	//want to avoid logic error
	
	do{
		menureadData(); 
		cin>>proceed;
		switch(proceed){
			case 'Y': //Read data from 2 textfile
					readData(arraySize,ob);
					cout<<"\t\t\t  Data is reading..............."<<endl;
					system("pause");
					break;
			default: //ask user to enter the right option if they enter input that are not in the menu screen	
					cout <<"\t\t\t Choice not valid.....Enter again\n";
					system("pause");
					 break;		
		}
	}while (proceed!='Y');//program will always loop until option 'Y' entered
	
	do{
		menuOthers();
		cin>>option;
		switch(option){	
			case 1:	//Display the data
					displayData(arraySize,ob);
					system("pause");
					break;
			case 2: //Add data
					addData(arraySize,ob);
					system("pause");
					break;
			case 3: //Modify data
					modifyData(arraySize,ob);
					system("pause");
					break;
			case 4: //Search data
					searchData(arraySize,ob);
					system("pause");
					break;
			case 5: //Combinational search
					combinationData(arraySize,ob);
					system("pause");
					break;
			case 6: //Statistic
					statistic(arraySize,ob);
					system("pause");
					break;
			case 7://Target weight
					targetWeight(arraySize,ob);
					system("pause");
					break;
			case 8: //Produce output file
					outputFile(arraySize,ob);
					system("pause");
					break;
			case 9: //Exit program when user enter this option
					option=9;
					system("CLS");
					exit();
					system("pause");
					break;
			default: //ask user to enter the right option if they enter input that are not in the menu screen	
					cout <<"\t\t\t Choice not valid.....Enter again\n";
					system("pause");
					break;	
		}
	}while (option!=9);
}
//-----MENU to read Data------------
void menureadData(){ //no return value. no parameter.
	system("CLS");
	cout<<"\n\n";
	cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\t\t\t\t W E L C O M E  T O  \n";
	cout<<"\t\t\t  ";
	cout<<"	   /    __         __ "<<endl;
	cout<<"\t\t\t  ";
	cout<<"|   _ |_  _  / _  _ |_  |_ o|_"<<endl;
	cout<<"\t\t\t  ";
	cout<<"|__(-`|_ _)  \\__)(-`|_  |  ||_"<<endl;
	cout<<"\n\t\t\t\t      -2020-  \n";
	cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
	cout<<"\n\t\t\t      Press Y to proceed: ";
}
//-----MENU  for the other functions------------
void menuOthers(){ //no return value. no parameter.
	system("CLS");
	cout<<"\n\n";
	cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\t\t";
	cout<<" #                    ###            #####                  #######"<<endl;
	cout<<"\t\t";          
	cout<<" #       ###### ##### ###  ####     #     # ###### #####    #       # #####"<<endl;
	cout<<"\t\t";  
	cout<<" #       #        #    #  #         #       #        #      #       #   #"<<endl;
	cout<<"\t\t";    
	cout<<" #       #####    #   #    ####     #  #### #####    #      #####   #   #"<<endl;
	cout<<"\t\t";    
	cout<<" #       #        #            #    #     # #        #      #       #   #"<<endl;
		cout<<"\t\t";    
	cout<<" #       #        #       #    #    #     # #        #      #       #   #"<<endl;
	cout<<"\t\t";    
	cout<<" ####### ######   #        ####      #####  ######   #      #       #   #"<<endl;    
	cout<<"\n\t\t\t\t\t\t -2020- \n";
	cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\t\t\t\t Choose the following options: \n";
	cout<<"\t\t\t\t 1. Display data and compute BMI,BMR,RMR\n";
	cout<<"\t\t\t\t 2. Add Data\n";
	cout<<"\t\t\t\t 3. Modify Weight/Height\n";
	cout<<"\t\t\t\t 4. Search Data\n";
	cout<<"\t\t\t\t 5. Combinational Search\n";
	cout<<"\t\t\t\t 6. Statistic\n";
	cout<<"\t\t\t\t 7. Target weight\n";
	cout<<"\t\t\t\t 8. Save Data\n";
	cout<<"\t\t\t\t 9. Exit.......\n\n";
	cout<<"\n\t\t\t\t Your option is: ";
}
//---read Data function-------
void readData(int &arraySize,USMstaff_info ob[]){
	string nAme,space;
	long long int id, ID;
	string genDer;
	float weIght,heIght;
	ifstream myFile1, myFile2;
	myFile1.open("PersonalInfo.txt",ios::app);
	myFile2.open("FitnessInfo.txt",ios::app);
	while((!myFile1.eof())&&(!myFile2.eof())){
		if((myFile1.eof()&&myFile2.eof())==true)
		break;
		else{
		myFile1>>id;
		getline(myFile1,space,'\t');
		getline(myFile1,nAme,'\t');
		getline(myFile1,genDer);
		myFile2>>ID;
		if(ID==id){ //using sample data 1, check whether both IDs in two seperate textfilea match each other. Consider the order is the same in both textfiles.
			myFile2>>weIght>>heIght;
			ob[arraySize].setData_all(nAme,id,genDer,weIght,heIght); //keep all data in array
		}
		arraySize++; // want to track the number of data available in the textfiles	
		}
	}myFile1.close();myFile2.close();
}
//---add Data function-------
void addData(int &arraySize,USMstaff_info ob[]){
system("CLS");
	string nAme;
	long long int id;
	string genDer;
	float weIght,heIght;
	int add;
	cout<<"\n\n\tEnter the number of Staff to be add: "; //prompt user to enter the number of staff(s)
	cin>>add;
	for (int j=arraySize; j<arraySize+add; j++){ 
	system("CLS");
		cout<<endl<<"\tEnter name: ";
		cin.ignore();//purpose: the the next cout will not cout in the same time
		getline(cin,nAme);
		while(nAme.size()<2){ //input validation if the user does not put any name/only put one character
			if (nAme.size()<2){
			cout<<"\tWrong input. Please enter again..\n\tEnter name: ";
			getline(cin,nAme);	
			}
		}
		cout<<"\tEnter gender (Male, Female): ";
		cin>>genDer;
		while(genDer!="Male" && genDer!="Female"){//input validation if the user does not put Female/Male
			if (genDer!="Male"&& genDer!="Female"){
				cout<<"\tWrong input. Please enter again..\n\tEnter gender (Male, Female): ";
				cin>>genDer;
			}
		}
		cout<<"\tEnter Staff ID: "; 
		cin>>id;
		
		while(id<601231999999 && id>991231999999){ //input validation of age
		if (id<601231999999 && id>991231999999 && genDer=="Male"){//1960-60 years old the max for work. Assume the min work age in USM is 21 years old (1999)
				if(id%2==0)//The Staff ID for Male must be odd number
					cout<<"\tWrong input. Please enter again..\n\tEnter Staff ID: ";
					cin>>id; 
		} 
		else if (id<601231999999 && id>991231999999 && genDer=="Female"){
		if(id%2!=0){//The Staff ID for Female must be odd number
				cout<<"\tWrong input. Please enter again..\n\tEnter Staff ID: ";
				cin>>id;
		}
		} } 
		/*cannot do for 2000's because "error: invalid digit "8" in octal constant." cannot put 0 in the beginning and the 0 will not be save.
				 e.g 000213050304. save as 213050304 */
		
		cout<<"\tEnter weight(kg): ";
		cin>>weIght;
		while(weIght<40.0){ //Commonly, min weight for adult is 40kg.
			if (weIght<40.0){
				cout<<"\tWrong input. Please enter again..\n\tEnter weight: ";
				cin>>weIght;
			}
		}
	
		cout<<"\tEnter height(cm): ";
		cin>>heIght;
		while(heIght<145.0 && heIght>200.0){ //Commonly, range height for adult is 145-200.
			if (heIght<145.0 && heIght>200.0){
				cout<<"\tWrong input. Please enter again..\n\tEnter height: ";
				cin>>heIght;
			}
		}
		ob[j].setData_all(nAme,id,genDer,weIght,heIght); 
	}	
arraySize=arraySize+add; //update the current array size	
}
//--------Display all data------------------
void displayData(int &arraySize,USMstaff_info ob[]){
	system("CLS");
	cout<<"Name\t\t\t\t        Age    Gender    Staff ID\t  Weight   Height     BMI\tCategory\tBMR\tRMR \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int j=0;j<arraySize;j++){
		ob[j].Display();
		ob[j].calDOB();
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	}
}
//---Modify data: Weight/Height----------
void modifyData(int &arraySize,USMstaff_info ob[]){
	long long int iD;
	string nAme;
	long long int id;
	string genDer;
	float weIght,heIght;
	char change;
	float n_weight, n_height;
	int k;
	system("CLS");
	cout<<endl<<"\t\t\tEnter your id: ";
	cin>>iD;
	
	for (int j=0; j<arraySize; j++){
		if(iD == ob[j].getstaffID()){
			k=j;
		}
	}
		if (iD == ob[k].getstaffID()){
			cout<<"\t\t\tWhat do you want to change? (W-weight, H-height) ->";
			cin>>change;
			if(change=='W'){
				cout<<endl<<"\t\t\tEnter your new weight(kg): ";
				cin>>n_weight;
				
				nAme=ob[k].getName();
				id=ob[k].getstaffID();
				genDer=ob[k].getGender();
				weIght=n_weight;
				heIght=ob[k].getHeight();
				ob[k].setData_all(nAme,id,genDer,weIght,heIght);
				cout<<"\t\t\tYour data has been successfully saved . Enter 1 to check your modification."<<endl;
			}
			else if(change=='H'){
				cout<<endl<<"\t\t\tEnter your new height(cm): ";
				cin>>n_height;
				
				nAme=ob[k].getName();
				id=ob[k].getstaffID();
				genDer=ob[k].getGender();
				weIght=ob[k].getWeight();
				heIght=n_height;
				ob[k].setData_all(nAme,id,genDer,weIght,heIght);
				cout<<"\t\t\tYour data has been successfully saved . Enter 1 to check your modification."<<endl;
			}
		}
		else
		cout<<"\n\t\t\tThe Staff ID is not available in the database."<<endl;
}
//-------Search data using ID----------
void searchData(int &arraySize,USMstaff_info ob[]){
	long long int search;
	int k;
	system("CLS");
	cout<<"\n\n\t\tSearch: ";
	cin>>search;
	for (int j=0; j<arraySize; j++){
		if(search == ob[j].getstaffID()){
			k=j;
		}
	}
	
	if(search == ob[k].getstaffID()){
		cout<<"Name\t\t\t\t        Age    Gender    Staff ID\t  Weight   Height     BMI\tCategory\tBMR\tRMR \n";
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;				
			ob[k].Display();
			ob[k].calDOB();
	}else
		cout<<"\n\t\tThe Staff ID is not available in the database."<<endl;
}
//-------Combinational Search: BMI range, Age Range-------------
void combinationData(int &arraySize,USMstaff_info ob[]){
	int minAge,maxAge;
	float minBMI,maxBMI;
	system("CLS");
	cout<<"\n\t\t\tEnter BMI range: \n"<<"\t\t\tmin: ";
	cin>>minBMI;
	cout<<"\t\t\tmax: ";				
	cin>>maxBMI;
	cout<<"\t\t\tEnter age range: \n"<<"\t\t\tmin: ";
	cin>>minAge;
	cout<<"\t\t\tmax: ";
	cin>>maxAge;

	cout<<"Name\t\t\t\t        Age    Gender    Staff ID\t  Weight   Height     BMI\tCategory\tBMR\tRMR \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		for (int j=0; j<arraySize; j++){
			if(ob[j].bmi>=minBMI && ob[j].bmi<=maxBMI && ob[j].age>=minAge && ob[j].age<=maxAge){
				ob[j].Display();
				ob[j].calDOB();	
			}	
		} 
} 
//------Statistic------------
void statistic(int &arraySize,USMstaff_info ob[]){
	int underweightM,underweightF,normalM,normalF,overweightM,overweightF,
	obeseM,obeseF,catM,catF,underweight,normal,overweight,obese,total;
	underweightM=underweightF=normalM=normalF=overweightM=overweightF=obeseM=obeseF=total=catM=catF=underweight=normal=overweight=obese=0;
	
	for (int j=0; j<arraySize; j++){
	
		if (ob[j].bmi >=30.0 &&  ob[j].getGender()=="Male")
			obeseM++;
		else if (ob[j].bmi >=30.0 && ob[j].getGender()=="Female")
			obeseF++;
		else if (ob[j].bmi >=25.0 && ob[j].bmi <30.0 &&  ob[j].getGender()=="Male")
			overweightM++;
		else if (ob[j].bmi >=25.0 && ob[j].bmi <30.0 && ob[j].getGender()=="Female")
			overweightF++; 		
		else if (ob[j].bmi >=20.0 && ob[j].bmi <25 &&  ob[j].getGender()=="Male")
			normalM++;
		else if (ob[j].bmi >=20.0 && ob[j].bmi <25 && ob[j].getGender()=="Female")
			normalF++;
		else if(ob[j].bmi <20 &&  ob[j].getGender()=="Male")
			 underweightM++;
		else if(ob[j].bmi <20 && ob[j].getGender()=="Female")
			 underweightF++;
	//Calculate the total for each category
	underweight=underweightF+underweightM; //total for underweight
	normal=normalF+normalM;//total for normal
	overweight=overweightF+overweightM;//total for overweight
	obese=obeseF+obeseM;//total of obese category
	catM=underweightM+normalM+overweightM+obeseM; //all category for Male
	catF=underweightF+normalF+overweightF+obeseF; //all category for Female
	total=catM+catF; //the number of USM staff's in the data
		
}	system("CLS");
	cout<<"\n\n\t\t\t Statistic of USM staff's BMI Category"<<endl;
	cout<<"\n\t\t====================================================="<<endl;
	cout<<"\t\t  category\t  Male\t      Female\t    Total"<<endl;
	cout<<"\t\t====================================================="<<endl;
	cout<<"\t\t underweight\t   "<<underweightM<<"\t\t"<<underweightF<<"\t      "<<underweight<<endl;
	cout<<"\t\t   normal\t   "<<normalM<<"\t\t"<<normalF<<"\t      "<<normal<<endl;
	cout<<"\t\t overweight\t   "<<overweightM<<"\t\t"<<overweightF<<"\t      "<<overweight<<endl;
	cout<<"\t\t   obese\t   "<<obeseM<<"\t\t"<<obeseF<<"\t      "<<obese<<endl;
	cout<<"\t\t====================================================="<<endl;
	cout<<"\t\t   total\t   "<<catM<<"\t\t"<<catF<<"\t      "<<total<<endl;
	cout<<"\t\t====================================================="<<endl;
}
//------Target Weight------------
void targetWeight(int &arraySize,USMstaff_info ob[]){
	float nweight,calorie;
	long long int iD;
	system("CLS");
	int k;
	bool check;
	cout<<"\n\t\t\t\t\tEnter your ID: ";
	cin>>iD;

	for (int j=0; j<arraySize; j++){
	if(iD == ob[j].getstaffID()){
		k=j;
		check=true;
		} 
	}

	if(check){
		cout<<"\nName\t\t\t\t        Age    Gender    Staff ID\t  Weight   Height     BMI\tCategory\tBMR\tRMR \n";
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		ob[k].Display();
		ob[k].calDOB();
	if (ob[k].bmi>=20.0 && ob[k].bmi<25.0)
		cout<<"\n\t\t\t\t\tYou are in a good shape. Keep it up!"<<endl; //The person does not need to lose/gain weight because he/she is in normal category(BMI)
	else{
		cout<<"\n\t\t\t\t\tEnter your target weight(kg): ";
		cin>>nweight;
	
	for (int j=0; j<arraySize; j++){
		if (iD==ob[j].getstaffID()&& ob[j].getGender()=="Male"){
			calorie= 10 * nweight + 6.25 * ob[j].getHeight() - 5 * ob[j].age + 5;
			cout<<"\n\t\t\t\t\tYou have to consume "<<calorie<<" calorie/day in order to get your desire weight"<<endl;
			cout<<"\n\t\t\t\t\tDon't forget to live a healthy lifestyle"<<endl; 
		}
		else if (iD==ob[j].getstaffID() && ob[j].getGender()=="Female"){
			calorie= 10 *  nweight  + 6.25 *  ob[j].getHeight() - 5 * ob[j].age - 161;
			cout<<"\n\t\t\t\t\tYou have to consume "<<calorie<<" calorie/day in order to get your desire weight"<<endl;
			cout<<"\n\t\t\t\t\tDon't forget to live a healthy lifestyle"<<endl;   
		}
		
	}
	}
	}
	else
		cout<<"\n\t\t\t\t\tThe Staff ID is not available in the database."<<endl;
}
//------Produce Output File-------------
void outputFile(int &arraySize,USMstaff_info ob[]){
	string nAme;
	long long int id;
	string genDer;
	float weIght,heIght;
	ofstream outData;
	
	outData.open("outputFile.txt",ios::app);		
	for(int i=0; i<arraySize; i++){
		nAme=ob[i].getName();
		id=ob[i].getstaffID();
		genDer=ob[i].getGender();
		weIght=ob[i].getWeight();
		heIght=ob[i].getHeight();
		
		outData.width(40);outData<<left<<nAme;
		outData.width(7);outData<<ob[i].age;
		outData.width(10);outData<<genDer;
		outData.width(8);outData<<id;
		outData<<fixed<<showpoint<<setprecision(2);
		outData.width(10);outData<<right<<weIght;
		outData.width(10);outData<<heIght;
		outData.width(10);outData<<ob[i].bmi;
		outData.width(15);outData<<ob[i].category;
		outData.width(10);outData<<ob[i].bmr;
		outData.width(10);outData<<ob[i].rmr<<endl;
	}outData.close();
	cout<<"\t\t\t\tThe data is save in ouputFile.txt"<<endl;		
}
//--------Text Art after exit the program---------
void exit(){
	cout<<"\n\n\t\t";cout<<".d8888. d88888b d88888b      db    db  .d88b.  db    db      db       .d8b.  d888888b d88888b d8888b. db"<<endl;
	cout<<"\t\t";cout<<"88'  YP 88'     88'          `8b  d8' .8P  Y8. 88    88      88      d8' `8b `~~88~~' 88'     88  `8D 88"<<endl; 
	cout<<"\t\t";cout<<"`8bo.   88ooooo 88ooooo       `8bd8'  88    88 88    88      88      88ooo88    88    88ooooo 88oobY' YP"<<endl; 
	cout<<"\t\t";cout<<"  `Y8b. 88~~~~~ 88~~~~~         88    88    88 88    88      88      88~~~88    88    88~~~~~ 88`8b"<<endl;      
	cout<<"\t\t"; cout<<"db   8D 88.     88.             88    `8b  d8' 88b  d88      88booo. 88   88    88    88.     88 `88. db"<<endl; 
	cout<<"\t\t"; cout<<"`8888Y' Y88888P Y88888P         YP     `Y88P'  ~Y8888P'      Y88888P YP   YP    YP    Y88888P 88   YD YP\n"<<endl; 
}
