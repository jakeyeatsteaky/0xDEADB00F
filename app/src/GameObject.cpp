#include "GameObject.hpp"
#include "Logger.hpp"


std::unique_ptr<GameObject> GameObject::CreateObject(RendererType type)
{
    if (RendererType::eSDLRenderer == type) {
        return std::make_unique<GameObject_SDL>();
    }
    else {
        ERR("Haven't Created the Vulkan Game Object Type yet");
        return nullptr;
    }
}

//////////////////////////////////////////////////////////////
//															//
//						SDL GAME OBJECT						//
//															//
//////////////////////////////////////////////////////////////


GameObject_SDL::GameObject_SDL() :
    m_pos(glm::vec2{0,0}),
    m_color(glm::vec4{0,0,0xFF, 0xFF})
{
	LOG("Creating an SDL game object");
}


GameObject_SDL::~GameObject_SDL()
{

}

bool GameObject_SDL::Init()
{
	bool ret = false;
	LOG("Initializing GameObject_SDL");
    m_pos = { 100,100 };
    m_color = { 0xAD, 0x12, 0xFF, 0xFF };

    m_renderData.colorData = m_color;
    m_renderData.positionData = m_pos;

    ret = true;
	return ret;

}

RenderData GameObject_SDL::GetRenderData()
{
    return m_renderData;
}

void GameObject_SDL::Update()
{
    // Process changes
    m_pos += glm::vec2(1, 1);

    // Update renderData
    m_renderData.colorData = m_color;
    m_renderData.positionData = m_pos;

}