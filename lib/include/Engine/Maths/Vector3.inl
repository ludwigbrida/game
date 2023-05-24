#ifndef ENGINE_VECTOR3_INL
#define ENGINE_VECTOR3_INL

namespace ng {

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Right{1, 0, 0};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Left{-1, 0, 0};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Up{0, 1, 0};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Down{0, -1, 0};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Backward{0, 0, 1};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Forward{1, 0, -1};

using Vector3f = Vector3<float>;

}

#endif
