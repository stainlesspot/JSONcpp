#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <memory>

namespace json {

	enum class ValueType {
		Null,
		Bool,
		Number,
		String,
		Array,
		Object
	};

	class Value {
		std::unique_ptr<bool> m_bool;
		std::unique_ptr<int> m_number;
		std::unique_ptr<std::string> m_string;
		std::unique_ptr<Array> m_array;
		std::unique_ptr<Object> m_object;

	public:

		Value();

	//	Value(std::string expression);

		Value(const bool);
		Value(const int);
		Value(const std::string&);
		Value(const Array&);
		Value(const Object&);

		Value(const Value&) = default;
		Value(Value&&) = default;
		~Value() = default;


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



	struct Object {
		std::unordered_map<std::string, Value> m_variables;
	};
	struct Array {
		std::vector<Value> m_elements;
	};

	const Value& parse(std::string expression) {
		return Value(expression);
	}
}