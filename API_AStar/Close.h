#pragma once
#include "Tile.h"
class Close : public Tile
{
public:
	void Start() override;
	void Update() override
	{

	}

public:
	Close();
	~Close();
};