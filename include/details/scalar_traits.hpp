#pragma once

#include "../Complex.hpp"

#include <type_traits>

template<typename T>
struct is_complex : std::false_type {};

template<>
struct is_complex<Complex> : std::true_type {};

template<typename K>
concept is_arithmetic = std::is_arithmetic_v<K> || is_complex<K>::value;

template<typename K>
concept numeric_scalar = is_arithmetic<K>;
