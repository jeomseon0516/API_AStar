#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Start()
{
	_aStar = (new AStar())->Start();
}


