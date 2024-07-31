/*Here, we define a class of complex numbers with imaginary and real parts
and doing BIG FIVE and some operation and manipulation on them*/

#include <iostream>	
#include <cmath>	

using namespace std;

class complex {
private:
	double re, im;				//re for real and im for imaginary

public:
	complex() : re{ 0 }, im{ 0 } {}	//default constructor
	complex(double r=0, double i=0) : re{ r }, im{ i } {}	//function: construct from two scalar
	complex(double r) : re{ r }, im{ 0 } {}			//construct from one scalar
	complex(const complex& z) :re{ z.re }, im{ z.im } {}//copy constrcutor
	~complex() = default;						//destructor

	//Function to add together complex number (part to part)
	complex& operator+=(complex z) {
		re += z.re;
		im += z.im;
		return *this;
	}

	//Function to add subtract the complex numbers
	complex& operator-=(const complex& z) {
		re -= z.re;
		im -= z.im;
		return *this;
	}


	//Function to multiply the parts of two complex number 
	complex& operator*=(complex z) {                    
		re *= z.re;
		im *= z.im;
		return *this;
	}
	//Function to divide the parts of complex numbers
	complex& operator /=(complex z){
		re /= z.re;
		im /= z.im;
		return *this;
	}

	//magnitude function needed for calculating the LOGARITHM of complex numbers
	double magnitude() const {
		return sqrt(re * re + im + im);
	}

	//Function to calculate the aangle of the complex number in radian
	double ang_rad()const {
		return atan2(im, re);
	}

	//Function to calc angle which its tangent is the magnitude of the complex number
	complex log() const {
		double mag = magnitude();
		double arg = ang_rad();
		return complex(std::log(mag), arg);
	}

	double real()const { return re; }			//ACCESSOR to real part
	void real(double d) { re = d; }             //function to change real part with an input : mutator
	double imaginary()const { return im; }		//ACCESSOR to imaginary part
	void imaginary(double s) { im = s; }		//function to change:mutate the imaginary paert
};

int main() {
	
	//testing the log function		
	complex v1(3, 9);
	auto ans = v1.log();						
	cout << "Log of " << v1.real() << "+" << v1.imaginary() << "i= " << ans.real() << "+" << ans.imaginary() << "i" << endl;

	//Testing the multipication function
	complex v2(4, 7);							
	v1 *= v2;
	cout << v1.real() << " " << v1.imaginary() << endl;

	//Testing the division function
	v1 /= v2;
	cout << v1.real() << " " << v1.imaginary() << endl;

	//Testing the copy constructor
	complex v3(v2);
	cout << v3.real() << ' ' << v3.imaginary() << endl;

	//Both real and Imaginary modifiers work properly
	v1.imaginary(13);                                        
	std::cout << v1.imaginary() << endl;

	v1.real(19);
	cout << v1.real() << endl;

	//Testing the ADDIOTION function                      
	complex v4(1.0, 3.0);                                  
	complex v5(3.0, 1.0);
	v4 += v5;
	cout << v4.real() << ' ' << v4.imaginary() << endl;

	//Testing the SUBTRACTION function                      
	v4 -= v5;
	cout << v4.real() << ' ' << v4.imaginary() << endl;

}