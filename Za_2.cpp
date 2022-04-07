#include <iostream>

/*
Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти».
*/


class Car
{
private:
	std::string m_company;
	std::string m_model;
protected:
	std::string getCompany() { return m_company; }
	std::string getModel() { return m_model; }
public:
	Car(std::string company, std::string model) : m_company(company), m_model(model)
	{
		std::cout << "Автомобиль компании " + getCompany() + " модель " + getModel() << std::endl;
	}

};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "Легковой автомобиль компании " + getCompany() + ", модель " + getModel() << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "Автомобильный бус компании " + getCompany() + ", модель " + getModel() << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model) : 
		Car(company, model), PassengerCar(company, model), Bus(company, model)
	{
		std::cout << "Автомобильный бус компании " + getCompany() + ", модель " + getModel() << std::endl;
	}
};

int main()
{
	Minivan m("GEEKGRAIN", "MERS");

	
	return 0;
}