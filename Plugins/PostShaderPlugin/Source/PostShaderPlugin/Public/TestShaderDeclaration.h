#pragma once


#include "GlobalShader.h"
#include "UniformBuffer.h"
#include "RHICommandList.h"

//This buffer should contain variables that never,or ralely change
BEGIN_UNIFORM_BUFFER_STRUCT(FTestShaderConstantParameters, )
UNIFORM_MEMBER(FVector4,TestColor)
END_UNIFORM_BUFFER_STRUCT(FTestShaderConstantParameters)

//Variable Buffers
BEGIN_UNIFORM_BUFFER_STRUCT(FTestShaderValiableParameters, )
UNIFORM_MEMBER(float, BlendFactor)
END_UNIFORM_BUFFER_STRUCT(FTestShaderValiableParameters)

typedef TUniformBufferRef<FTestShaderConstantParameters> FTestShaderConstantParametersRef;
typedef TUniformBufferRef<FTestShaderValiableParameters> FTestShaderValiableParametersRef;

//This is the type we use as vertices for our fullscreen quad.
struct FVertexPos4AndUV
{
	FVector4 ScreenPos4;
	FVector2D UV;
};


class FTestShaderVertexDeclaration :public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;

	virtual void InitRHI() override
	{
		FVertexDeclarationElementList Elements;

		uint32 Stride = sizeof(FVertexPos4AndUV);
		auto TempElement = FVertexElement(0, STRUCT_OFFSET(FVertexPos4AndUV, ScreenPos4), VET_Float4, 0, Stride);
		Elements.Add(TempElement);
		auto TempElement2 = FVertexElement(0, STRUCT_OFFSET(FVertexPos4AndUV, UV), VET_Float2, 0, Stride);
		Elements.Add(TempElement2);

		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
		
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}

protected:
private:
};

// A simple pass through VertexShader that we will use
class FTestVertexShader :public FGlobalShader
{
	DECLARE_SHADER_TYPE(FTestVertexShader, Global);

public:
	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}
	FTestVertexShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FGlobalShader(Initializer)
	{}

	FTestVertexShader() {}

	//Permutation –Ú¡–£¨÷√ªª£¨≈≈¡–
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters);

private:

};


// This class is what encapsulates the shader in the engine.
// It is the main bridge between the HLSL located in the engine directory
// and the engine itself.
class FTestPixelhader : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FTestPixelhader, Global);
public:

	FTestPixelhader() {}

	explicit FTestPixelhader(const ShaderMetaType::CompiledShaderInitializerType& Initializer);
	
	static bool ShouldCache(EShaderPlatform Platform) { return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM5); }

	virtual bool Serialize(FArchive& Ar) override
	{
		bool bShaderHasOutdatedParams = FGlobalShader::Serialize(Ar);

		//Ar <<

		return bShaderHasOutdatedParams;
	}

	//this function is required to bind our constant/uniform buffers to the shader.
	//Required function
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters);

protected:
private:
	//FShaderResourceParameter 
};