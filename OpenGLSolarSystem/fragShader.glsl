#version 430

in vec3 varyingNormal;
in vec3 varyingLightDir;
in vec3 varyingVertPos;
in vec3 varyingHalfVector;

struct PositionalLight
{	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec3 position;
};

uniform vec4 globalAmbient;
uniform PositionalLight light;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;
uniform mat4 norm_matrix;

layout (binding=0) uniform sampler2D samp;
//in vec4 varyingColor;
in vec2 tc;
out vec4 color;

void main(void)
{		
	vec3 L = normalize(varyingLightDir);
	vec3 N = normalize(varyingNormal);
	vec3 V = normalize(-varyingVertPos);
	
	// get the angle between the light and surface normal:
	float cosTheta = dot(L,N);
	
	// halfway vector varyingHalfVector was computed in the vertex shader,
	// and interpolated prior to reaching the fragment shader.
	// It is copied into variable H here for convenience later.
	vec3 H = normalize(varyingHalfVector);
	
	// get angle between the normal and the halfway vector
	float cosPhi = dot(H,N);

	// compute ADS contributions (per pixel):
	vec3 ambient = ((globalAmbient) + (light.ambient)).xyz;
	vec3 diffuse = light.diffuse.xyz * max(cosTheta,0.0);
	vec3 specular = light.specular.xyz * pow(max(cosPhi,0.0), 3.0);
	vec3 textureColor = (texture(samp, tc)).xyz;
	color = vec4(textureColor * (ambient + diffuse), 1.0);
	//color = vec4(1.0, 0.0, 0.0, 1.0);
}
