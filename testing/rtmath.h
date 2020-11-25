#ifndef RTMATH_H
#define RTMATH_H

#include <math.h>
typedef	struct	s_vec4
{
	union
	{
		float x;
		float r;
	};
	union
	{
		float y;
		float g;
	};
	union
	{
		float z;
		float b;
	};
	union
	{
		float w;
		float a;
	};
}				t_vec4;

typedef	struct	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

typedef	struct	s_vec2
{
	float x;
	float y;
}				t_vec2;

float	rt_smoothstep(float min, float max, float value);
/* ----- VECTORS STUFF ----- */
t_vec3	rt_add_vec(t_vec3 v0, t_vec3 v1);
t_vec3	rt_sub_vec(t_vec3 v0, t_vec3 v1);
float	rt_length(t_vec3 v0);
float	rt_dot(t_vec3 v0, t_vec3 v1);
t_vec3	rt_cross(t_vec3 v0, t_vec3 v1);
t_vec3	rt_normalize(t_vec3 v0);
/* ----- MATRICES STUFF ----- */
#endif