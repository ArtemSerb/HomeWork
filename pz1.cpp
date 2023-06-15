#include <iostream>
 #include <cmath>
  class Triangle { 
  private: 
        double side1; 
		double side2; 
		double side3; 
	public: 
	    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
	    // ������ ��� ���������� ���� ������ 
		double getSide1() const { return side1; } 
		double getSide2() const { return side2; } 
		double getSide3() const { return side3; }
	    // ����� ��� ���������� ������� ������������ �� ������� ������ 
		double calculateArea() const { 
		    double semiPerimeter = calculatePerimeter() / 2.0;
		    return sqrt(semiPerimeter * 
			           (semiPerimeter - side1) * 
					   (semiPerimeter - side2) * 
					   (semiPerimeter - side3)); 
		}
		// ����� ��� ����������� ���� ������������ (�������������, �������������, ������������) 
		std::string determineType() const { 
		    double angleA = calculateAngleA(); 
		    double angleB = calculateAngleB(); 
			double angleC = calculateAngleC(); 
			if (angleA == 90.0 || angleB == 90.0 || angleC == 90.0) 
			    return "������������� �����������"; 
			else if (angleA < 90.0 && angleB < 90.0 && angleC < 90.0) 
			    return "������������� �����������"; 
			else 
			    return "������������ �����������"; 
		}
		// ������ ��� ���������� ����� ������������ � �������������� ������� ���������
		double calculateAngleA() const { 
		    return acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
		} 
		double calculateAngleB() const { 
		    return acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)); 
		} double calculateAngleC() const { 
		    return acos((side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2)); 
		}
		// ����� ��� ���������� ��������� ������������ 
		double calculatePerimeter() const { 
		    return side1 + side2 + side3; 
		} 
	};
	int main() { 
	    double side1, side2, side3; 
		std::cout � "������� ����� ������ ������������: "; 
		std::cin � side1 � side2 � side3; 
		Triangle triangle(side1, side2, side3);
		std::cout � "��������: " � triangle.calculatePerimeter() � std::endl; 
		std::cout � "�������: " � triangle.calculateArea() � std::endl; 
		std::cout � "��� ������������" � triangle.determineType() � std::endl;
		std::cout � "����� ������: " � triangle.getSide1() � ", " � triangle.getSide2() � ", " � triangle.getSide3() � std::endl;
		std::cout � "���� ������������: " � triangle.calculateAngleA() � ", " � triangle.calculateAngleB() � ", " � triangle.calculateAngleC() � std::endl;
