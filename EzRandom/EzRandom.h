#pragma once

#include <cmath>
#include <limits>
#include <random>

template<typename IntType = int, typename Engine = std::mt19937>
class EzRandomInt
{
public:
	EzRandomInt(const IntType& min, const IntType& max, bool include_min, bool include_max);
	~EzRandomInt() = default;

	IntType GetNext();

private:
	Engine engine_;
	std::uniform_int_distribution<IntType> distribution_;
};

template<typename RealType = float, typename Engine = std::mt19937>
class EzRandomReal
{
public:
	EzRandomReal(const RealType& min, const RealType& max, bool include_min, bool include_max);
	~EzRandomReal() = default;

	RealType GetNext();

private:
	Engine engine_;
	std::uniform_real_distribution<RealType> distribution_;
};

template<typename IntType, typename Engine>
EzRandomInt<IntType, Engine>::EzRandomInt(const IntType& min, const IntType& max, bool include_min, bool include_max)
{
	std::random_device rd;
	engine_ = Engine(rd());

	IntType dist_min;
	if (include_min)
	{
		dist_min = min;
	}
	else
	{
		dist_min = min + 1;
	}

	IntType dist_max;
	if (include_max)
	{
		dist_max = max;
	}
	else
	{
		dist_max = max - 1;
	}

	distribution_ = std::uniform_int_distribution<IntType>(dist_min, dist_max);
}

template<typename IntType, typename Engine>
IntType EzRandomInt<IntType, Engine>::GetNext()
{
	return distribution_(engine_);
}

template<typename RealType, typename Engine>
inline EzRandomReal<RealType, Engine>::EzRandomReal(const RealType& min, const RealType& max, bool include_min, bool include_max)
{
	std::random_device rd;
	engine_ = Engine(rd());

	RealType dist_min;
	if (include_min)
	{
		dist_min = min;
	}
	else
	{
		dist_min = std::nextafter(min, std::numeric_limits<RealType>::max());
	}

	RealType dist_max;
	if (include_max)
	{
		dist_max = std::nextafter(max, std::numeric_limits<RealType>::max());
	}
	else
	{
		dist_max = max;
	}

	distribution_ = std::uniform_real_distribution<RealType>(dist_min, dist_max);
}

template<typename RealType, typename Engine>
inline RealType EzRandomReal<RealType, Engine>::GetNext()
{
	return distribution_(engine_);
}
