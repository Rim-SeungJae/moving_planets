#ifdef GL_ES
	#ifndef GL_FRAGMENT_PRECISION_HIGH	// highp may not be defined
		#define highp mediump
	#endif
	precision highp float; // default precision needs to be defined
#endif

// input from vertex shader
in vec3 norm;
in vec2 tc;

// the only output variable
out vec4 fragColor;

uniform int color_type;

void main()
{
	switch(color_type)
	{
		case 0:
			fragColor=vec4(tc.xy,0,1);
			break;
		case 1:
			fragColor=vec4(tc.xxx,1);
			break;
		case 2:
			fragColor=vec4(tc.yyy,1);
			break;
	}
}
