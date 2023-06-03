#include <Engine/Maths/Radian.hpp>
#include <cmath>

namespace ng {

Float fromDegrees(Float degrees) {
	return degrees * (M_PI / 180);
}

}
