#include <iostream>

/*
������� ����� Car (����������) � ������ company (��������) � model (������). 
������-����������: PassengerCar (�������� ����������) � Bus (�������). 
�� ���� ������� ��������� ����� Minivan (�������). 
������� ������������ ��� ������� �� �������, ����� ��� �������� ������ � �������. 
������� ������� ��� ������� �� ������� � ����������, � ����� ������������������ ����������� ������������. 
�������� �������� �� �������� ������ ������.
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
		std::cout << "���������� �������� " + getCompany() + " ������ " + getModel() << std::endl;
	}

};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "�������� ���������� �������� " + getCompany() + ", ������ " + getModel() << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "������������� ��� �������� " + getCompany() + ", ������ " + getModel() << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model) : 
		Car(company, model), PassengerCar(company, model), Bus(company, model)
	{
		std::cout << "������������� ��� �������� " + getCompany() + ", ������ " + getModel() << std::endl;
	}
};

int main()
{
	Minivan m("GEEKGRAIN", "MERS");

	
	return 0;
}