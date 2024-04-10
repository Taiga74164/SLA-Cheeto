#pragma once

class Module
{
public:
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual ~Module() = default;
};
