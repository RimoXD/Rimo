#pragma once

class MyException1 :
	public std::exception
{
public:
	const char* what() {
		return typeid(MyException1).name();
	}
};

