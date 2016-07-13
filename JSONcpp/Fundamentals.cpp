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
	bool isWhiteSpace(char ch)
	{
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}

	std::string removeWrappingSpaces(std::string expression)
	{
		auto it(expression.begin());
		for (auto end(expression.end()); it != end; it++)
			if (!isWhiteSpace(*it))
				break;

		auto rit(expression.rbegin());
		for (auto rend(expression.rend()); rit != rend; rit++)
			if (!isWhiteSpace(*rit))
				break;
		return std::string(it, (rit + 1).base());
	}

	Value & Value::extractFrom(std::string expression)
	{
		expression = removeWrappingSpaces(expression);

		try {
			switch (expression[0])
			{
			case '"':
				size_t endPosition = expression.find('"', 1);
				if (endPosition != std::string::npos)
					operator =(std::string(expression.substr(1, endPosition - 1)));
				break;
			case '-':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				operator =(std::stod(expression));
				break;
			case '{':
				size_t endPosition = expression.find_last_of('}');
				if (endPosition != std::string::npos)
					operator =(Object(expression.substr(1, endPosition - 1)));
				break;
			case '[':
				size_t endPosition = expression.find_first_of(']');
				if (endPosition != std::string::npos)
					operator =(Array(expression.substr(1, endPosition - 1)));
				break;
			case 't':
				if (expression.substr(0, 4) == "true")
					operator =(true);
				break;
			case 'f':
				if (expression.substr(0, 5) == "false")
					operator =(false);
				break;
			case 'n':
				if (expression.substr(0, 4) == "null")
					operator =(nullptr);
				break;

			}
		}
		catch (const std::exception*) {}
		
		
		return *this;
	}
}