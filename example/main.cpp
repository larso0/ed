#include <iostream>
#include <ed/ed.h>

using namespace std;

void print_value(int value)
{
	cout << "Value is " << value << ".\n";
}

class multiple_printer
{
public:
	multiple_printer(int multiple) : multiple(multiple) {}

	void evaluate(int value)
	{
		if (value % multiple == 0)
			cout << value << " is a multiple of " << multiple << ".\n";
	}

private:
	int multiple;
};

int main()
{
	//The event.
	//Implements operator () with the parameters provided to the template
	//For similar behavior as a Qt signal, use an event as a public member variable
	ed::event<int> event;

	//Function as delegate
	ed::connect(event, print_value);

	//Method as delegate
	multiple_printer mp(3);
	ed::connect(event, mp, &multiple_printer::evaluate);

	//Closure/lambda as delegate
	ed::connect(event, [](int value) {
		cout << value << " is " << (value % 2 ? "odd" : "even") << ".\n";
	});

	for (int i = 1; i <= 10; i++)
		event(i);

	return 0;
}