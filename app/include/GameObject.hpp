#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Renderer.hpp"
#include "glm/glm.hpp"

class GameObject
{
private:
	

public:
	virtual ~GameObject() {};
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void SetDT(float dt) = 0;
	virtual RenderData GetRenderData() = 0;

	static std::unique_ptr<GameObject> CreateObject(RendererType type);

};

class GameObject_SDL : public GameObject
{
	glm::vec2 m_pos;
	glm::vec4 m_color;
	RenderData m_renderData;
	float m_deltaTime;

public:
	GameObject_SDL();
	~GameObject_SDL() override;
	bool Init() override;
	void Update() override;
	void SetDT(float dt) override;
	RenderData GetRenderData() override;
};

#endif // end game object hpp