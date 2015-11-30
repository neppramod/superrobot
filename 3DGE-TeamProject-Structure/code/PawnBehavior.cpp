#include "PawnBehavior.h"
#include "Model.h"
#include "Mesh.h"



PawnBehavior::PawnBehavior()
{
}


PawnBehavior::~PawnBehavior()
{
}

void PawnBehavior::update(GameObject* object, float elapsedSeconds)
{
	Model* model = (Model*)object;
	Mesh* blade = model->getMesh("Blade");
	model->frameStack.setBaseFrame(model->referenceFrame);
	model->frameStack.push();
	{
		model->frameStack.translate(1.5f, 5, 0);
		model->frameStack.rotateZ(-60);
		blade->referenceFrame = model->frameStack.top();
	}
	model->frameStack.pop();
}
