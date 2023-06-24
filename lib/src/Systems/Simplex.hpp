#ifndef ENGINE_SIMPLEX_HPP
#define ENGINE_SIMPLEX_HPP

#include <Engine/Maths/Vector3.hpp>
#include <array>

namespace Engine {

struct Simplex {
public:
	Simplex()
			: m_points(
					{Vector3<Float>::Zero,
					 Vector3<Float>::Zero,
					 Vector3<Float>::Zero,
					 Vector3<Float>::Zero}
				),
				m_size(0) {}

	Simplex& operator=(std::initializer_list<Vector3<Float>> list) {
		for (auto v = list.begin(); v != list.end(); v++) {
			m_points[std::distance(list.begin(), v)] = *v;
		}
		m_size = list.size();

		return *this;
	}

	void push_front(Vector3<Float> point) {
		m_points = {point, m_points[0], m_points[1], m_points[2]};
		m_size = std::min(m_size + 1, 4u);
	}

	Vector3<Float>& operator[](unsigned i) {
		return m_points[i];
	}

	unsigned size() const {
		return m_size;
	}

	auto begin() const {
		return m_points.begin();
	}

	auto end() const {
		return m_points.end() - (4 - m_size);
	}

private:
	std::array<Vector3<Float>, 4> m_points;
	unsigned m_size;
};

}

#endif
