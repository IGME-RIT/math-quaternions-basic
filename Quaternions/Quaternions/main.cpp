#include "Quaternion.h"
#include <iostream>

int main()
{
	Quaternion q = Quaternion(10, 1, 1, 4);
	Quaternion l = Quaternion(10, 4, 5, 9);

	float s = 10.0f;
	float r = 5.0f;

	std::cout << "======THE QUATERNION OPERATIONS======" << std::endl;

	std::cout << "The sum of two Quaternions: " << std::endl;
	std::cout << q + l << std::endl;

	std::cout << "The difference of two Quaternions: " << std::endl;
	std::cout << q - l << std::endl;

	std::cout << "The product of two Quaternions: " << std::endl;
	std::cout << q * l << std::endl;

	std::cout << "The division of two Quaternions: " << std::endl;
	std::cout << q / l << std::endl;

	std::cout << "Conjugate of the Quaternion is: " << std::endl;
	std::cout << Conjugate(q) << std::endl;

	std::cout << "The inverse of the Quaternion is: " << std::endl;
	std::cout << Inverse(q) << std::endl;

	std::cin.get();
}