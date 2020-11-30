#pragma once
#include <GL/glew.h>

struct Position {
	float x;
	float y;

	void set(float _x,float _y) {
		x = _x;
		y = _y;
	}
};

struct Color {
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	void set(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
};

struct UV {
	float u;
	float v;
};

struct Vertex {
	Position position;
	Color color;
	UV uv;
	
	void setUV(float u, float v) {
		uv.u = u;
		uv.v = v;
	}
	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}
};
