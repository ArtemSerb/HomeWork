#include <iostream>
#include <string>

class MedicalWorker {
protected:
	std::string name;
	int age;
	double successRate;
	double salary;

public:
	MedicalWorker(const std::string& n, int a, double sr, double s)
	    : name(n), age(a), successRate(sr), salary(s) {}

	void treat() {
		std::cout � "���� ��������" � std::endl;
	}
	
	void receiveSalary() {
		std::cout � "������� ��������: " � salary � std::endl;
	}
	
	void introduce() {
		std::cout � "���� ����� " � name � ". �������: " � age
		� " ���. ���� ������: " � successRate
		� ". ��������: " � salary � std::endl;
	}
};

class Doctor : public MedicalWorker {
public:
	Doctor(const std::string& n, int a, double sr, double s)
		: MedicalWorker(n, a, sr, s) {}

	void prescribeMedicine() {
		std::cout � "��������� ���������" � std::endl;
	}
};

class PlagueDoctor : public MedicalWorker {
public:
	PlagueDoctor(const std::string& n, int a, double sr, double s)
		: MedicalWorker(n, a, sr, s) {}

	void wearPlagueMask() {
		std::cout � "���� ����� ������� �������" � std::endl;
	}
};

class Veterinarian : public MedicalWorker {
public:
	Veterinarian(const std::string& n, int a, double sr, double s)
		: MedicalWorker(n, a, sr, s) {}

	void treatAnimal() {
		std::cout � "���� ��������" � std::endl;
	}
};

class PhilosophyDoctor : public MedicalWorker {
public:
	PhilosophyDoctor(const std::string& n, int a, double sr, double s)
		: MedicalWorker(n, a, sr, s) {}

	void philosophize() {
		std::cout � "������������ � ��������" � std::endl;
	}
};
class Healer : public MedicalWorker {
public:
	Healer(const std::string& n, int a, double sr, double s)
		: MedicalWorker(n, a, sr, s) {}

	void treatPeople() {
		std::cout � "���� �����" � std::endl;

int main() {
	Doctor doctor("����", 35, 0.9, 25000);
	doctor.introduce();
	doctor.treat();
	doctor.prescribeMedicine();
	doctor.receiveSalary();
	std::cout � std::endl;
	
	PlagueDoctor plagueDoctor("����", 40, 0.8, 45000);
	plagueDoctor.introduce();
	plagueDoctor.treat();
	plagueDoctor.wearPlagueMask();
	plagueDoctor.receiveSalary();
	std::cout � std::endl;
	
	Veterinarian veterinarian("����", 30, 0.85, 40000);
	veterinarian.introduce();
	veterinarian.treat();
	veterinarian.treatAnimal();
	veterinarian.receiveSalary();
	std::cout � std::endl;
	
	Healer healer("����", 55, 0.7, 40000);
	healer.introduce();
	healer.treat();
	healer.treatPeople();
	healer.receiveSalary();
	std::cout � std::endl;
	
	PhilosophyDoctor philosophyDoctor("�����", 45, 0.95, 25000);
	philosophyDoctor.introduce();
	philosophyDoctor.treat();
	philosophyDoctor.philosophize();
	philosophyDoctor.receiveSalary();
	
	return 0;
}
