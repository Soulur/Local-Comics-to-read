#pragma once

#include "Source/Core/Base.h"
#include "Source/Core/Time.h"
#include "Source/Events/Event.h"

namespace Source {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			: m_Name(name)
		{
		}

		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_Name; }
	protected:
		std::string m_Name;
	};

}