/*
	Jonathan Truong
	CPSC 121-19
	02/19/20
	Lab 04 - Classes (Tamagotchi)
*/

#include <iostream> //header
#include <time.h> //header
#include <string> //header
using namespace std;

class Tamagotchi
{
	//private function cannot be changed by anyone
private:
	string name;
	int hunger;
	int happiness;
	int age;

	//anyone can use the public function
public:
	Tamagotchi()
	{
		hunger = rand() % 5 + 1;
		happiness = rand() % 5 + 1;
		age = 0;
	}
	//this function lets the user assign the name
	void setName(string c)
	{
		name = c;
	}
	//this gets the name from the class
	//while being used in the main
	string getName()
	{
		return name;
	}
	//this retrieves the hunger value of the Tamagotchi
	int getHungry()
	{
		return hunger;
	}
	//this retrieves the happy value of the Tamagotchi
	int getHappy()
	{
		return happiness;
	}
	//this retrieves the age of the Tamagotchi
	int tamAge()
	{
		return age;
	}
	//this allows a plus one increase to the hunger value
	void goFeed()
	{
		cout << "Yummm yumm yummmmy!!" << name << " ate the delicious food. (+1 HUNGER)" << endl;
		hunger++;
	}

	//this function increases the happiness value by 1
	void goPlay()
	{
		cout << "HELLO, let us have the time of our lives!!" << name << " wants to PLAY!! (+1 HAPPINESS)" << endl;
		happiness++;
	}

	//this decreases the hunger by 1 if the value is 0
	//this function decreases the happiness by 1 if the value is 1
	void isDecrease()
	{
		int anyNum = rand() % 2;
		if (anyNum == 0)
		{
			cout << name << " gets to eat. (-1 Hunger)" << endl;
			hunger--;
		}
		else
		{
			cout << name << " needs attention and wants to have a good day. (-1 Happiness)" << endl;
			happiness--;
		}
		age++;
	}
	//this function displays the Tamagotchi's stats
	void displayAttributes()
	{
		cout << "--" << name << "'s stats--" << endl;
		cout << "Hunger: " << hunger << endl;
		cout << "Happiness: " << happiness << endl;
		cout << "Age: " << age << endl;
	}
	//this function allows the user the option
	//to either feed or play with the Tamagotchi
	char theMenu()
	{
		char option;
		cout << "Main Menu:" << endl;
		cout << "1. Feed" << endl;
		cout << "2. Play" << endl;
		cout << "Choose either (1 or 2)" << endl;
		cin >> option;
		return option;
	}
};

int main()
{
	srand(time(0));
	string name;
	char option;
	cout << "-Virtual Orangutan-" << endl;
	cout << "---- - m------m------" << endl;
	cout << "       @(o.o)@" << endl;
	cout << "         (0)~~" << endl;
	cout << "         o o" << endl;
	cout << "Please input a name for your pet Orangutan: " << endl;
	cin >> name;
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
		if (option == '2')
		{
			Name.goPlay();
			Name.isDecrease();
		}
	} while (Name.tamAge() <= 5 && Name.Hungry() > 0 && Name.Happy() > 0);
	//this function allows the Tamagotchi
	//to have the age limit be up to 5
	//after that it will be gone :(
	if (Name.tamAge() > 5)
	{
		cout << "This very moment, we lost a true hero but " << name << " was very old. RIP homie " << name << "!!!!" << endl;
	}
	//this function allows the happiness or hunger of 
	//the Tamagotchi to reach 0
	//which will lead to its passing
	if (Name.Happy() == 0 || Name.Hungry() == 0)
	{
		cout << "Why did you let it go like that?" << name << " was such an honorble!!!" << endl;
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