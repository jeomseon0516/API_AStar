#pragma once
#include "Tile.h"

class End : public Tile
{
public:

	void Start() override;
	void Update() override
	{

	}

public:
	 End();
	~End();
};

