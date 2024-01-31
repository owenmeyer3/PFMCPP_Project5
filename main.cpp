/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
/*
copied UDT 1:
*/

struct Diner
{
    Diner();
    ~Diner();

    int numberOfEmployees;
    std::string foodSupplier = "Sysco";
    std::string hoursOfOperation = "eight to five";
    int numberOfTables = 10;
    float starRating = 5;

    struct Kitchen
    {
        Kitchen();
        ~Kitchen();

        int numberOfChefs;
        std::string grillBrand;
        std::string tileType = "Marble";
        int numberOfBlenders = 10;
        float temperature = 100.0f;

        void runFoodDisposal();
        void burnToast(int numberOfSlices);
        std::string receiveOrder();
        float addBodyHeat();
    };

    void cookEggs(Kitchen thiskitchen);
    void serveFood(int tableNumber);
    std::string takeOrders(); 
    void loseRating(int numberOfSpills);

    Kitchen kitchen;
};

Diner::Diner():
numberOfEmployees(5)
{   
    std::cout << "Constructing Diner with " << numberOfEmployees << " employees" << std::endl;
}

Diner::~Diner()
{
    std::cout << "Destruct Diner" << std::endl;
}

Diner::Kitchen::Kitchen():
numberOfChefs(5), 
grillBrand("Weber")
{   
    std::cout << "Constructing Diner::Kitchen" << std::endl;
}

Diner::Kitchen::~Kitchen()
{
    std::cout << "Destruct Diner::Kitchen" << std::endl;
}

void Diner::Kitchen::runFoodDisposal()
{
    numberOfChefs -= numberOfBlenders;
    std::cout << "Grrrrrrrr" << std::endl;
}

void Diner::Kitchen::burnToast(int numberOfSlices)
{
    std::cout << "Cooking toast on " << grillBrand << " grill" << std::endl;

    if(numberOfSlices == 1 || grillBrand == "Weber")
    {
        temperature += 1.0f;
    }
    else
    {
        temperature += 2.0f;
    }
}

std::string Diner::Kitchen::receiveOrder(){
    return "Roger that!";
}

float Diner::Kitchen::addBodyHeat(){

    float changedTemperature = temperature;

    for(int c = 0; c < numberOfChefs; ++c)
    {
        changedTemperature += 0.1f;
    }

    std::cout << "It's " << changedTemperature << " degrees in here!" << std::endl;

    return changedTemperature;
}

void Diner::cookEggs(Kitchen thiskitchen)
{
    numberOfTables = numberOfEmployees + thiskitchen.numberOfChefs;
    std::cout << "You've got crumbs all over my " << kitchen.tileType << std::endl;
}

void Diner::serveFood(int tableNumber)
{
    tableNumber += 1;
}

std::string Diner::takeOrders()
{
    return hoursOfOperation + " " + foodSupplier;
}

void Diner::loseRating(int numberOfSpills)
{
    for(int spill = 0; spill < numberOfSpills; ++spill)
    {
        starRating -= 1;
    }
}
/*
copied UDT 2:
*/

struct Cabin
{
    Cabin();
    ~Cabin();

    int numberOfPassengers;
    int numberOfSeats;
    std::string snackType = "Bugles";
    std::string gingerAletype = "Canada Dry";
    float legroomDepth = 0.0f;

    struct FlightAttendant
    {
        FlightAttendant();
        ~FlightAttendant();

        int numberOfEyeballs;
        int numberOfElbows;
        std::string deoderantBrand = "Mitchum";
        std::string favoriteDanceType = "Disco";
        float earSize = 0.0f;

        void dance(float insanityLevel);
        float bendKnee();
        void speak();
        float pourCoffee(float coffeeLevel, int numberOfOrders);
    };

    void dimLights(float newLevel);
    float serveCoffee(FlightAttendant flightAttendant);
    void playMusic();
    float reclineSeat(float maxReclineAngle, bool rearPassengerIsHappy);

    FlightAttendant joseph;
    FlightAttendant nadine;
};

Cabin::Cabin():
numberOfPassengers(50),
numberOfSeats(49)
{   
    std::cout << "Constructing Cabin" << std::endl;
}

