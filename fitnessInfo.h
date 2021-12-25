/*This is base class (Composition)
* It saved Fitness Information of USM staff: Weight, Height.
*/
//------HEADER---------
#include <iostream> 
class fitnessInfo{ //Base class (Composition)
	private:
		float weight;
		float height;
	public:
		float getWeight(){return weight;}	
		float getHeight(){return height;}
		void setFit(float,float); 
		fitnessInfo(){weight=height=0;}	//constructor
		~fitnessInfo(){weight=height=0;} //destructor
};
void fitnessInfo::setFit(float Weight,float Height){
	weight=Weight;
	height=Height;
}
