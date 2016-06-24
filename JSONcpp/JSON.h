#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <memory>

#include "Fundamentals.h"

namespace json {

	enum class ValueType {
		Null,
		Bool,
		Number,
		String,
		Array,
		Object
	};



	

	Value parse(std::string expression) {
		return Value().extractFrom(expression);
	}
}