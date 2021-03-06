//#ifdef __APPLE__ 
//#include<GLUT/glut.h> 
//#include<openGL/openGL.h> 
//#else 
#include<GL/glut.h> 
//#endif 
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
float da=0.0002,a=2.3,b=2.3,c=2.3,d=2.3,e=2.3,f=2.3;
void initRendering() 
{ 
    glEnable(GL_DEPTH_TEST); 
} 

void reshape(int w,int h) 
{ 
    glViewport(0,0,w,h); 
    
    glMatrixMode(GL_PROJECTION); 
    
    glLoadIdentity(); 
    
    gluPerspective(45,w/h,1,200); 
    
} 

void keyPressed(int key,int x,int y) 
{ 
    if(key==27) 
    {
        exit(1);
    } 
} 

void drawBall() 
{ 
    glColor3f(1.0,1.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,a,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
    glColor3f(1.0,0.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,b+1,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
    glColor3f(0.0,1.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,c+2,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,d+3,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
    glColor3f(1.0,0.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,e+4,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
    glColor3f(0.0,1.0,1.0); 
    glPushMatrix(); 
    glTranslatef(2.0,f+5,-6.0);
    glutSolidSphere(0.2,40,40); 
    glPopMatrix();
    
} 

void update() 
{
    
    if(a<(-2.8))
    {
        a=2.3-5*da;
    }
    else
    {
        a-=da;
    }
    if(b<(-2.8))
    {
        b=2.3-4*da;
    }
    else
    {
        b-=da;
    }
    if(c<(-2.8))
    {
        c=2.3-3*da;
    }
    else
    {
        c-=da;
    }
    if(d<(-2.8))
    {
        d=2.3-2*da;
    }
    else
    {
        d-=da;
    }
    if(e<(-2.8))
    {
        e=2.3-da;
    }
    else
    {
        e-=da;
    }
    if(f<(-2.8))
    {
        f=2.3;
    }
    else
    {
        f-=da;
    }
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    drawBall(); 
    update(); 
    glutSwapBuffers(); 
} 


int main(int argc,char **argv) 
{ 
    glutInit(&argc,argv); 
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 
    
    glutInitWindowSize(600,600); 
    
    glutCreateWindow("Ball Falling Randomly!"); 
    
    initRendering(); 
    
    glutDisplayFunc(display); 
    
    glutIdleFunc(display); 
    
    glutReshapeFunc(reshape); 
    
    glutSpecialFunc(keyPressed); 
    
    glutMainLoop(); 
    
    return(0); 
}
