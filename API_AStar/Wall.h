#pragma once
#include "Tile.h"

class Wall : public Tile
{
public:

	void Start() override;
	void Update() override
	{

	}

public:
	Wall();
	~Wall();
};

