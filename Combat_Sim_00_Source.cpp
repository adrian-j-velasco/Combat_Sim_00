#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Bipedal {
public:
	Bipedal();
	Bipedal(int hp, int ap, float hc);
	
	int gethP() const;
	int getaP() const;
	float gethC() const;

	Bipedal & sethP(int hp);
	Bipedal & setaP(int ap);
	Bipedal & gethC(float hc);
private:
	int healthPoints;
	int attackPoints;
	float hitChance;
};

void die(const string & msg);


int main()
{
	mt19937 randomGenerator(time(NULL));
	uniform_real_distribution<float> attackRoll(0.0f,1.0f);

	cout << "I am rolling a " << attackRoll(randomGenerator) << endl;

	system("PAUSE");
	return 0;
}

void die(const string & msg)
{
	cerr << "Fatal error: " << msg << endl;
	exit(EXIT_FAILURE);
}

Bipedal::Bipedal():healthPoints(0),attackPoints(0),hitChance(0.0f){}

Bipedal::Bipedal(int hp, int ap, float hc)
{
	healthPoints = hp;
	attackPoints = ap;
	hitChance = hc;
}

int Bipedal::gethP() const 
{
	return healthPoints;
}

int Bipedal::getaP() const
{
	return attackPoints;
}

float Bipedal::gethC() const
{
	return hitChance;
}

Bipedal & Bipedal::sethP(int hp)
{
	healthPoints = hp;
	return *this;
}

Bipedal & Bipedal::setaP(int ap)
{
	attackPoints = ap;
	return *this;
}

Bipedal & Bipedal::gethC(float hc)
{
	hitChance = hc;
	return *this;
}