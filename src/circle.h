#pragma once
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

struct circle_t
{
	vec3	center=vec3(0);		// 2D position for translation
	float	radius=1.0f;		// radius
	float	theta=0.0f;			// rotation angle for self rotation
	float	phi = 0.0f;			// rotation angle for revolution
	vec4	color;				// RGBA color in [0,1]
	float	rot_speed = 1.0f;
	float	rev_speed = 1.0f;
	mat4	model_matrix;		// modeling transformation

	// public functions
	void	update( float t );
};

inline std::vector<circle_t> create_circles()
{
	std::vector<circle_t> circles;
	circle_t c;
	
	c = {vec3(0),2.0f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f),1/25.3f,0};
	circles.emplace_back(c);
	c = {vec3(-4.0f,0,0),0.2f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f),1/5.8f,1/0.24f};
	circles.emplace_back(c);
	c = { vec3(7.2f,0,0),0.3f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f),1/24.3f,1/0.68f};
	circles.emplace_back(c);
	c = { vec3(-10.0f,0,0),0.4f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f), 1/1.0f ,1/1.0f};
	circles.emplace_back(c);
	c = { vec3(15.0f,0,0),0.42f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f), 1/1.03f ,1/1.9f};
	circles.emplace_back(c);
	c = { vec3(-20.0f,0,0),1.12f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f), 1/0.41f ,1/3.0f};
	circles.emplace_back(c);
	c = { vec3(25.0f,0,0),0.95f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f), 1/0.45f,1/5.0f};
	circles.emplace_back(c);
	c = { vec3(-30.0f,0,0),0.6f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f) ,1/0.71f,1/8.0f};
	circles.emplace_back(c);
	c = { vec3(35.0f,0,0),0.76f,0.0f,0.0f,vec4(1.0f,0.5f,0.5f,1.0f) ,1/0.74f,1/10.0f};
	circles.emplace_back(c);
	return circles;
}

inline void circle_t::update( float dt)
{
	theta += dt*rot_speed*5.0f;
	phi += dt*rev_speed;
	float c_theta = cos(theta), s_theta = sin(theta);
	float c_phi = cos(phi), s_phi = sin(phi);

	// these transformations will be explained in later transformation lecture
	mat4 scale_matrix =
	{
		radius, 0, 0, 0,
		0, radius, 0, 0,
		0, 0, radius, 0,
		0, 0, 0, 1
	};

	mat4 rotation_matrix =
	{
		c_theta,-s_theta, 0, 0,
		s_theta, c_theta, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	mat4 rotation_matrix2 =
	{
		c_phi,-s_phi, 0, 0,
		s_phi, c_phi, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	mat4 translate_matrix =
	{
		1, 0, 0, center.x,
		0, 1, 0, center.y,
		0, 0, 1, center.z,
		0, 0, 0, 1
	};
	
	model_matrix = rotation_matrix2*translate_matrix*rotation_matrix*scale_matrix;
}


#endif
