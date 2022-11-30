#include <stdio.h>
#include <math.h>
#include <GL/gl.h>


#ifndef POINT_H
#define POINT_H
struct point
{
	float x, y, z;		// coordinates
	float nx, ny, nz;	// surface normal
	float s, t;		// texture coords
};

inline
void
DrawPoint( struct point *p )
{
	glNormal3fv( &p->nx );
	glTexCoord2fv( &p->s );
	glVertex3fv( &p->x );
}
#endif

int		SphNumLngs, SphNumLats;
struct point *	SphPts;

inline
struct point *
SphPtsPointer( int lat, int lng )
{
	if( lat < 0 )			lat += (SphNumLats-1);
	if( lng < 0 )			lng += (SphNumLngs-0);
	if( lat > SphNumLats-1 )	lat -= (SphNumLats-1);
	if( lng > SphNumLngs-1 )	lng -= (SphNumLngs-0);
	return &SphPts[ SphNumLngs*lat + lng ];
}

