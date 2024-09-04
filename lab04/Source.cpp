/*
	Jonathan Truong
	CPSC 121-19
	02/19/20
	Lab 04 - Classes (Tamagotchi)
*/

#include <iostream>
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
#include <string>   // for string

using namespace std;

class Tamagotchi
{
private:
    string name;
    int hunger;
    int happiness;
    int age;

public:
    // Constructor initializes the Tamagotchi
    Tamagotchi()
    {
        hunger = rand() % 5 + 1;
        happiness = rand() % 5 + 1;
        age = 0;
    }

    // Set the name of the Tamagotchi
    void setName(const string& c)
    {
        name = c;
    }

    // Get the name of the Tamagotchi
    string getName() const
    {
        return name;
    }

    // Get the hunger level of the Tamagotchi
    int getHunger() const
    {
        return hunger;
    }

    // Get the happiness level of the Tamagotchi
    int getHappiness() const
    {
        return happiness;
    }

    // Get the age of the Tamagotchi
    int getAge() const
    {
        return age;
    }

    // Feed the Tamagotchi
    void goFeed()
    {
        cout << "Yummm yumm yummmmy!! " << name << " ate the delicious food. (+1 HUNGER)" << endl;
        hunger++;
    }

    // Play with the Tamagotchi
    void goPlay()
    {
        cout << "HELLO, let us have the time of our lives!! " << name << " wants to PLAY!! (+1 HAPPINESS)" << endl;
        happiness++;
    }

    // Decrease either hunger or happiness
    void isDecrease()
    {
        int anyNum = rand() % 2;
        if (anyNum == 0)
        {
            cout << name << " gets hungrier. (-1 Hunger)" << endl;
            hunger--;
        }
        else
        {
            cout << name << " needs attention and wants to have a good day. (-1 Happiness)" << endl;
            happiness--;
        }
        age++;
    }

    // Display the Tamagotchi's attributes
    void displayAttributes() const
    {
        cout << "--" << name << "'s stats--" << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Age: " << age << endl;
    }

    // Show the menu and get the user's choice
    char theMenu() const
    {
        char option;
        cout << "Main Menu:" << endl;
        cout << "1. Feed" << endl;
        cout << "2. Play" << endl;
        cout << "Choose either (1 or 2): ";
        cin >> option;
        return option;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator
    string name;
    char option;
    cout << "-Virtual Orangutan-" << endl;
    cout << "---- - m------m------" << endl;
    cout << "       @(o.o)@" << endl;
    cout << "         (0)~~" << endl;
    cout << "         o o" << endl;
    cout << "Please input a name for your pet Orangutan: ";
    cin >> name;
    cin.ignore();  // Clear newline left in the input buffer

    Tamagotchi Name;
    Name.setName(name);

    do
    {
        Name.displayAttributes();
        option = Name.theMenu();
        if (option == '1')
        {
            Name.goFeed();
            Name.isDecrease();
        }
        else if (option == '2')
        {
            Name.goPlay();
            Name.isDecrease();
        }
        else
        {
            cout << "Invalid choice. Please choose 1 or 2." << endl;
        }
    } while (Name.getAge() <= 5 && Name.getHunger() > 0 && Name.getHappiness() > 0);

    // Check the status of the Tamagotchi
    if (Name.getAge() > 5)
    {
        cout << "This very moment, we lost a true hero but " << name << " was very old. RIP homie " << name << "!!!!" << endl;
    }
    else if (Name.getHappiness() <= 0 || Name.getHunger() <= 0)
    {
        cout << "Why did you let it go like that? " << name << " was such an honorable!!!" << endl;
    }

    system("PAUSE");
    return 0;
}

/*
-Virtual Orangutan-
---- - m------m------
	   @(o.o)@
		 (0)~~
		 o o
Please input a name for your pet Orangutan:
Joknee
--Joknee's stats--
Hunger: 4
Happiness: 2
Age: 0
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
1
Yummm yumm yummmmy!!Joknee ate the delicious food. (+1 HUNGER)
Joknee gets to eat. (-1 Hunger)
--Joknee's stats--
Hunger: 4
Happiness: 2
Age: 1
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
2
HELLO, let us have the time of our lives!!Joknee wants to PLAY!! (+1 HAPPINESS)
Joknee gets to eat. (-1 Hunger)
--Joknee's stats--
Hunger: 3
Happiness: 3
Age: 2
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
2
HELLO, let us have the time of our lives!!Joknee wants to PLAY!! (+1 HAPPINESS)
Joknee needs attention and wants to have a good day. (-1 Happiness)
--Joknee's stats--
Hunger: 3
Happiness: 3
Age: 3
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
1
Yummm yumm yummmmy!!Joknee ate the delicious food. (+1 HUNGER)
Joknee needs attention and wants to have a good day. (-1 Happiness)
--Joknee's stats--
Hunger: 4
Happiness: 2
Age: 4
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
2
HELLO, let us have the time of our lives!!Joknee wants to PLAY!! (+1 HAPPINESS)
Joknee gets to eat. (-1 Hunger)
--Joknee's stats--
Hunger: 3
Happiness: 3
Age: 5
Main Menu:
1. Feed
2. Play
Choose either (1 or 2)
2
HELLO, let us have the time of our lives!!Joknee wants to PLAY!! (+1 HAPPINESS)
Joknee gets to eat. (-1 Hunger)
This very moment, we lost a true hero but Joknee was very old. RIP homie Joknee!!!!
*/