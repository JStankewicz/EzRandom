#pragma once

#include <cmath>
#include <limits>
#include <random>

template<typename IntType = int, typename Engine = std::mt19937>
class EzRandomIntStatic
{
public:
	EzRandomIntStatic() = delete;
	~EzRandomIntStatic() = delete;

	static IntType GetInRange(const IntType& min, const IntType& max);
};

// Returns a value between min (inclusive) and max (inclusive).
template<typename IntType, typename Engine>
IntType EzRandomIntStatic<IntType, Engine>::GetInRange(const IntType& min, const IntType& max)
{
	static std::random_device rd;
	static Engine engine = Engine(rd());
	std::uniform_int_distribution<IntType> distribution = std::uniform_int_distribution<IntType>(std::numeric_limits<IntType>::lowest(), std::numeric_limits<IntType>::max());

	IntType dist_min = std::min(min, max);
	IntType dist_max = abs(max - min) + 1;
	IntType ret = distribution(engine);

	// Get the result into the right range...
	ret %= dist_max;
	ret += dist_max;
	ret %= dist_max;

	ret += dist_min;
	return ret;
}
