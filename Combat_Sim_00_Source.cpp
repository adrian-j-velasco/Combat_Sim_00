#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Bipedal 
{
public:
	Bipedal();
	Bipedal(int hp, int ap, int n, float hc);
	
	int gethP() const;
	int getaP() const;
	int getnE() const;
	float gethC() const;

	Bipedal & sethP(int hp);
	Bipedal & setaP(int ap);
	Bipedal & setnE(int nE);
	Bipedal & sethC(float hc);
private:
	int healthPoints;
	int attackPoints;
	int numEls;
	float hitChance;
};

void die(const string & msg);

int main()
{
	mt19937 randomGenerator(time(0));
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

	int numHum, numSkel;
	Bipedal Humans;	//	hp: 10, ap: 3, hc: 0.9
	Bipedal Skeletons;	//	hp: 6, ap: 2, hc: 0.45

	cout << "*** Humans Vs Skeletons ***\n*** Combat Sim 00 ***\n";
	cout << "Input the number of Humans\n";	//	No checks lol
	cin >> numHum;
	Humans.sethP(10).setaP(3).sethC(0.9).setnE(numHum);

	cout << "Input the number of Skeletons\n";	//	No checks lol
	cin >> numSkel;
	Skeletons.sethP(6).setaP(2).sethC(0.45).setnE(numSkel);
	
	cout <<endl<< "Begin Combat!\n";
	cout << endl << "Combat Noises!\n";
	while( Humans.getnE() > 0 && Skeletons.getnE() > 0)
	{
		static int turn = 1;
		cout << endl << "Turn " << turn << "!\n";
		turn++;
		float flip = attackRoll(randomGenerator);
		//cout << endl << flip << endl;
		if (flip >= 0.5)	//	Humans attack
		{
			float humanFlip = attackRoll(randomGenerator);
			//cout << endl << humanFlip << endl;
			if (Humans.gethC() >= humanFlip)	//	Human Attack succesful
			{
				cout << "Humans attack!\n";
				int hp = Skeletons.gethP();
				hp = hp - Humans.getaP();
				Skeletons.sethP(hp);

				if (Skeletons.gethP() == 0)
				{
					cout << "A Skeleton has fallen!\n";
					Skeletons.sethP(6);
					Skeletons.setnE(Skeletons.getnE() - 1);
				}
			}
			else
			{
				cout << "Humans miss!\n";
			}
		}
		else	//	Skeletons attack
		{
			float skelFlip = attackRoll(randomGenerator);
			//cout << endl << skelFlip << endl;
			if (Skeletons.gethC() >= skelFlip)	//	Skeleton attack succesful
			{
				cout << "Skeletons attack!\n";
				int hp = Humans.gethP();
				hp = hp - Skeletons.getaP();
				Humans.sethP(hp);
			}
			else
			{
				cout << "Skeletons miss!\n";
			}

			if (Humans.gethP() == 0)
			{
				cout << "A Human has fallen!\n";
				Humans.sethP(10);
				Humans.setnE(Humans.getnE() - 1);
			}
		}
	}

	if (Humans.getnE() == 0)
	{
		cout << endl << "Skeletons Win!\n";
		cout << "There are " << Skeletons.getnE() << " skeletons left\n";
	}
	else
	{
		cout << endl << "Humans Win!\n";
		cout << "There are " << Humans.getnE() << " Humans left\n";
	}

	system("PAUSE");
	return 0;
}

void die(const string & msg)
{
	cerr << "Fatal error: " << msg << endl;
	exit(EXIT_FAILURE);
}

Bipedal::Bipedal():healthPoints(0),attackPoints(0),numEls(0),hitChance(0.0f){}

Bipedal::Bipedal(int hp, int ap, int n, float hc)
{
	healthPoints = hp;
	attackPoints = ap;
	numEls = n;
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

int Bipedal::getnE() const
{
	return numEls;
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

Bipedal & Bipedal::setnE(int n)
{
	numEls = n;
	return *this;
}

Bipedal & Bipedal::sethC(float hc)
{
	hitChance = hc;
	return *this;
}