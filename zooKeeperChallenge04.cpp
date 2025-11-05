// ZooKeeperChallenge.cpp
// Created by Chijenda

#include <iostream>
#include <string>
#include <fstream> // adding file to code
#include <sstream> // for parsing strings
#include <chrono>
#include <ctime> // handles date and time for the animals
#include <iomanip>
#include <unordered_map> // hashmap
using namespace std;

// Class is a blueprint
// Parent class
class Animal {
private:
    static int NumofAnimals; // Static variable belongs to the parent class, it just tracks total animals created.
    string name;
    string id;
    string bday;
    string sex;
    string species;
    string birthseason;
    string weight;
    string color;
    string location;
    string state;
    string arrivaldate;
    int age;


public:
    // constructor - this will run every time an object is created
    // const string simply avoids making extra copies of the string and prevent changes to the input variables
    Animal(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
           const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    {
        this->name = name;  // "this->" takes the value of the variable from the parent class and inputs the name we give it.
        this->id = id;
        this->bday = bday;
        this->sex = sex;
        this->species = species;
        this->birthseason = birthseason;
        this->weight = weight;
        this->color = color;
        this->location = location;
        this->state = state;
        this->arrivaldate = arrivaldate;
        this->age = age;
        NumofAnimals++;  // count each new Animal object
    }
    void setName(const string& name) { this->name = name; }
    void setId(const string& id) { this->id = id; }
    void setBday(const string& bday) { this->bday = bday; }
    void setSex(const string& sex) { this->sex = sex; }
    void setSpecies(const string& species) { this->species = species; }
    void setBirthseason(const string& birthseason) { this->birthseason = birthseason; }
    void setWeight(const string& weight) { this->weight = weight; }
    void setColor(const string& color) { this->color = color; }
    void setLocation(const string& location) { this->location = location; }
    void setState(const string& state) { this->state = state; }
    void setArrivaldate(const string& arrivaldate) { this->arrivaldate = arrivaldate; }
    void setAge(int age) { this->age = age; }

    // Getters
    string getName() const { return name; }
    string getId() const { return id; }
    string getBday() const { return bday; }
    string getSex() const { return sex; }
    string getSpecies() const { return species; }
    string getBirthseason() const { return birthseason; }
    string getWeight() const { return weight; }
    string getColor() const { return color; }
    string getLocation() const { return location; }
    string getState() const { return state; }
    string getArrivaldate() const { return arrivaldate; }
    int getAge() const { return age; }

    // Static getter for total number of animals
    static int getNumofAnimals() { return NumofAnimals; }


    // Converts all animal data into a single formatted string
    // so it can be displayed easily on the screen.
    string toString() const {
        stringstream ss;
        ss << "Animal Information:\n"
           << "Name: " << name << "\n"
           << "ID: " << id << "\n"
           << "Birthday: " << bday << "\n"
           << "Sex: " << sex << "\n"
           << "Species: " << species << "\n"
           << "Birth Season: " << birthseason << "\n"
           << "Weight: " << weight << "\n"
           << "Color: " << color << "\n"
           << "Location: " << location << "\n"
           << "State: " << state << "\n"
           << "Arrival Date: " << arrivaldate << "\n"
           << "Age: " << age << "\n"
           << "Total Animals: " << NumofAnimals;
        return ss.str();

    };
};
int Animal::NumofAnimals = 0;


//Inheritance - each subclass has all Animal properties.
//todo hyena subclass
class Hyena : public Animal {
private:
static int NumofHyena;
public:
    // Animal constructor - reuse for each subclass
    Hyena(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
               const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    : Animal (name,id,bday,sex,species,birthseason,weight,color,location,state,arrivaldate,age) {
        NumofHyena++;
    }

    static int getNumofHyena() { return NumofHyena; }
};
int Hyena::NumofHyena = 0;

// todo Lion subclass
class Lion : public Animal {
private:
    static int NumofLion;
public:
    Lion(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
               const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    : Animal (name,id,bday,sex,species,birthseason,weight,color,location,state,arrivaldate,age) {
        NumofLion++;
    }
    // getter
    static int getNumofLion() { return NumofLion; }
};
int Lion::NumofLion = 0;

//todo Tiger subclass
class Tiger : public Animal {
private:
    static int NumofTiger;
public:
    Tiger(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
               const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    : Animal (name,id,bday,sex,species,birthseason,weight,color,location,state,arrivaldate,age) {
        NumofTiger++;
    }
    // getter
    static int getNumofTiger() { return NumofTiger; }
};
int Tiger::NumofTiger = 0;

//todo Bear subclass
class Bear : public Animal {
private:
    static int NumofBear;
public:
    Bear(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
               const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    : Animal (name,id,bday,sex,species,birthseason,weight,color,location,state,arrivaldate,age) {
        NumofBear++;
    }
    // getter
    static int getNumofBear() { return NumofBear; }
};
int Bear::NumofBear = 0;


int main() {

    // this stores animal objects with their own IDs as keys
    unordered_map<string,Animal*> map; // pointers allow us to store objects of different classes in the same space.


    fstream file1;
    file1.open("arrivingAnimals.txt", ios::in);

    if (file1.is_open()) {
    string line;

    // Reads the file line by line
    while (getline(file1, line)) {
        cout << line << endl; // Prints each line

        // Declare empty variables that will store animal data
        string arrivaldate = ""; // Placeholder for arrival date
        string name;             // Stores the animal's name
        string bday;             // Stores the animal's birthday

        //todo parsing the file
        //parsing means to separate by breaking single lines
        size_t pos = 0;
        string delimiter = ","; // 

        // split element 1
        pos = line.find(delimiter); // Finds the position of the first comma in the string.
        string var1 = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        cout << var1 << endl;

        // parse string again
        istringstream iss1(var1);
        int age;
        string year,old,sex,species;
        //parse the tokens
        iss1 >> age >> year >> old >> sex >> species;





        // split element 2
        pos = line.find(delimiter);
        string var2 = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        cout << var2 << endl;

        istringstream iss2(var2);
        string Born,in,birthseason;




        // split element 3
        pos = line.find(delimiter);
        string color = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        cout << color << endl;


        // split element 4
        pos = line.find(delimiter);
        string weight = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        cout << weight << endl;

        // split element 5 - location
        pos = line.find(delimiter);
        string Location = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        cout << Location << endl;



        // split element 6 - state
        pos = line.find(delimiter);

        string state = line.substr(0, pos);

        line.erase(0, pos + delimiter.length());
        cout << state << endl;


        // The program checks what species was extracted earlier and creates an object for that specific animal type
        if (species == "hyena") {
            string hyenaid = "Hy0" + to_string(Hyena::getNumofHyena());

            auto* hyena = new Hyena (name,hyenaid,bday,sex,species,birthseason,weight,color,Location,state, "",age);
            map[hyenaid] = hyena;
        }

        if (species == "lion") {
            string lionid = "Li0" + to_string(Lion::getNumofLion());

            auto* lion = new Lion (name,lionid,bday,sex,species,birthseason,weight,color,Location,state, "",age);
            map[lionid] = lion;
        }


        if (species == "tiger") {
            string tigerid = "Ti0" + to_string(Tiger::getNumofTiger());

            auto* tiger = new Tiger (name,tigerid,bday,sex,species,birthseason,weight,color,Location,state, "",age);
            map[tigerid] = tiger;
        }


        if (species == "bear") {
            string bearid = "Be0" + to_string(Bear::getNumofBear());

            auto* bear = new Bear (name,bearid,bday,sex,species,birthseason,weight,color,Location,state, "",age);
            map[bearid] = bear;
        }

    }


    file1.close();
}else{cout << "error opening file" << endl;}

    // This keeps track of which species have already been printed.
    // bool means whether it is true or false
    unordered_map<string, bool> printed;
    // This line of code goes through key value pairs
    // The keys in my case are the unique ID's of the animals.
    for (auto &pair : map) {
        string species = pair.second->getSpecies();
        if (!printed[species]) {  // If the species have not been printed
            // this line of code calls on toString to display all animal info and formats them.
            cout << "\n" << pair.second->toString() << endl;

        }
    }
    // Basically lets us know the total animals that have been created.
    cout << "\nTotal created animals: " << Animal::getNumofAnimals() << endl;


    return 0;
};
