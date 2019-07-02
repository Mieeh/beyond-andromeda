//HORIZONTAL GLOW

uniform float fadedelta;
/*
//Fading Delta:
float fadedelta = 0f;
for (float i = 0f; i < 10f * glowMul; i++)
	fadedelta += (1f - (i / (10f * glowMul)));
fadedelta = 1f / (1f + 2f * fadedelta);
*/

uniform sampler2D img;
uniform float width;
uniform float g; //glow multiplier (glowMul)

void main() {
	vec2 step = vec2(1. / width, 0.);
	vec4 clr = texture2D(img, gl_TexCoord[0].st);
	
	vec4 c = clr * fadedelta;
	
	float threshold = 10. * g;
	for(float i = 0.; i < threshold; i++) {
		vec4 c_inc;
		
		c_inc = texture2D(img, gl_TexCoord[0].st + step * i);
		c += c_inc * (1. - (fadedelta * i)) * fadedelta;
		
		c_inc = texture2D(img, gl_TexCoord[0].st - step * i);
		c += c_inc * (1. - (fadedelta * i)) * fadedelta;
	}
	gl_FragColor = c * g;
}