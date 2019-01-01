#include "TestShaderDeclaration.h"




//These are needed to actually implement the constant buffers so they are available inside our shader,
//They also need to be unique over the entire solution since they can in fact be accessed from any shader
IMPLEMENT_UNIFORM_BUFFER_STRUCT(FTestShaderConstantParameters, TEXT("TestConstBuffer"));
IMPLEMENT_UNIFORM_BUFFER_STRUCT(FTestShaderValiableParameters, TEXT("TestVariableBuffer"));




bool FTestVertexShader::ShouldCompilePermutation(const FGlobalShaderPermutationParameters & Parameters)
{
	return true;
}

FTestPixelhader::FTestPixelhader(const ShaderMetaType::CompiledShaderInitializerType & Initializer)
	:FGlobalShader(Initializer)
{
	//
}

bool FTestPixelhader::ShouldCompilePermutation(const FGlobalShaderPermutationParameters & Parameters)
{
	return true;
}


//This is what will instance the shader into the engine from the Engine/Shaders folder
//								Shader Type					ShaderFileName		Shader function name			ShaderType
IMPLEMENT_SHADER_TYPE(, FTestVertexShader, TEXT("/Plugin/PostShaderPlugin/Private/TestShader.usf"),TEXT("TestShaderMainVertex"),SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FTestPixelhader, TEXT("/Plugin/PostShaderPlugin/Private/TestShader.usf"), TEXT("TestShaderMainPixel"), SF_Pixel);


