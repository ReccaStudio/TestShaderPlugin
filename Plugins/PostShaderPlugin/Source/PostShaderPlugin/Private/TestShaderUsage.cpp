#include "TestShaderUsage.h"


//定点输入声明
//是否全局根据自己的访问范围决定
TGlobalResource<FTestShaderVertexDeclaration> GTextureVertexDeclaration;


FTestShaderUsage::FTestShaderUsage(ERHIFeatureLevel::Type ShaderFeatureLevel)
{
	FeatureLevel = ShaderFeatureLevel;

	ConstantParameters = FTestShaderConstantParameters();

	VaraiableParameters = FTestShaderValiableParameters();

	bIsUnloading = false;
	bIsTestShaderExecuting = false;

	CurrentRenderTarget = nullptr;
}

FTestShaderUsage::~FTestShaderUsage()
{
	bIsUnloading = true;
}

//UTextureRenderTarget2D * RenderTarget, FTexture2DRHIRef InputTexture
void FTestShaderUsage::ExecuteShader()
{
	check(IsInGameThread());

	if (bIsUnloading || bIsTestShaderExecuting)
	{
		return;
	}

	bIsTestShaderExecuting = true;

	ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(FPixelShaderRunner, FTestShaderUsage*, TestShader, this, 
	{
		TestShader->ExecuteShader_RenderThread();
	}
	);

}

void FTestShaderUsage::ExecuteShader_RenderThread()
{
	check(IsInRenderingThread());

	if (bIsUnloading)
	{
		return;
	}




	//finished
	bIsTestShaderExecuting = false;
}
