#include <iostream>
#include <math.h>



/*
* ������� ����������� ����� Figure (������).
��� ������������ �������� ������ Parallelogram (��������������) � Circle (����).
����� Parallelogram � ������� ��� ������� Rectangle (�������������), Square (�������), Rhombus (����).
��� ���� ������� ������� ������������.
��� ������ Figure �������� ����� ����������� ������� area() (�������).
�� ���� ��������� ������� �������������� ��� �������, ������ �� �������������� ������ ���������� �������.
*/



#define PI 3.14159265358979323846
class Figure
{
public:
    virtual float area() { return 0; }

};

class Parallelogramm : public Figure
{
private:
    float m_side1; // 1-� ������� 
    float m_side2; // 2-� ������� 
    float m_height; // �������� ������
protected:
    float getSide1()
    {
        return m_side1;
    }
    float getSide2()
    {
        return m_side2;
    }
    float getHeight()
    {
        return m_height;
    }

public:
    Parallelogramm(float side1, float side2, float height)
        : m_side1(side1), m_side2(side2), m_height(height) {}
    float area()
    {
        float area = m_side1 * m_height;
        std::cout << "������� ��������������� = " << area << std::endl;
        return area;
    }
};

class Circle : public Figure
{
private:
    float m_radius; //������
public:
    Circle(float radius) : m_radius(radius) {}
    float area()
    {
        float area = PI * (m_radius * m_radius);
        std::cout << "������� ����� = " << area << std::endl;
        return area;
    }
};

class Rectangel : public Parallelogramm
{
public:
    Rectangel(float side1, float side2) : Parallelogramm(side1, side2, side2) {}

    float area()
    {
        float area = getSide1() * getSide2();
        std::cout << "������� �������������� = " << area << std::endl;
        return area;
    }

};

class Square : public Parallelogramm
{
public:
    Square(float side1, float side2) : Parallelogramm(side1, side1, side1) {}
    float area()
    {
        float area = getSide1() * getSide2();
        std::cout << "������� �������� = " << area << std::endl;
        return area;
    }
};

class Rhombus : public Parallelogramm
{
public:
    Rhombus(float side1, float height) : Parallelogramm(side1, side1, height) { }

    float area()
    {
        float area = getSide1() * getHeight();
        std::cout << "������� ����� = " << area << std::endl;
        return area;
    }
};

int main()
{
    Parallelogramm c0(2, 4, 6);
    Circle c1(2.2);
    Square c2(2.0, 4.9);
    Rhombus c3(2.2, 4.3);
   
    return 0;
}