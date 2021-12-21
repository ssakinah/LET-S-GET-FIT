#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h> //contains declarations for all of the functions in the Windows API
using namespace std;

//function prototype
void menu();
void readData(string[],string[],char[],int[],float[],float[],int&);
void addData(string[],string[],char[],int[],float[],float[],int&);
void modify(string[],string[],char[],int[],float[],float[],int&);
void outputFile(string [],string[],char[],int[],float[],float[],float[],float[],float[],string [],int&);
void bmi_bmr_rmr(string[],string[],char[],int[],float[],float[],float[],float[],float[],string[],int&);
void Search(string[],string [],char[],int[],float[],float[],float[],float[],float[],int&);
void combination(string[],string[],char[],int[],float[],float[],float[],float[],float[],int&);
void statistic(string [],string[],char[],int[],float[],float[],float[],float[],float[],string [],int&);
void target(string [],string[],char[],int[],float[],float[],float[],float[],float[],int&);
void modify(string [],string[],char[],int[],float[],float[],float[],float[],float[],int&);

int main(){
	int option, size=0, age[100]={0};
	string name[100]={" "},ID[100]={" "},category[100]={" "};								//declaration of all variables and arrays
	char gender[100]={" "};
	float weight[100]={0.0},height[100]={0.0},bmI[100]={0.0},bmR[100]={0.0},rmR[100]={0.0};
	system("Color f3"); //use #include <windows.h> to obtain the background color code
	do{
		menu(); //f(x) call to display menu
		cin>>option;	//input by user to choose the options given
		switch (option){
			case 1: readData(name,ID,gender,age,weight,height,size);//f(x) call to read USM staff's data from text file
					system("pause");
					break;
			case 2: cout<<endl;
					bmi_bmr_rmr(name,ID,gender,age,weight,height,bmI,bmR,rmR,category,size); //f(x) call to calculate bmi,bmr,rmr
					cout<<endl;
					system("pause");
					break;
			case 3: Search(name,ID,gender,age,weight,height,bmI,bmR,rmR,size); //f(x) call to search Staff's ID and display the data
					system("pause");
					break;
			case 4: combination(name,ID,gender,age,weight,height,bmI,bmR,rmR,size); //f(x) call to do combinational search and display the data
					system("pause");
					break;
			case 5: statistic(name,ID,gender,age,weight,height,bmI,bmR,rmR,category,size); //f(x) call to show the statistics of BMI chart
					system("pause");
					break;
			case 6: addData(name,ID,gender,age,weight,height,size); //f(x) call to add new data
					system("pause");
					break;	
			case 7: target(name,ID,gender,age,weight,height,bmI,bmR,rmR,size); //f(x) call to show calorie per day based on target weight
					system("pause");
					break;
			case 8:	modify(name,ID,gender,age,weight,height,size); //f(x) call to modify staff's data. modify age and weight.
					system("pause");
					break;
			case 9:outputFile(name,ID,gender,age,weight,height,bmI,bmR,rmR,category,size); //f(x) call to save all the output into new textfile
					system("pause");
					break;
			case 10:option=10; //to stop the program
					system("pause"); 
					break;
			default: cout <<"\t\t\t Choice not valid.....Enter again\n"; //if the user put wrong value 
					 system("pause");
					 break;
		}
	} while (option!=10);
}
void menu(){ //no return value. no parameter.
	system("CLS");
	cout<<"\n\n";
	cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\t\t\t\t\t Let's Get Fit \n";
	cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\t\t\t\t Choose the following options: \n";
	cout<<"\t\t\t\t 1. Read data from the text file\n";
	cout<<"\t\t\t\t 2. Display data and compute BMI,BMR,RMR\n";
	cout<<"\t\t\t\t 3. Search\n";
	cout<<"\t\t\t\t 4. Combinational Search\n";					
	cout<<"\t\t\t\t 5. Statistic\n";
	cout<<"\t\t\t\t 6. Add new staff\n";
	cout<<"\t\t\t\t 7. Target\n";
	cout<<"\t\t\t\t 8. Modify\n";
	cout<<"\t\t\t\t 9. Output\n";
	cout<<"\t\t\t\t 10. Exit.......\n\n";
	cout<<"\n\t\t\t\t Your option is: ";
}
void readData(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],int &arraySize){ //read data from text file
//passing by array and reference
	ifstream inData;
    arraySize=0;
	inData.open("USM_staff.txt");
							
	while(!inData.eof()){
		if (inData.eof()==true)
			break;
		
		else{
			getline(inData,Name[arraySize],'\t');
			inData>>Id[arraySize]>>Gender[arraySize]>>Age[arraySize]>>Weight[arraySize]>>Height[arraySize];
			arraySize++;//want to know the number of data
		}
	}
	inData.close();
}
void addData(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],int &arraySize){ //add new data
//passing array and reference
	system("CLS");
	
	int add;
	cout<<"\n\n\tEnter the number of Staff to be add: "; //prompt user to enter the number of staff
	cin>>add;
	arraySize=arraySize+1; //add one to arraySize because we don't want the previous data replace the newly add data
	for (int k=arraySize; k<arraySize+add; k++){ 
		system("CLS");
		
		cout<<endl<<"\tEnter name: ";
		cin.ignore();//purpose: the the next cout will not cout in the same time.
		getline(cin,Name[k]);
		while(Name[k].size()<2){ //input validation if the user does not put any name/only put one character
			if (Name[k].size()<2){
			cout<<"\tWrong input. Please enter again..\n\tEnter name: ";
			getline(cin,Name[k]);	
			}
		}
	
		cout<<"\tEnter ID: ";
		cin>>Id[k];
		while(Id[k].size()<6 || Id[k].size()>6 ){ //input validation if the id is less than 6 or more than 6.
			if (Id[k].size()<6 || Id[k].size()>6 ){
				cout<<"\tWrong input. Please enter again..\n\tEnter ID: ";
				cin>>Id[k];
			}
		}
	
		cout<<"\tEnter gender (M-Male, F-Female): ";
		cin>>Gender[k];
		while(Gender[k]!='M'&& Gender[k]!='F'){//input validation if the user does not put F/M.
			if (Gender[k]!='M'&& Gender[k]!='F'){
				cout<<"\tWrong input. Please enter again..\n\tEnter gender (M-Male, F-Female): ";
				cin>>Gender[k];
			}
		}
	
		cout<<"\tEnter age: ";
		cin>>Age[k];
		while(Age[k]<25){ //Input validation if it does not in the range of staff's age 
			 if (Age[k]<25){
				cout<<"\tWrong input. Please enter again..\n\tEnter age: ";
				cin>>Age[k];
			}
		}
		
		cout<<"\tEnter weight: ";
		cin>>Weight[k];
		while(Weight[k]<40.0){ //Input validation if the weight below 40
			if (Weight[k]<40.0){
				cout<<"\tWrong input. Please enter again..\n\tEnter weight: ";
				cin>>Weight[k];
			}
		}
	
		cout<<"\tEnter height: ";
		cin>>Height[k];
		while(Height[k]<145.0){ //Input validation if the height below 145
			if (Height[k]<145.0){
				cout<<"\tWrong input. Please enter again..\n\tEnter height: ";
				cin>>Height[k];
			}
		}
	}	
arraySize=arraySize+add; //update the current arraySize 
}
void modify(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],int &arraySize){//modify the data
	string iD;
	int n_age;
	float n_weight;
	system("CLS");
	cout<<endl<<"\t\t\tEnter your id: ";
	cin>>iD;
					
	for (int j=0; j<arraySize; j++){ 
		if(iD == Id[j]){
			cout<<endl<<"\t\t\tEnter your new age: ";
			cin>>n_age;
			cout<<endl<<"\t\t\tEnter your new weight: ";
			cin>>n_weight;
			
			Age[j]=n_age;		//replace the data with new value
			Weight[j]=n_weight;
		}
	}
}
void outputFile(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],string Category[],int &arraySize){
	//save the output in new text file
			ofstream outData;
			outData.open("outputFile.txt",ios::app);
			
			for(int i=0; i<arraySize; i++){
			outData<<Name[i]<<"\t"<<Id[i]<<"\t"<<Gender[i]<<"\t"<<Age[i]
			<<"\t"<<Weight[i]<<"\t"<<Height[i]<<"\t"<<bmi[i]<<"\t"
			<<Category[i]<<"\t"<<bmr[i]<<"\t"<<rmr[i]<<endl;
			}
			outData.close();
			cout<<"\t\t\t\t\tThe data is save in ouputFile.txt"<<endl;
}
void bmi_bmr_rmr(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],string Category[],int &arraySize){
	//display the data and compute bmi,bmr,rmr and find the category bmi
	system("CLS");
	cout<<setprecision(2)<<fixed;
	cout<<"\nNAME\t\t\t\tID STAFF  GENDER   AGE\tWEIGHT\tHEIGHT\tBMI\tBMR\t  RMR\t       CATEGORY"<<endl;
	for (int j=0; j<arraySize; j++){
		if (Gender[j]=='M'){
			bmi[j]=Weight[j]/((Height[j]/100)*(Height[j]/100));
			bmr[j]= 10 * Weight[j] + 6.25 * Height[j] - 5 * Age[j]+ 5;
			rmr[j]= 88.362 + (13.397 * Weight[j]) + (4.799 * Height[j]) - (5.677 * Age[j]) ;
			
				if (bmi[j]<20)
				Category[j]="underweight";
				else if (bmi[j]>=20.0 && bmi[j]<25.0)
				Category[j]="normal";
				else if (bmi[j]>=25.0 && bmi[j]<30.0)
				Category[j]="overweight";
				else if(bmi[j]>=30.0)
				Category[j]="obese";
			cout<<endl;
			cout<<Name[j]<<"\t"<<Id[j]<<"\t    "<<Gender[j]<<"\t   "<<Age[j]<<"\t"<<Weight[j]<<"\t"<<Height[j]<<"\t"<<bmi[j]
			<<"\t"<<bmr[j]<<"\t  "<<rmr[j]<<"\t"<<Category[j];
			}
		else if(Gender[j]=='F'){
			bmi[j]=Weight[j]/((Height[j]/100)*(Height[j]/100));
			bmr[j]= 10 *  Weight[j]  + 6.25 *  Height[j] - 5 * Age[j] - 161;
			rmr[j] = 447.593 + (9.247 * Weight[j]) + (3.098 * Height[j]) - (4.330 * Age[j]) ;
			
				if (bmi[j]<20)
				Category[j]="underweight";
				else if (bmi[j]>=20.0 && bmi[j]<25)
				Category[j]="normal";
				else if (bmi[j]>=25.0 && bmi[j]<30.0)
				Category[j]="overweight";
				else if(bmi[j]>=30.0)
				Category[j]="obese";
			cout<<endl;
			cout<<Name[j]<<"\t"<<Id[j]<<"\t    "<<Gender[j]<<"\t   "<<Age[j]<<"\t"<<Weight[j]<<"\t"<<Height[j]<<"\t"<<bmi[j]
			<<"\t"<<bmr[j]<<"\t  "<<rmr[j]<<"\t"<<Category[j];
		}

} 
}
void Search(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],int &arraySize){
//search data	
	string search;
	int j;
	system("CLS");
	cout<<"\n\n\t\t\t\t\t\t\tSearch: ";
	cin>>search;
	cout<<"\nNAME\t\t\t\tID STAFF  GENDER   AGE\tWEIGHT\tHEIGHT\tBMI\tBMR\t  RMR"<<endl;				
	for (j=0; j<arraySize; j++){
		if(search == Id[j]){
			cout<<Name[j]<<"\t"<<Id[j]<<"\t    "<<Gender[j]<<"\t   "<<Age[j]<<"\t"<<Weight[j]<<"\t"<<Height[j]<<"\t"<<bmi[j]
			<<"\t"<<bmr[j]<<"\t  "<<rmr[j]<<"\t"<<endl;
		}
	} 
}
void combination(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],int &arraySize){
	//search data based of range bmi and age
	int minAge,maxAge;
	float minBMI,maxBMI;
	system("CLS");
	cout<<"\t\t\tEnter BMI range: \n"<<"\t\t\tmin: ";
	cin>>minBMI;
	cout<<"\t\t\tmax: ";				//variasi search. bukan setakat ni ja.
	cin>>maxBMI;
	cout<<"\t\t\tEnter age range: \n"<<"\t\t\tmin: ";
	cin>>minAge;
	cout<<"\t\t\tmax: ";
	cin>>maxAge;
	system("CLS");
	cout<<"\nNAME\t\t\t\tID STAFF  GENDER   AGE\tWEIGHT\tHEIGHT\tBMI"<<endl;
	for (int j=0; j<arraySize; j++){
		if(bmi[j]>=minBMI && bmi[j]<=maxBMI && Age[j]>=minAge && Age[j]<=maxAge)
			cout<<Name[j]<<"\t"<<Id[j]<<"\t    "<<Gender[j]<<"\t   "<<Age[j]<<"\t"<<Weight[j]<<"\t"<<Height[j]<<"\t"<<bmi[j]<<endl;
	}
}
void statistic(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],string Category[],int &arraySize){
	//calculate the number of bmi category
	int underweight=0;
	int normal=0; 
	int overweight=0;
	int obese=0;
	
	for (int j=0; j<arraySize; j++){
		if (bmi[j]<20){
			underweight++;
		}
		else if (bmi[j]>=20.0 && bmi[j]<25){
			normal++;
		}		
		else if (bmi[j]>=25.0 && bmi[j]<30.0){
			overweight++; 
		}
		else if(bmi[j]>=30.0){
			obese++; 
		}
}	system("CLS");
	cout<<"\n\n\t\t\t\t Statistic of USM staff's BMI Category"<<endl;
	cout<<"\n\n\t\t\t\t underweight: "<<underweight<<endl;
	cout<<"\t\t\t\t normal: "<<normal<<endl;
	cout<<"\t\t\t\t overweight: "<<overweight<<endl;
	cout<<"\t\t\t\t obese: "<<obese<<endl;
}
void target(string Name[],string Id[],char Gender[],int Age[],float Weight[],float Height[],float bmi[],float bmr[],float rmr[],int &arraySize){
	//let the user know the amouunt of calorie intake per day if they want to lose or gain weight
	float nweight,calorie;
	string iD;
	system("CLS");
	cout<<"Enter your ID: ";
	cin>>iD;
	cout<<"Enter your target weight: ";
	cin>>nweight;
	
	for (int j=0; j<arraySize; j++){
		if (iD==Id[j] && Gender[j]=='M'){
			calorie= 10 * nweight + 6.25 * Height[j] - 5 * Age[j]+ 5;
			cout<<"Calorie: "<<calorie<<"/day"<<endl; 
		}
		else if (iD==Id[j] && Gender[j]=='F'){
			calorie= 10 *  nweight  + 6.25 *  Height[j] - 5 * Age[j] - 161;
			cout<<"Calorie: "<<calorie<<"/day"<<endl;  
		}
		
	}
}
