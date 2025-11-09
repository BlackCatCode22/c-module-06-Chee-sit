// ZooKeeperChallenge.cpp
// Created by Chijenda


//Libraries
#include <iostream>
#include <string>
#include <fstream> // adding file to code either to read or write.
#include <sstream> // for parsing strings
#include <ctime> // handles date and time for the animals
#include <iomanip>
#include <vector>
#include <unordered_map> // lets us use hashmaps, it stores key value pairs
using namespace std;

// Class is a blueprint
// Parent class
class Animal {
// Anything declared under private can only be accessed inside this class.
private:
    static int NumofAnimals; // Static variable belongs to the parent class, it just tracks total animals created.
// Attributes of the animals
    string name;
    string id;
    string bday;
    string sex;
    string species;
    string birthseason;
    string weight; // This stores the weight of the animal either in lbs or kg.
    string color;
    string location;
    string state;
    string arrivaldate;
    int age; // integer number which is for whole numbers ONLY.

    // Anything under public can be accessed outside the class
public:
    // constructor - this will run every time an object is created
    // const string & simply avoids making extra copies of the string and prevent changes to the input variables
    Animal(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
           const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    {
        // "this->" takes the value of the variable from the parent class and inputs the name we give it.
        this->name = name;
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
    // A setter is a function that changes or updates a variable's value.
    // these are public so we can update private data from outside the class.
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
    // A getter is a function that gives information back.
    // For example, getName() does not change anything.
    // It just returns what the animal’s name already is.
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

    // my toString.
    // Converts all animal data into a single formatted string.
    // so it can be displayed neatly on the screen.
    string toString() const {

        // this temporarily stores lines of code until combined as one chunk of code.
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
        // After we’re done adding everything into the stringstream
        // Take everything out of the box and turn it into one big string.
        return ss.str();

    };
};
// It starts at 0 because, in the beginning, no animals have been made yet.
int Animal::NumofAnimals = 0;


//Inheritance - each subclass has all Animal properties.
//todo hyena subclass
class Hyena : public Animal {
private:
static int NumofHyena;
public:
    // Animal constructor - reuse for each subclass
    // It takes all the animal info and passes it to the Animal class using ": Animal(...)"
    Hyena(const string &name, const string &id, const string &bday, const string &sex, const string &species, const string &birthseason,
         const string &weight, const string &color, const string &location, const string &state, const string &arrivaldate, int age)
    : Animal (name,id,bday,sex,species,birthseason,weight,color,location,state,arrivaldate,age) {
        // Every time a new Hyena object is made, add one to the counter.
        NumofHyena++;
    }
    // This tells us how many hyenas exist in total.
    static int getNumofHyena() { return NumofHyena; }
};
// starts at zero because no hyena have been created yet.
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

    // My hashmap
    // Think of it like storage boxes with labels for each animal, this is called a key.
    // A key in my case are the animal ID's.
    unordered_map<string,Animal*> map;

    // Function lets us work with files.
    fstream file1;
    file1.open("arrivingAnimals.txt", ios::in);
    if (file1.is_open()) {
    string line; // A string that stores a line.

        // I hardcoded the names from our animalNames.txt file.
        // These lists store possible names for each animal type.
        // Each list uses "vector<string>" which is like a resizable array that stores text values.
        // The names are chosen to match the correct species for realism.
        vector<string> hyenaNames = {"Shenzi", "Banzai", "Ed", "Zig", "Bud", "Lou", "Kamari", "Wema", "Nne", "Madoa", "Prince Nevarah"};
        vector<string> lionNames = {"Scar", "Mufasa", "Simba", "Kiara", "King", "Drooper", "Kimba", "Nala", "Leo", "Samson", "Elsa", "Cecil"};
        vector<string> bearNames = {"Yogi", "Smokey", "Paddington", "Lippy", "Bungle", "Baloo", "Rupert", "Winnie the Pooh", "Snuggles", "Bert"};
        vector<string> tigerNames = {"Tony", "Tigger", "Amber", "Cosimia", "Cuddles", "Dave", "Jiba", "Rajah", "Rayas", "Ryker"};

        // Random seed generator to make names different each time I run the program.
        // The names are assigned to their animals.
        // "time(0)" gives the current time in seconds.
        // This makes sure each time the program runs, different random names appear instead of the same ones.
        srand(static_cast<unsigned int>(time(0)));

    // A while loop that reads the file line by line
    while (getline(file1, line)) {
        // Prints each line

        // Declare empty variables that will store animal data
        string arrivaldate = ""; // Placeholder for arrival date
        string name;             // Stores the animal's name
        string bday;             // Stores the animal's birthday

        //todo parsing the file
        //parsing means to separate by breaking single lines
        // size_t is a number type used to store a position in text.
        // It’s set to 0 because we start looking from the beginning of the line
        size_t pos = 0;

        // A comma separates pieces of data in the file, like a divider between words.
        string delimiter = ",";

        // todo split element 1
        // Finds the position of the first comma in the string.
        pos = line.find(delimiter);

        // substr = substring.
        // substr(0, pos) means to take the part of the text from position 0 up to the comma.
        // For example: from “4 year old male hyena,born in summer,...” it takes “4 year old male hyena”
        string var1 = line.substr( 0 ,pos);

        // erase removes the part we already took out (var1 and the comma),
        // so the line now starts right after the comma for the next step.
        line.erase(0, pos + delimiter.length());
        //cout << var1 << endl;

        // parse string again
        // istringstream lets us read words from a single piece of text like from my example.
        istringstream iss1(var1);
        int age;
        string year,old,sex,species;
        // reads from line into the variables one by one.
        iss1 >> age >> year >> old >> sex >> species;

        // From this point on, everything has the same process as element 1.

        // todo split element 2 - birthseason
        pos = line.find(delimiter);
        string var2 = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        //cout << var2 << endl;

        istringstream iss2(var2);
        string word, birthseason;
        // Birthseason kept saying "born" or "born in" instead of printing the actual season.
        // use a while loop with an If statement.
        while (iss2 >> word) {

            // so if "born in" is printed again
            if (word != "born" && word != "in") {

                // birthseason = word will skip words "born" and "in" and give me the actual season.
                birthseason = word;
            }
        }



        // todo split element 3 - color
        pos = line.find(delimiter);
        string color = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        //cout << color << endl;


        // todo split element 4 - weight
        pos = line.find(delimiter);
        string weight = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        //cout << weight << endl;

        // todo split element 5 - location
        pos = line.find(delimiter);
        string Location = line.substr( 0 ,pos);
        line.erase(0, pos + delimiter.length());
        //cout << Location << endl;



        // todo split element 6 - state
        pos = line.find(delimiter);
        string state = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        //cout << state << endl;


        // todo If statements
        // The program checks what species was extracted earlier and creates an object for that specific animal type
        // If the animal is a hyena, code will run
        if (species == "hyena") {

            // This creates a unique ID for each hyena, like "Hy01", "Hy02", and so on.
            string hyenaid = "Hy0" + to_string(Hyena::getNumofHyena());

            // This picks a random name from the list of hyena names.
            // "rand() % hyenaNames.size()" gives a random position number in that list.
            string name = hyenaNames[rand() % hyenaNames.size()];

            // This line creates a new hyena object using the random name generator and other data collected earlier.
            // "new" means it’s being made in computer memory and a pointer will store it
            auto* hyena = new Hyena(name, hyenaid, bday, sex, species, birthseason, weight, color, Location, state, "", age);

            // This stores the new hyena object into the map using its ID as the key.
            map[hyenaid] = hyena;
        }

        // Everything underneath is the same, copy and paste format for each animal.


        else if (species == "lion") {
            string lionid = "Li0" + to_string(Lion::getNumofLion());
            string name = lionNames[rand() % lionNames.size()];
            auto* lion = new Lion(name, lionid, bday, sex, species, birthseason, weight, color, Location, state, "", age);
            map[lionid] = lion;
        }

        else if (species == "tiger") {
            string tigerid = "Ti0" + to_string(Tiger::getNumofTiger());
            string name = tigerNames[rand() % tigerNames.size()];
            auto* tiger = new Tiger(name, tigerid, bday, sex, species, birthseason, weight, color, Location, state, "", age);
            map[tigerid] = tiger;
        }

        else if (species == "bear") {
            string bearid = "Be0" + to_string(Bear::getNumofBear());
            string name = bearNames[rand() % bearNames.size()];
            auto* bear = new Bear(name, bearid, bday, sex, species, birthseason, weight, color, Location, state, "", age);
            map[bearid] = bear;
        }
    }


    file1.close();
}else{cout << "error opening file" << endl;}

    // This keeps track of which species have already been printed.
    // bool means whether it is true or false that the species have already been printed.
    unordered_map<string, bool> printed;

    // This line of code goes through key value pairs
    // The keys in my case are the unique ID's of each animal created.
    for (auto &pair : map) {
        string species = pair.second->getSpecies();

        // If the species have not been printed
        if (!printed[species]) {
            // this line of code calls on toString to display all animal info and formats them.
            cout << "\n" << pair.second->toString() << endl;

        }
    }
    // Basically lets us know the total animals that have been created.
    cout << "\nTotal created animals: " << Animal::getNumofAnimals() << endl;


    return 0;
};
