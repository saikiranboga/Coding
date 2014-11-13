/*
*Author :Tharindra Galahena
*Project:pong game playing neural network (AI)
*Date   :02/09/2012
*License:
* 
*     Copyright 2012 Tharindra Galahena
*
* This program is free software: you can redistribute it and/or modifood_y it under the terms of 
* the GNU General Public License as published by the Free Software Foundation, either 
* version 3 of the License, or (at your option) any later version. This program is distributed
* in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with This program. 
* If not, see http://www.gnu.org/licenses/.
*
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "neural_net.cpp"

using namespace std;

typedef struct sq{
	int x;
	int y;
	int mx;
	int my;
	struct sq *next;
} sq;

sq *snake;

int      mx;
int      my;
neural *net;

int food_x      = -6;
int food_y      = -6;
int sc          =  0;
int num_layers  =  3;
int num_inputs  =  6;
int num_outputs =  4;
int iter        =  0;
int tmp         = 10;
int th          =  0;

bool p          =  false;
bool reseting   =   true;
bool leaning    =   true;

void add(int x, int y){
	sq *tmp = (sq *)malloc(sizeof(sq));
	tmp -> x = x;
	tmp -> y = y;
	tmp -> mx = 1;
	tmp -> my = 0;
	tmp -> next = snake;
	snake = tmp;
}
void start(){
	snake = NULL;
	add(0, 0);
	add(1, 0);
	add(2, 0);
	add(3, 0);
	add(4, 0);
	mx = 1;
	my = 0;
}
void set_f(){
	th = 0;
	bool f = true;
	while(f){
		srand(time(NULL));
		food_x = (rand() % 34) - 17;	 
		srand(time(NULL));
		food_y = (rand() % 34) - 17;
		sq *p = snake;
		while(p != NULL){
			if(p -> x == food_x && p -> y == food_y){
				f = true;
				break;		
			}	
			f = false;
			p = p -> next;
		}	
	}
}
bool tail(){
	sq *p = snake;
	while(p -> next != NULL){
		if(p -> next -> x == snake -> x && p -> next -> y == snake -> y)
			return true;	
		p = p -> next;
	}
	return false;
}
float check(int x, int y){
	sq *p = snake;
	while(p -> next != NULL){
		if(p -> next -> x == x && p -> next -> y == y)
			return 1.0;	
		p = p -> next;
	}
	return 0.0;
}
void rev(){
	sq *snake2 = NULL;
	sq *p = snake;
	while(p != NULL){
		sq *tmp = (sq *)malloc(sizeof(sq));
		tmp -> x = p -> x;
		tmp -> y = p -> y;
		tmp -> mx = -1 * p -> mx;
		tmp -> my = -1 * p -> my;
		tmp -> next = snake2;
		snake2 = tmp;
		sq *x = p -> next;
		free(p);
		p = x;	
	}
	snake = snake2;
	mx = snake -> mx;
	my = snake -> my;
}

void move(){
	sq *p = snake;
	int x = p -> x;
	int y = p -> y;
	int tmx = p -> mx;
	int tmy = p -> my;
	while(p -> next != NULL){
		sq *q = p -> next;
		int tmp = q -> x;
		q -> x = x;
		x = tmp;

		tmp = q -> y;
		q -> y = y;
		y = tmp;

		tmp = q -> mx;
		q -> mx = tmx;
		tmx = tmp;

		tmp = q -> my;
		q -> my = tmy;
		tmy = tmp;

		p = p -> next;
	}
	snake -> mx = mx;
	snake -> my = my;
	snake -> x += mx;
	snake -> y += my;
}
void par(float x1, float x2, float y1, float y2, float z1, float z2){
	if(leaning) glColor3f(1.0, 0.0, 1.0);
	else  glColor3f(1.0, 1.0, 0.0);
	
	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glVertex3f(x1, y2, z1);

	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();

	glTranslatef(0.0, 0.0, -22.0);
	int i;
	sq *p = snake;
	par(-8.7,  9.2,  9.0,  9.2, 0.0, 0.0);
	par(-8.7,  9.2, -8.5, -8.7, 0.0, 0.0);
	par(-8.5, -8.7, -8.7,  9.2, 0.0, 0.0);
	par( 9.2,  9.0, -8.7,  9.2, 0.0, 0.0);
	while(p != NULL){
		par((p -> x)/2.0,(p -> x)/2.0 + 0.4,(p -> y)/2.0,(p -> y)/2.0 + 0.4, 0.0, 0.0);
		p = p -> next;	
	}
	par(food_x/2.0, food_x/2.0 + 0.4 , food_y/2.0 , food_y/2.0 + 0.4, 0.0 , 0.0);
	glutSwapBuffers();
}
void myIdleFunc(int a) {
	if(!p){
		th++;
		int sx = snake -> x;
		int sy = snake -> y;
		
		float bx = food_x - snake -> x;
		float by = food_y - snake -> y;
		
		if(bx < 0) bx = -bx;
		if(by < 0) by = -by;
		
		float inputs[6];
		inputs[0] = food_x - snake -> x;
		inputs[1] = food_y - snake -> y;
		inputs[2] = check(snake -> x + 1, snake -> y    );
		inputs[3] = check(snake -> x    , snake -> y + 1);
		inputs[4] = check(snake -> x - 1, snake -> y);
		inputs[5] = check(snake -> x    , snake -> y - 1);
		
		float *out = net -> feed(inputs);
		if(out[0] > 0.5){
			mx = -1;
			my =  0;
		}else if(out[1] > 0.5){
			mx =  1;
			my =  0;
		}else if(out[2] > 0.5){
			mx =  0;
			my =  1;
		}else{
			mx =  0;
			my = -1;
		}
		move();
		if(snake -> x == food_x && snake -> y == food_y){
			add(food_x, food_y);	
			sc++;
			cout << "================= > score = " << sc << endl;
			set_f();
		}else{
			float ax = food_x - snake -> x;
			float ay = food_y - snake -> y;
			
			if(ax < 0) ax = -ax;
			if(ay < 0) ay = -ay;
			
			bool flage1 = ax > bx || ay > by;
			bool flage2 = tail();
			if(flage1 || flage2){
				iter++;
				cout << "iterations = " << iter << endl;
				
				float dout[4];
				bool flage = false;
				
				if(food_x > sx && inputs[2] != 1.0){
					dout[0] = 0.0;
					dout[1] = 1.0;
				}else if(food_x < sx && inputs[4] != 1.0){
					dout[0] = 1.0;
					dout[1] = 0.0;
				}else{
					dout[0] = 0.0;
					dout[1] = 0.0;
				}
				if(food_y > sy && inputs[3] != 1.0){
					dout[2] = 1.0;
					dout[3] = 0.0;
				}else if(food_y < sy && inputs[5] != 1.0){
					dout[2] = 0.0;
					dout[3] = 1.0;
				}else{
					dout[2] = 0.0;
					dout[3] = 0.0;
					if(dout[0] == 0.0 && dout[1] == 0.0){
						dout[2] = 1.0;
					}
				}
				if(leaning) net -> learn(dout);
				if(reseting || flage2){
					sc = 0;
					start();
				}
				
			}
		}
		if(snake -> x > 18 || snake -> x < -18 || snake -> y > 18 || snake -> y < -18){
			start();
		}
		if(th > 200) set_f();
	}
	
	glutPostRedisplay();
	glutTimerFunc(tmp, myIdleFunc, 0);
}
void keyboard(unsigned char key, int x, int y)
{
	if((char)key == 'p'){
		if(p) p = false;
		else p = true;	
	}else if((char)key == 't'){
		tmp--;
	}else if((char)key == 'y'){
		tmp++;
	}else if((char)key == 's'){
		set_f();
	}else if((char)key == 'f'){
		reseting = false;
	}else if((char)key == 'r'){
		reseting = true;
	}else if((char)key == 'l'){
		leaning = true;
	}else if((char)key == 'n'){
		leaning = false;
	}
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);	
	glLoadIdentity ();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLfloat acolor[] = {1.4, 1.4, 1.4, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, acolor);

}
void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(45.0, (float)w/(float)h, 0.1, 200.0);
	
}
int main(int argc, char** argv)
{
	srand(time(NULL));
	net = new neural(num_inputs, num_outputs, num_layers, 10, 0.01, 0.8);
	net -> init();
	start();
	set_f();
	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(450,450);
	glutInitWindowPosition(500,0);
	glutCreateWindow("snake game automation");
	init();
	glutTimerFunc(400, myIdleFunc, 0);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc( keyboard );
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

