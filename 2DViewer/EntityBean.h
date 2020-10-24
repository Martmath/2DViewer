#pragma once

struct baseEB //Entity Bean
{
	//int dx = 0; int dy = 0;
};

struct SquareEB:public baseEB //Square Entity Bean
{
	SquareEB(long l_) :L(l_) {};
	long L;
};

struct CircleEB :public baseEB //Circle Entity Bean
{
	CircleEB(long l_) :L(l_) {};
	long L;
};