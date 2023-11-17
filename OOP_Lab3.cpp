#include <iostream>
#include "Cash.h"
#include "Smart_Pointer.h"
#include "Queue.h"


#define HURT char(3)


int main()
{
	setlocale(LC_ALL, "");

	Cash cash(5, 800);
	Queue<int> queue;

	queue.push(11);
	queue.push(12);
	queue.push(13);
	queue.push(14);
	queue.push(15);


	cash.push(1);
	cash.push(2);
	cash.push(3);
	cash.push(4);
	cash.push(5);



	std::cout << HURT << HURT << HURT << "~~~Cash~~~"<< HURT << HURT << HURT << "\n" << cash << "\n\n";
	std::cout << HURT << HURT << HURT << "~~~Queue~~~"<< HURT << HURT << HURT << "\n" << queue << "\n\n";
	std::cout << "\n\n";


	try
	{
		cash(0, 3) = queue;
		std::cout << HURT << HURT << HURT << "~~~Cash~~~" << HURT << HURT << HURT << "\n" << cash << "\n\n";
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what()<<"\n\n";
	}
	catch (const std::length_error& e)
	{
		std::cout << e.what() << "\n\n";
	}


	
	Smart_Pointer<Queue<int>> ptr = new Queue<int>();

	ptr->push(5);
	ptr->push(4);
	ptr->push(3);
	ptr->push(2);
	ptr->push(1);


	std::cout << "\n\n";

	std::cout << HURT << HURT << HURT << "~~~Queue_Ptr~~~" << HURT << HURT << HURT << "\n" << *ptr << "\n\n";


	return 0;
}



//Test

//1
//(1,3), size = 3
// 
// 2
// (1, 5), size = 3
// 
// 3
// (0, 3) size = 2
// 
// 4
// (4, 3) size = 3
// 
// 5
// (0, 5) size = 5 
// 
// 6
// (3, 5) size = 5
//