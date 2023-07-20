#pragma once
#include "Include.h"
#include "Tile.h"
#include "AStar.h"

class MainUpdate
{
private:
	AStar* _aStar;
public:
	void Start();
	void Update()
	{
		_aStar->Update();
	}
	void Render()
	{
		_aStar->Render();
	}

public:
	 MainUpdate();
	~MainUpdate();
};

