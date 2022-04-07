#include <iostream>


/*
3. Создать класс: Fraction (дробь). 
Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
*/


class Fraction
{
private:
	bool m_zero;
	bool m_integer;
	int numerator;
	int denominator;

	int GreatCD(int n_1, int n_2)

	{
		int div;
		if (n_1 == n_2)  return n_1;
		int d = n_1 - n_2;
		if (d < 0)
		{
			d = -d;
			div = GreatCD(n_1, d);
		}
		else
			div = GreatCD(n_2, d);

		return div;
	}

		int GreatCM(int n_1, int n_2)
	{
		return n_1 * n_2 / GreatCD(n_1, n_2);
	}

	void reduceFraction(int& a, int& b)
	{
		int divisor = GreatCD(abs(a), abs(b));
		a = a / divisor;
		b = b / divisor;
	}
public:
	Fraction() : numerator(0), denominator(0)
	{
		m_zero = true;
		m_integer = true;
	}

	Fraction(int num, int dnum) : numerator(num), denominator(dnum)
	{
		if (numerator == 0 || denominator == 0)
		{
			std::cout << "Числитель или знаменатель != 0!\n"
				<< "Число будет инициализировано нулём!" << std::endl;
			numerator = 0;
			denominator = 0;
			m_zero = true;
			m_integer = true;
		}
		else
		{
			m_zero = false;
			m_integer = (abs(numerator) == abs(denominator) || denominator == 1);
		}
	}

	friend std::ostream& operator<<(std::ostream&, const Fraction&);

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	Fraction operator-() const;

	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator<(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<=(const Fraction&);
};

std::ostream& operator<<(std::ostream& s, const Fraction& f)
{
	if (f.m_integer)
	{
		if (f.m_zero)
			s << f.numerator;
		else
			s << f.numerator / f.denominator;
	}
	else
		s << f.numerator << '/' << f.denominator;

	return s;
}

Fraction Fraction::operator+(const Fraction& f)
{
	if (f.m_zero)
		return Fraction(numerator, denominator);

	if (m_zero)
		return Fraction(f.numerator, f.denominator);

	int new_denominator = GreatCD(denominator, f.denominator);
	int new_numerator = numerator * (new_denominator / denominator) + f.numerator * (new_denominator / f.denominator);

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator-(const Fraction& f)
{
	if (f.m_zero)
		return Fraction(numerator, denominator);

	if (m_zero)
		return Fraction(-f.numerator, f.denominator);

	int new_denominator = GreatCD(denominator, f.denominator);
	int new_numerator = numerator * (new_denominator / denominator) - f.numerator * (new_denominator / f.denominator);

	if (new_numerator == 0)
		return Fraction();

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator*(const Fraction& f)
{
	if (m_zero || f.m_zero)
		return Fraction();

	int new_numerator = numerator * f.numerator;
	int new_denominator = denominator * f.denominator;

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator/(const Fraction& f)
{
	if (f.m_zero)
	{
		std::cout << " [На 0 делить нельзя!] ";
		return Fraction();
	}

	if (m_zero)
		return Fraction();

	return *this * Fraction(f.denominator, f.numerator);
}

Fraction Fraction::operator-() const
{
	return Fraction(-numerator, denominator);
}

bool Fraction::operator==(const Fraction& f)
{
	if (m_zero || f.m_zero)
		return numerator == f.numerator;

	int a_n = numerator;
	int a_d = denominator;

	int b_n = f.numerator;
	int b_d = f.denominator;

	reduceFraction(a_n, a_d);
	reduceFraction(b_n, b_d);

	return a_n == b_n && a_d == b_d;
}

bool Fraction::operator!=(const Fraction& f)
{
	return !(*this == f);
}

bool Fraction::operator<(const Fraction& f)
{
	if (m_zero || f.m_zero)
		return numerator < f.numerator;

	int new_denominator = GreatCD(denominator, f.denominator);
	int a_n = numerator * (new_denominator / denominator);
	int b_n = f.numerator * (new_denominator / f.denominator);

	return a_n < b_n;
}

bool Fraction::operator>=(const Fraction& f)
{
	return (*this == f || !(*this < f));
}

bool Fraction::operator>(const Fraction& f)
{
	return (*this != f && !(*this < f));
}

bool Fraction::operator<=(const Fraction& f)
{
	return (*this == f || *this < f);
}


int main()
{
	Fraction a(3, 9);
	Fraction b(2, 3);
	Fraction c; // 0

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "[a + b] " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "[a - b] " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "[a * b] " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "[a / b] " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "[c + b] " << c << " + " << b << " = " << c + b << std::endl;
	std::cout << "[b + c] " << b << " + " << c << " = " << b + c << std::endl;
	std::cout << "[c - b] " << c << " - " << b << " = " << c - b << std::endl;
	std::cout << "[b - c] " << b << " - " << c << " = " << b - c << std::endl;
	std::cout << "[c * b] " << c << " * " << b << " = " << c * b << std::endl;
	std::cout << "[b * c] " << b << " * " << c << " = " << b * c << std::endl;
	std::cout << "[c / b] " << c << " / " << b << " = " << c / b << std::endl;
	std::cout << "[b / c] " << b << " / " << c << " = " << b / c << std::endl;
	std::cout << "-a = " << -a << std::endl;
	std::cout << "[a == b] " << a << " == " << b << " is " << ((a == b) ? "true" : "false") << std::endl;
	std::cout << "[a != b] " << a << " != " << b << " is " << ((a != b) ? "true" : "false") << std::endl;
	std::cout << "[a < b]  " << a << " < " << b << " is " << ((a < b) ? "true" : "false") << std::endl;
	std::cout << "[a <= b] " << a << " <= " << b << " is " << ((a <= b) ? "true" : "false") << std::endl;
	std::cout << "[a > b]  " << a << " > " << b << " is " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << "[a >= b] " << a << " >= " << b << " is " << ((a >= b) ? "true" : "false") << std::endl;
	std::cout << "[c == a] " << c << " == " << a << " is " << ((c == a) ? "true" : "false") << std::endl;
	std::cout << "[c != a] " << c << " != " << a << " is " << ((c != a) ? "true" : "false") << std::endl;
	std::cout << "[c < a]  " << c << " < " << a << " is " << ((c < a) ? "true" : "false") << std::endl;
	std::cout << "[c <= a] " << c << " <= " << a << " is " << ((c <= a) ? "true" : "false") << std::endl;
	std::cout << "[c > a]  " << c << " > " << a << " is " << ((c > a) ? "true" : "false") << std::endl;
	std::cout << "[c >= a] " << c << " >= " << a << " is " << ((c >= a) ? "true" : "false") << std::endl;

	return 0;
}





