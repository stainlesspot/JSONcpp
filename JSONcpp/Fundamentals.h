#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <memory>

namespace json
{
	class Value;

	class Object {
		std::unordered_map<std::string, Value> m_variables;

	public:
		Object(std::string expression);

		Object() = default;
		Object(const Object&) = default;
		Object(Object&&) = default;
		~Object() = default;
	};


	class Array
	{
		std::vector<Value> m_elements;

	public:
		Array(std::string expression);

		Array() = default;
		Array(const Array&) = default;
		Array(Array&&) = default;
		~Array() = default;
	};

	enum class ValueType {
		Null,
		Bool,
		Integer,
		String,
		Array,
		Object
	};
	
	class Value
	{
		ValueType type;

		std::unique_ptr<bool> m_bool;
		std::unique_ptr<int> m_number;
		std::unique_ptr<std::string> m_string;
		std::unique_ptr<Array> m_array;
		std::unique_ptr<Object> m_object;
	public:

		Value();

		Value(const bool);
		Value(const int);
		Value(const std::string&);
		Value(const Array&);
		Value(const Object&);

		Value(const Value&) = default;
		Value(Value&&) = default;
		~Value() = default;

		Value& extractFrom(std::string expression);

		operator bool();
		operator int();
		operator std::string();
		operator Array();
		operator Object();

		Value& operator =(const bool);
		Value& operator =(const int);
		Value& operator =(const std::string&);
		Value& operator =(const Array&);
		Value& operator =(const Object&);

		Value& operator =(const Value&) = default;
		Value& operator =(Value&&) = default;
	};
}