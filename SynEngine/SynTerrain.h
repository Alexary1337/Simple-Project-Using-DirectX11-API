#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "common.h"
#include <d3d11.h>
#include <d3dx10math.h>
#include "syntexture.h"

class SynTerrain
{
private:

	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};

public:
	SynTerrain();
	SynTerrain(const SynTerrain&);
	~SynTerrain();

	bool Initialize(ID3D11Device*, WCHAR*);
	void Shutdown();
	bool Render(ID3D11DeviceContext*);

	ID3D11ShaderResourceView* GetTexture();

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	SynTexture* m_Texture;
	int m_vertexCount, m_indexCount;
};

#endif