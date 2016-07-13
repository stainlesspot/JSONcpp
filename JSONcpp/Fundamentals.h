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
		std::unordered_map<std::string, Value> m_properties;

	public:
		Object(std::string expression);

		Object() = default;
		Object(const Object&) = default;
		Object(Object&&) = default;
		~Object() = default;

		Value& operator[](const std::string&);

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
		Number,
		String,
		Array,
		Object
	};
	
	class Value
	{
		ValueType type;

		std::unique_ptr<bool> m_bool;
		std::unique_ptr<double> m_number;
		std::unique_ptr<std::string> m_string;
		std::unique_ptr<Array> m_array;
		std::unique_ptr<Object> m_object;
	public:

		Value();

		Value(std::nullptr_t);
		Value(const bool);
		Value(const double);
		Value(const std::string&);
		Value(const Array&);
		Value(const Object&);

		Value(const Value&) = default;
		Value(Value&&) = default;
		~Value() = default;

		Value& extractFrom(std::string expression);

		operator bool();
		operator double();
		operator std::string();
		operator Array();
		operator Object();

		Value& operator =(std::nullptr_t);

		Value& operator =(const bool);
		Value& operator =(const double);

		Value& operator =(const std::string&);
		Value& operator =(std::string&&);
		
		Value& operator =(const Array&);
		Value& operator =(Array&&);

		Value& operator =(const Object&);
		Value& operator =(Object&&);

		Value& operator =(const Value&) = default;
		Value& operator =(Value&&) = default;
	};
}