#include <iostream> 
#include <cstdlib>
#include <string> 

using namespace std;
class FarmAnimal{ 
public:
    //default constructor
    FarmAnimal(){};
    //constructor that excepts a parameter
    FarmAnimal(double water_consumption) : waterConsumption(water_consumption) {}
    //gets Water Consumption
    double getWaterConsumption(){return waterConsumption;}
    //sets Water Consumption
    void setWaterConsumption(double waterConsumption){this->waterConsumption = waterConsumption;}
private:
    double waterConsumption;
};

class Cow : public FarmAnimal
{
public:
    //Creates a Cow and set the new WaterConsumption
    Cow(double weight){
    FarmAnimal::setWaterConsumption((weight / 100) * 8.6);
    }
};


class Sheep : public FarmAnimal
{
public:
    //Creates a Sheep and set the new WaterConsumption
    Sheep(double weight){
    FarmAnimal::setWaterConsumption((weight / 100) * 1.1);}
};


class Horse : public FarmAnimal
{
public:
    //Creates a Horse and set the new WaterConsumption
    Horse(double weight){
    FarmAnimal::setWaterConsumption((weight / 100) * 6.8);}
};


class ConsumptionAccumulator {
public:
    //constructor for the accumulator
    ConsumptionAccumulator();
    //gets the consumption
    double getTotalConsumption();
    //Adds an animals consumption to the total consumption
    void addConsumption(FarmAnimal animal);
private:
    double total_consumption;
};
//base constructor
ConsumptionAccumulator::ConsumptionAccumulator() : 
    total_consumption()
{ 

}
//gets the  consumption
double ConsumptionAccumulator::getTotalConsumption() 
{
    return total_consumption; 
}
//adds the current animal consumption to the total consumption
void ConsumptionAccumulator::addConsumption(FarmAnimal animal) 
{
    total_consumption += animal.getWaterConsumption(); 
}

int main() 
{

//holds inputs    
string input;
double weight;

//creates an accumulator
ConsumptionAccumulator accumulator;

//does something while a condition is true
do{
    //reads a line
    getline(cin, input);
    //looks at the line and searches for "Cow" and a long or float. Then points that number to the variable made for it
        if(1 == sscanf(input.c_str(), "Cow %lf", &weight))
        {
            Cow Cow(weight);
            accumulator.addConsumption(Cow);
        }
        //looks at the line and searches for "Sheep" and a long or float. Then points that number to the variable made for it
        else if(1 == sscanf(input.c_str(), "Sheep %lf", &weight))
        {   
            Sheep Sheep(weight); 
            accumulator.addConsumption(Sheep);
        }
    //looks at the line and searches for "Horse" and a long or float. Then points that number to the variable made for it
        else if(1 == sscanf(input.c_str(), "Horse %lf", &weight))
        {
            Horse Horse(weight); 
            accumulator.addConsumption(Horse);
        }
        
} while (input != "");
    //prints total consumption
    cout << accumulator.getTotalConsumption();   
}