// Jack/RYBN 2013
#extension GL_EXT_gpu_shader4 : enable
#extension GL_ARB_texture_rectangle : enable
uniform sampler2DRect tex0, tex1;
uniform vec3 value;
uniform float range;

float maxl = sqrt(3.0);

ivec2 size1 = textureSize2DRect(tex0, 0);
ivec2 size2 = textureSize2DRect(tex1, 0);

void main() {
	vec2 coordA = (gl_TextureMatrix[0] * gl_TexCoord[0]).st*vec2(size1);
	vec2 coordB = (gl_TextureMatrix[1] * gl_TexCoord[1]).st*vec2(size2);
	vec4 colorA = texture2DRect(tex0, coordA);
	vec4 colorB = texture2DRect(tex1, coordB);
	float dist = distance(vec3(colorA),value);
	dist /= maxl;
	float rupture = step(dist, range);
	colorA *= (1.0-rupture);
	colorB *= (rupture);
    gl_FragColor = colorA+colorB;
}

