/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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
        void printGrillBrand();
    };

    void cookEggs(Kitchen thiskitchen);
    void serveFood(int tableNumber);
    std::string takeOrders(); 
    void loseRating(int numberOfSpills);
    void printFoodSupplier();

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

float Diner::Kitchen::addBodyHeat()
{

    float changedTemperature = temperature;

    for(int c = 0; c < numberOfChefs; ++c)
    {
        changedTemperature += 0.1f;
    }

    std::cout << "It's " << changedTemperature << " degrees in here!" << std::endl;

    return changedTemperature;
}

void Diner::Kitchen::printGrillBrand()
{
    std::cout << "Kitchen grillBrand: " << this->grillBrand << std::endl;
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

void Diner::printFoodSupplier()
{
    std::cout << "Diner foodSupplier: " << this->foodSupplier << std::endl;
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
        void printDeoderantBrand();
        void printEarSize();
    };

    void dimLights(float newLevel);
    float serveCoffee(FlightAttendant flightAttendant);
    void playMusic();
    float reclineSeat(float maxReclineAngle, bool rearPassengerIsHappy);
    void printGingerAletype();

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

void Cabin::FlightAttendant::printDeoderantBrand()
{
    std::cout << "FlightAttendant deoderantBrand: " << this->deoderantBrand << std::endl;
}

void Cabin::FlightAttendant::printEarSize()
{
    std::cout << "FlightAttendant earSize: " << std::to_string(this->earSize) << std::endl;
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

void Cabin::printGingerAletype()
{
    std::cout << "Cabin gingerAletype: " << this->gingerAletype << std::endl;
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
    void printBatteryLife();
    void printCameraType();
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

void Iphone::printBatteryLife()
{
    std::cout << "iPhone batteryLife: " << std::to_string(this->batteryLife) << std::endl;
}

void Iphone::printCameraType()
{
    std::cout << "iPhone cameraType: " << this->cameraType << std::endl;
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

    std::cout << "iPhone batteryLife: " << std::to_string(myPhone.batteryLife) << std::endl;
    std::cout << "iPhone cameraType: " << davesPhone.cameraType << std::endl;
    std::cout << "Kitchen grillBrand: " << jerrysKitchen.grillBrand << std::endl;
    std::cout << "Diner foodSupplier: " << jerrys.foodSupplier << std::endl;
    std::cout << "FlightAttendant deoderantBrand: " << jerry.deoderantBrand << std::endl;
    std::cout << "FlightAttendant earSize: " << std::to_string(jessica.earSize) << std::endl;
    std::cout << "Cabin gingerAletype: " << passengersClub.gingerAletype << std::endl;

    myPhone.printBatteryLife();
    davesPhone.printCameraType();
    jerrysKitchen.printGrillBrand();
    jerrys.printFoodSupplier();
    jerry.printDeoderantBrand();
    jessica.printEarSize();
    passengersClub.printGingerAletype();
    
    std::cout << "good to go!" << std::endl;
}