Cabin::~Cabin()
{
    std::cout << "Destruct Cabin" << std::endl;
}

Cabin::FlightAttendant::FlightAttendant():
numberOfEyeballs(1),
numberOfElbows(2)
{   
    std::cout << "Constructing Cabin::FlightAttendant" << std::endl;
}

Cabin::FlightAttendant::~FlightAttendant()
{
    std::cout << "Destruct Cabin::FlightAttendant" << std::endl;
}

void Cabin::FlightAttendant::dance(float insanityLevel)
{
    std::cout << "I had like " << insanityLevel << " cups of coffee before this" << std::endl;
}

float Cabin::FlightAttendant::bendKnee()
{
    earSize *= 2.0f;
    return earSize;
}

void Cabin::FlightAttendant::speak()
{
    std::cout << "About what?" << std::endl;
    std::cout << deoderantBrand << " " << favoriteDanceType << std::endl;
}

float Cabin::FlightAttendant::pourCoffee(float coffeeLevel, int numberOfOrders)
{
    for(int order = 0; order < numberOfOrders; ++order)
    {
        if(coffeeLevel > 0.5f)
        {
            std::cout << "Pour cup" << std::endl;
            coffeeLevel -= 0.5f;  
        }
        else
        {
            std::cout << "No more coffee" << std::endl;
            return 0.0f;
        }
    }
    return coffeeLevel;
}

void Cabin::dimLights(float newLevel)
{
    newLevel += legroomDepth;
    std::cout << snackType << " and " << gingerAletype << std::endl;
}

float Cabin::serveCoffee(FlightAttendant flightAttendant)
{
    flightAttendant.bendKnee();
    return legroomDepth;
}

void Cabin::playMusic()
{
    if(numberOfPassengers < numberOfSeats)
    {
        joseph.numberOfEyeballs = 0;
        nadine.numberOfElbows = 0;
    }
}

float Cabin::reclineSeat(float maxReclineAngle, bool rearPassengerIsHappy)
{
    float angle = 0.0f;

    while(angle < maxReclineAngle)
    {
        if(angle > 30.0f)
        {
            rearPassengerIsHappy = false;
        }

        if(rearPassengerIsHappy)
        {
            std::cout << "Recline seat" << std::endl;
            angle += 5.0f;
        }
        else
        {
            std::cout << "No recline" << std::endl;
            return angle;
        }
    }
    return angle;
}
/*
copied UDT 3:
*/
struct Iphone
{
    Iphone();

    std::string operatingSystem;
    float screenSize{8.0f};
    std::string speakerType;
    std::string cameraType;
    float batteryLife = 100.0f;

    void browseTheWeb(std::string url);
    void playMusic(std::string songName);
    void makePhoneCall(int number);
    void shrinkScreen(int magnitude);
};

Iphone::Iphone():
operatingSystem("iOS"),
speakerType("Bose"),
cameraType("Nikon")
{   
    std::cout << "Constructing IPhone" << std::endl;
}

void Iphone::browseTheWeb(std::string url)
{   
    operatingSystem = speakerType + cameraType;
    std::cout << "www." << url << std::endl;
}

void Iphone::playMusic(std::string songName)
{
    screenSize = batteryLife;
    std::cout << speakerType << " " << songName << std::endl;
}

void Iphone::makePhoneCall(int number)
{
    std::cout << "Listen on on " << speakerType << " speakers" << std::endl;
    number += 1;
}

void Iphone::shrinkScreen(int magnitude)
{
    int i = magnitude % 10;
    while(i < 10)
    {
        screenSize -= 0.1f;
        ++i;
    }
}
/*
new UDT 4:
with 2 member functions
*/
struct WishList
{
    WishList();
    ~WishList();

    Cabin myCabin;
    Cabin::FlightAttendant jerry;
    Diner myDiner;
    Diner::Kitchen myKitchen;
    Iphone myPhone;

    void playOnPhone();
    std::string setMood(float lightLevel);
};

WishList::WishList()
{
    myCabin.serveCoffee(jerry);
    std::cout << "Construct WishList. Coffee is served!" << std::endl;
}

WishList::~WishList()
{
    std::cout << "Deconstruct WishList. Please recycle!" << std::endl;
}

