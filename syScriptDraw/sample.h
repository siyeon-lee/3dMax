#pragma once
#include "syCore.h"
#include "syStd.h"
#include "syPlaneObject.h"
#include "syMap.h"
#include "syDebugCamera.h"
#include <sstream>

struct LIGHT_CONSTANT_BUFFER
{
	D3DXMATRIX			g_matInvWorld;
	// Material
	D3DXVECTOR4			g_cAmbientMaterial;
	D3DXVECTOR4			g_cDiffuseMaterial;
	D3DXVECTOR4			g_cSpecularMaterial;
	D3DXVECTOR4			g_cEmissionMaterial;
	// Light
	D3DXVECTOR4			g_cAmbientLightColor;
	D3DXVECTOR4			g_cDiffuseLightColor;
	D3DXVECTOR4			g_cSpecularLightColor;
	D3DXVECTOR4			g_vLightDir; // w = light damping(attenuation) : ����
	D3DXVECTOR4			g_vLightPos; // w = light radius
	D3DXVECTOR4			g_vEyeDir;// w = light intensity : ����
	D3DXVECTOR4			g_vEyePos;// w = light radius	
};

class sample : public syCore
{
public:
	sample();
	~sample();
public:
	syDebugCamera				m_CameraBack;
	std::vector<syMaxMesh> m_ObjList;
	std::vector<syMaxMtrl> m_TexList;
	syMaxObject				m_Ship;

	D3DXVECTOR3					m_vLightVector;
	LIGHT_CONSTANT_BUFFER		m_cbLight;
	Microsoft::WRL::ComPtr<ID3D11Buffer>	m_pConstantBufferLight;
public:
	bool Init();
	bool Import(wstring filename);
	bool getMaxObject();
	bool Frame() override;
	bool RenderObject(D3DXMATRIX& matView, D3DXMATRIX& matProj);
	bool Render() override;
	bool Release() override;
};

syCORE_RUN(thanks, 0, 0, 800, 600);