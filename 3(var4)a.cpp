#include <iostream>

using namespace std;

class Transport
{
protected:
	string name;
	double speed;
	double costPerKm;
public:
	Transport(string newName = " ", double newSpeed = 0, double newCost = 0)
		: name(newName), speed(newSpeed), costPerKm(newCost) {
		cout << "Tranport(base class) contructor\n";
	}

	virtual ~Transport() { cout << "Transport(base class) destructor\n"; }

	virtual void setName(const string& newName) = 0;
	virtual void setSpeed(double newSpeed) = 0;
	virtual void setCostPerKm(double newCost) = 0;

	virtual string getName() const = 0;
	virtual double getSpeed() const = 0;
	virtual double getCost() const = 0;

	virtual double calculateTime(double distance) const = 0;
	virtual double calculateCost(double distance) const = 0;
	virtual void Show() const = 0;
};

class Car : public Transport
{
public:
	Car(string newName = "Car", double newSpeed = 0, double newCost = 0)
		: Transport(newName, newSpeed, newCost) {
		cout << "Car constructor\n";
	}

	~Car() override { cout << "Car destructor\n"; }

	void setName(const string& newName) override { this->name = newName; }
	void setSpeed(double newSpeed) override { this->speed = newSpeed; }
	void setCostPerKm(double newCost) override { this->costPerKm = newCost; }

	string getName() const override { return this->name; }
	double getSpeed() const override { return this->speed; }
	double getCost() const override { return this->costPerKm; }

	double calculateTime(double distance) const override
	{
		if ((distance / speed) > 0)
		{
			return distance / speed;
		}
		else
		{
			return 0;
		}
	}

	double calculateCost(double distance) const override
	{
		if ((distance * costPerKm) > 0)
		{
			return distance * costPerKm;
		}
		else
		{
			return 0;
		}
	}

	void Show() const override
	{
		cout << "Name: " << name << endl;
		if (speed > 0)
		{
			cout << "Speed: " << speed << "km / hour\n";
		}
		else if (speed <= 0)
		{
			cout << "Speed: Invalid value\n";
		}

		if (costPerKm == 0)
		{
			cout << "Cost per km : free\n";
		}
		else if (costPerKm > 0)
		{
			cout << "Cost per km: " << costPerKm << "grn\n";
		}
		else
		{
			cout << "Cost per Km: Invalid value\n";
		}
	}
};

class Bicycle : public Transport
{
public:
	Bicycle(string newName = "Bicycle", double newSpeed = 0, double newCost = 0)
		: Transport(newName, newSpeed, newCost) {
		cout << "Bicycle constructor\n";
	}

	~Bicycle() override { cout << "Bicycle destructor\n"; }

	void setName(const string& newName) override { this->name = newName; }
	void setSpeed(double newSpeed) override { this->speed = newSpeed; }
	void setCostPerKm(double newCost) override { this->costPerKm = newCost; }

	string getName() const override { return this->name; }
	double getSpeed() const override { return this->speed; }
	double getCost() const override { return this->costPerKm; }

	double calculateTime(double distance) const override
	{
		if ((distance / speed) > 0)
		{
			return distance / speed;
		}
		else
		{
			return 0;
		}
	}

	double calculateCost(double distance) const override
	{
		if ((distance * costPerKm) > 0)
		{
			return distance * costPerKm;
		}
		else
		{
			return 0;
		}
	}

	void Show() const override
	{
		cout << "Name: " << name << endl;
		if (speed > 0)
		{
			cout << "Speed: " << speed << "km / hour\n";
		}
		else if (speed <= 0)
		{
			cout << "Speed: Invalid value\n";
		}

		if (costPerKm == 0)
		{
			cout << "Cost per km : free\n";
		}
		else if (costPerKm > 0)
		{
			cout << "Cost per km: " << costPerKm << "grn\n";
		}
		else
		{
			cout << "Cost per Km: Invalid value\n";
		}
	}
};

class Cart : public Transport
{
public:
	Cart(string newName = "Cart", double newSpeed = 0, double newCost = 0)
		: Transport(newName, newSpeed, newCost) {
		cout << "Cart constructor\n";
	}

	~Cart() override { cout << "Cart destructor\n"; }

	void setName(const string& newName) override { this->name = newName; }
	void setSpeed(double newSpeed) override { this->speed = newSpeed; }
	void setCostPerKm(double newCost) override { this->costPerKm = newCost; }

	string getName() const override { return this->name; }
	double getSpeed() const override { return this->speed; }
	double getCost() const override { return this->costPerKm; }

	double calculateTime(double distance) const override
	{
		if ((distance / speed) > 0)
		{
			return distance / speed;
		}
		else
		{
			return 0;
		}
	}

	double calculateCost(double distance) const override
	{
		if ((distance * costPerKm) > 0)
		{
			return distance * costPerKm;
		}
		else
		{
			return 0;
		}
	}

	void Show() const override
	{
		cout << "Name: " << name << endl;
		if (speed > 0)
		{
			cout << "Speed: " << speed << "km / hour\n";
		}
		else if (speed <= 0)
		{
			cout << "Speed: Invalid value\n";
		}

		if (costPerKm == 0)
		{
			cout << "Cost per km : free\n";
		}
		else if (costPerKm > 0)
		{
			cout << "Cost per km: " << costPerKm << "grn\n";
		}
		else
		{
			cout << "Cost per Km: Invalid value\n";
		}
	}
};

int main()
{
	Transport* transports[5] = { new Car("Car1", 180, 80),
								new Bicycle("Bicycle1", 20, 0),
								new Cart("Cart1", 35, 100),
								new Car("Car2", 165, -40),
								new Cart("Cart2", -50, 0) };

	double distance = 150;
	for (int i = 0; i < 5; i++)
	{
		transports[i]->Show();
		cout << "Time: " << transports[i]->calculateTime(distance) << "hours\n";
		cout << "Cost: " << transports[i]->calculateCost(distance) << "grn\n";
		cout << "-----------------------------------------------------------\n";
	}
}