#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "synd3d.h"
#include "syncamera.h"
#include "synmodel.h"
#include "syncolorshader.h"
#include "synlight.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 7000.0f;
const float SCREEN_NEAR = 0.1f;

class SynGraphics
{
public:
	SynGraphics();
	SynGraphics(const SynGraphics&);
	~SynGraphics();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	bool TurnWF();
	void ChangeCameraPosition(bool);

private:
	bool Render(float);

private:
	SynD3D* m_D3D;
	SynCamera* m_Camera;
	SynModel* m_Model;
	SynColorShader* m_ColorShader;
	SynLight* m_Light;
};

#endif