void WishList::playOnPhone()
{
    myPhone.batteryLife -= 10.0f;
}

std::string WishList::setMood(float lightLevel)
{
    myCabin.dimLights(lightLevel);
    myCabin.playMusic();
    return "Lights dimmed to " + std::to_string(lightLevel) + " and music playing";
}

/*
new UDT 5:
with 2 member functions
*/
struct SearchHistory
{
    SearchHistory();
    ~SearchHistory();

    Cabin myCabin;
    Cabin::FlightAttendant jerry;
    Diner myDiner;
    Diner::Kitchen myKitchen;
    Iphone myPhone;

    void animateFlightAttendant(float insanityLevel);
    std::string prepEggs(int tableNumber);
};

SearchHistory::SearchHistory()
{
    prepEggs(1);
    std::cout << "Construct SearchEngine. Who doesn't like eggs in the morning?" << std::endl;
}

SearchHistory::~SearchHistory()
{
    std::cout << "Deconstruct WishList" << std::endl;
}

void SearchHistory::animateFlightAttendant(float insanityLevel)
{
    jerry.dance(insanityLevel);
    jerry.bendKnee();
}

std::string SearchHistory::prepEggs(int tableNumber)
{
    myDiner.cookEggs(myKitchen);
    myDiner.serveFood(tableNumber);
    auto hoursAndSupplier = myDiner.takeOrders();

    return "Here's our hours and food supplier " + hoursAndSupplier + ". We served to table " + std::to_string(tableNumber);
}


/*
MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

If you didn't already: 
Make a pull request after you make your first commit
pin the pull request link and this repl.it link to our DM thread in a single message.

send me a DM to review your pull request when the project is ready for review.

Wait for my code review.
*/

int main()
{
    Iphone myPhone;
    Iphone davesPhone;
    Diner jerrys;
    Diner::Kitchen jerrysKitchen;
    Cabin passengersClub;
    Cabin::FlightAttendant jerry;
    Cabin::FlightAttendant jessica;

    myPhone.browseTheWeb("homestarrunner.com");
    myPhone.playMusic("Night Mommas");
    myPhone.makePhoneCall(5551234);

    davesPhone.browseTheWeb("namethatbeard.com");
    davesPhone.playMusic("Sharp Dressed Man");
    davesPhone.makePhoneCall(5559876);

    jerrysKitchen.runFoodDisposal();
    jerrysKitchen.burnToast(1);
    auto kitchenOrder = jerrysKitchen.receiveOrder();
    std::cout << kitchenOrder << std::endl;

    jerrys.serveFood(12);
    jerrys.cookEggs(jerrysKitchen);
    auto tableOrder = jerrys.takeOrders();
    std::cout << "Here's your " << tableOrder << std::endl;

    jerry.dance(7.0f);
    auto jerrysEar = jerry.bendKnee();
    jerry.speak();
    std::cout << "gross me out, " << std::to_string(jerrysEar) << std::endl;

    jessica.dance(14000.0f);
    auto jessicasEar = jessica.bendKnee();
    jessica.speak();
    std::cout << "hear me, " << std::to_string(jessicasEar) << std::endl;

    passengersClub.dimLights(11.0f);
    auto legroom = passengersClub.serveCoffee(jessica);
    passengersClub.playMusic();
    std::cout << "Legroom: " << std::to_string(legroom) << std::endl;

    myPhone.shrinkScreen(15);

    auto temp = jerrysKitchen.addBodyHeat();
    std::cout << "New temp: " << std::to_string(temp) << std::endl;

    jerrys.loseRating(5);

    auto coffeeLevel = jessica.pourCoffee(5.0f, 25);
    std::cout << "coffeeleft: " << std::to_string(coffeeLevel) << std::endl;

    auto angle = passengersClub.reclineSeat(40.0f, true);
    std::cout << "This far back: " << std::to_string(angle) << std::endl;

    WishList wishlist;
    SearchHistory searchHistory;

    wishlist.playOnPhone();
    wishlist.setMood(50.0f);

    searchHistory.animateFlightAttendant(40.0f);
    searchHistory.prepEggs(5);
    
    std::cout << "good to go!" << std::endl;
}
