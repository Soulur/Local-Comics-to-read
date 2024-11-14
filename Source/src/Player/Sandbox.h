#pragma once

#include "Source/Core/Application.h"

#include "Player/ExampleLayer.h"

class Sandbox : public Source::Application
{
public:
	Sandbox()
	{
		PushLayer(new Source::ExampleLayer());
	}

	~Sandbox()
	{
	}

};

Source::Application* Source::CreateApplication()
{
	return new Sandbox();
}