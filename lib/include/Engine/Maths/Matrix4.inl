#ifndef ENGINE_MATRIX4_INL
#define ENGINE_MATRIX4_INL

namespace ng {

template <IsArithmetic T>
const Matrix4<T> Matrix4<T>::Identity{
	1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
};

}

#endif
