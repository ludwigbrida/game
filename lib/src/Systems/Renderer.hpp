#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include "../Graphics/Program.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Matrix4.hpp>

namespace ng {

class Renderer : public System {
public:
	void update(Registry& registry, State& state, Float deltaTime) override;

private:
	void clear(const Color& color) const;
	void draw(const Mesh& mesh, const Program& program,
						const Matrix4f& modelMatrix) const;
};

}

#endif
