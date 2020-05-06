#pragma once

class MyException2 :
	public std::exception
{
public:
	const char* what() {
		return typeid(MyException2).name();
	}
};

