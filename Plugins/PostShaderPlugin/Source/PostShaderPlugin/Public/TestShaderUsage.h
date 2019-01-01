#pragma once
#include "TestShaderDeclaration.h"
#include <atomic>


class FTestShaderUsage
{
public:
	FTestShaderUsage(ERHIFeatureLevel::Type ShaderFeatureLevel);
	~FTestShaderUsage();

	// Let the user change render target during runtime if they want to
	//UTextureRenderTarget2D* RenderTarget, FTexture2DRHIRef InputTexture
	void ExecuteShader();

	
	void ExecuteShader_RenderThread();



protected:
	std::atomic<bool> bIsTestShaderExecuting;
	std::atomic<bool> bIsUnloading;

	FTestShaderConstantParameters ConstantParameters;
	FTestShaderValiableParameters VaraiableParameters;
	ERHIFeatureLevel::Type FeatureLevel;

	UTextureRenderTarget2D* CurrentRenderTarget;

	//

private:
};