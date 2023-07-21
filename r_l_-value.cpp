#include <iostream> 
#include <type_traits>

void Print(const int& x) {
	std::cout << x << " L-value overload\n";
}

void Print(int&& x) {
	std::cout << x << " R-value overload\n";
}

int main() {

	Print(6);// 6 R-value overload
	int x = 5;
	Print(x);// 5 L-value overload
	typedef std::remove_reference<int&>::type RV;
	Print(static_cast<RV>(x));// 5 R-value overload
}