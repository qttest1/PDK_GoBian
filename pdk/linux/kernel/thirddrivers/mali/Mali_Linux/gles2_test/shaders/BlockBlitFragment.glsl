/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2001-2002, 2007-2010 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */
 
 
 precision mediump float;
/*
#if OpenGL_ES
#define	OPENGL_MEDIUMP	mediump 
#else
#define	OPENGL_MEDIUMP	mediump
#endif
*/

//#define	_FILTER_TEST

// image to be convolved
uniform sampler2D s_texture;
varying vec2 v_texCoord;

uniform  vec2 v_offset[25];
uniform  float v_kernel[25];

const	mat3 rgb2yuv = mat3( 
/*
							0.29900, 0.58700, 0.11400,
							-0.14713,-0.28886, 0.43600,
							 0.61500,-0.51498,-0.10001
*/							 
								0.29900, -0.14713, 0.61500,
							0.58700,-0.28886, -0.51498,
							 0.11400,0.43600,-0.10001 
							 
							 );

void main()
{
#ifdef	_FILTER_TEST
        int i;
        vec4	tmp;
        vec4	sum = vec4(0.0);
        
        vec4 ScaleFactor = vec4(0.003663);
				int KernelSize = 25;
/*        
        const float step_w = 2.0/512.0;
        const float step_h = 2.0/512.0;
        vec2 offset[25];
        float kernel[25];
        
				offset[0] = vec2(-2.0*step_w,  2.0*step_h);
        offset[1] = vec2(-2.0*step_w,  1.0*step_h);
        offset[2] = vec2(-2.0*step_w,  0.0*step_h);
        offset[3] = vec2(-2.0*step_w, -1.0*step_h);
        offset[4] = vec2(-2.0*step_w, -2.0*step_h);
        offset[5] = vec2(-1.0*step_w,  2.0*step_h);
        offset[6] = vec2(-1.0*step_w,  1.0*step_h);
        offset[7] = vec2(-1.0*step_w,  0.0*step_h);
        offset[8] = vec2(-1.0*step_w, -1.0*step_h);
        offset[9] = vec2(-1.0*step_w, -2.0*step_h);
        offset[10]= vec2( 0.0*step_w,  2.0*step_h);
        offset[11]= vec2( 0.0*step_w,  1.0*step_h);
        offset[12]= vec2( 0.0*step_w,  0.0*step_h);
        offset[13]= vec2( 0.0*step_w, -1.0*step_h);
        offset[14]= vec2( 0.0*step_w, -2.0*step_h);
        offset[15]= vec2( 1.0*step_w,  2.0*step_h);
        offset[16]= vec2( 1.0*step_w,  1.0*step_h);
        offset[17]= vec2( 1.0*step_w,  0.0*step_h);
        offset[18]= vec2( 1.0*step_w, -1.0*step_h);
        offset[19]= vec2( 1.0*step_w, -2.0*step_h);
        offset[20]= vec2( 2.0*step_w,  2.0*step_h);
        offset[21]= vec2( 2.0*step_w,  1.0*step_h);
        offset[22]= vec2( 2.0*step_w,  0.0*step_h);
        offset[23]= vec2( 2.0*step_w, -1.0*step_h);
        offset[24]= vec2( 2.0*step_w, -2.0*step_h);

        kernel[0] = kernel[4] = kernel[20]= kernel[24]= 1.0;
        kernel[5] = kernel[15]= kernel[1] = kernel[21]= kernel[3] = kernel[23]= kernel[9] = kernel[19]= 4.0;
        kernel[10]= kernel[14]= kernel[2] = kernel[22]= 7.0;
        kernel[6] = kernel[16]= kernel[8] = kernel[18]= 16.0;
        kernel[11]= kernel[7] = kernel[17]= kernel[13]= 26.0;
        kernel[12]= 41.0;   
*/				
				for (i = 0; i < KernelSize; i++)
				{
					tmp = texture2D(s_texture, v_texCoord + v_offset[i]);
					tmp.rgb = rgb2yuv * tmp.rgb ;
	
	
					tmp.g = tmp.g + 0.5;
					tmp.b = tmp.b + 0.5;
					sum += tmp * v_kernel[i];
				}
				gl_FragColor = ScaleFactor * sum;
				
#else
        	
	
	gl_FragData[0] = texture2D(s_texture, v_texCoord );
	
// yuv2rgb convertor	
/*	
	gl_FragData[0].rgb = rgb2yuv * gl_FragData[0].rgb ;
	
	gl_FragData[0].g = gl_FragData[0].g + 0.5;
	gl_FragData[0].b = gl_FragData[0].b + 0.5;
*/	
	//gl_FragData[1].r = gl_FragData[0].g + 0.5;
	//gl_FragData[1].g = gl_FragData[0].b + 0.5;
	
#endif        	
}
