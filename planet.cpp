#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#endif

#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "osushpere.cpp"

class Planet{
	public:
		const double G = 6.6743e-11;
		const double SunMass = 1.9891e30; 

		float x, z, angle;

		float r, orbitR, orbitPeriod; // Time in days, distance in 10 Million Mile units
		unsigned int *texture;

		Planet(float r, float orbitR, float orbitPeriod, unsigned int *texture){
			this->r = r;
			this->orbitR = orbitR;
			this->orbitPeriod = orbitPeriod;
			this->texture = texture;

			this->angle = 0;
		}

		// Returns orbital period in seconds
		float
		getOrbitPeriod(float orbitR){
			double orbitFactor = 4 * pow(M_PI,2) / (G * SunMass);
			printf("%f\n", G * SunMass);

			return sqrt(orbitFactor * pow(orbitR, 3));
		}

		void
		draw(){
			glEnable( GL_TEXTURE_2D );
			glBindTexture(GL_TEXTURE_2D, *texture);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glColor3f(0,0,0);
			glShadeModel( GL_SMOOTH );
			glPushMatrix();
				glTranslatef(x, 0, z);
				OsuSphere(r,100,100);
			glPopMatrix();
		}

		void
		update(){
			// 1 year = 10 seconds
			// 31,540,000 seconds per year
			// Good time scale = 3.1 million times faster (divide peeriod by time scale)
			// 1 frame = 30 seconds

			
			angle += (2 * M_PI) / 365; 
			
			x = cos(angle);
			z = sin(angle);
			// printf("EarthX: %f\tEarthZ: %f\n", x,z);
		}

};
