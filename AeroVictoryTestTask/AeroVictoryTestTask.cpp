#include <iostream>
#include <vector>

// 1. In C++11 write a function summing all vector elements:
// std::vector xs = { 1, 2, 3, 4 };
// vectorSum(xs); // 10


int vectorSum(std::vector<int>& vector)
{
	const auto End = vector.end();
	int result = 0;

	for (auto It = vector.begin(); It != End; ++It)
	{
		result += *It;
	}

	return result;
} //10



// 2. Let's separate iteration and an operation to be done.
// Write a function aggregating a vector with any given function:
// aggregate(xs, add); // 10
// aggregate(xs, mul); // 24

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	//std::cout << a;
	//std::cout << b;
	return a * b;
}


int aggregate(std::vector<int>& vector, int(*func)(int, int) )
{
	if (vector.size() < 2)
	{
		std::abort();
	}

	auto End = vector.end();
	auto It = vector.begin();
	
	int result = func(vector[0],vector[1]); // initialize result with func execution,if init "result = 0" - mul func will always result 0
	It = It + 2;

	while (It != End)
	{
		result = func(result, *It);
		++It;
	}
	
	return result;
}

// 3. Add an optional parameter to start aggregating with
// aggregate(xs, mul, 10); // 240
// aggregate(xs, concat, std::string("0")); // "01234"




// 4. Implement `aggregate` recursively
// Let's also make it work with plain arrays (and maybe other collections?)
// And with both function pointers and lambdas (and maybe something else?)







int main()
{
	//add
	//mul
	std::vector<int> xs = { 1, 2, 3, 4 };
	int res = aggregate(xs, &mul);
	std::cout << res;
}
