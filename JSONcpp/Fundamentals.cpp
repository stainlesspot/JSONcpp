#include "Fundamentals.h"

namespace json
{
/*	std::string::iterator findlastOccurance(std::string string, char character) {
		for(auto it(string.rbegin()), end(string.rend()); it != end; it++)
		{
			if (*it == character) {
				return it.base;
			}
		}
		return std::string::npos;
	}
*/
	Value & Value::extractFrom(std::string expression)
	{
		for (size_t i = 0; i < expression.size(); i++)
		{
			switch (expression[i])
			{
			case '{':
				size_t endPosition = expression.find_last_of('}');
				if (endPosition != std::string::npos) {
					type 
				}

			}
		}
		
		
		
		return *this;
	}
}