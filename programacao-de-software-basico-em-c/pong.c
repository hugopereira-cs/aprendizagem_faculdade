#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define WIDTH 600
#define HEIGHT 500
#define VELOCIDADE_BOLA 30 // Controla o intervalo em milissegundos entre cada atualização da posição da bola (Quanto menor for o valor, maior será a velociade).
#define	VELOCIDADE_JOGADORES 1
#define NUM_RODADAS 10

// Variáveis globais
GLint movebolax=0;
GLint movebolay=0;
GLint direcao=1;
GLint direcao_vertical=1;
GLint move_jogador1Y=0;
GLint move_jogador2Y=0;

int TYJ1 = 0;
int TYJ2 = 0;

int janelaPlacar;
int janela;
static char label[200];
int pts_jogador1 = 0;
int pts_jogador2 = 0;

int movimento_jogador1 = 2;
int movimento_jogador2 = 2;

double angulo = 0.0;

bool pause = true;

// Declaração de funções utilizadas no programa
void init(void);
void display(void);
void bola(int passo);
void keyboard(unsigned char key, int x, int y);
void KeySpecial(int key, int x, int y);
void DesenhaTexto(char *s);
void DesenhaPtsPlacar(char *s);
void JanelaPlacar(void);
void moveJogador(int *move_jogadorY, int *movimento_jogador);
void jogador1(int passo);
void jogador2(int passo);
void displayAll(void);
int gerar_angulo(void);
void setPause(void);


int main(int argc, char** argv){
  // Inicilaiza o GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutInitWindowPosition (100, 100); 

  // Cria a janela principal
	janela = glutCreateWindow ("Telejogo");
	
  // registra funções de callback
  glutIdleFunc(displayAll);
	init();
	glutDisplayFunc(display);	
	glutTimerFunc(VELOCIDADE_JOGADORES,jogador1, 1);
	glutTimerFunc(VELOCIDADE_JOGADORES,jogador2, 1);
	glutTimerFunc(10,bola,1);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(KeySpecial);
	
  // Cria a sub-janela para o placar
	janelaPlacar = glutCreateSubWindow (janela, 5, 5, WIDTH - 10, 85);
	glutDisplayFunc (JanelaPlacar);
	
  // Entra no Loop principal do GLUT
	glutMainLoop();
	return 0;
}

// Função para atualizar todas as janelas
void displayAll(void){
	glutSetWindow(janela);
	glutPostRedisplay();
	glutSetWindow(janelaPlacar);
	glutPostRedisplay();
}

// Inicializa as configurações de OpenGL
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho (0, WIDTH, 0, HEIGHT, -1 ,1);
}

// Função de callback para desenhar a cena principal
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	// glPolygonMode(GL_BACK, GL_LINE);

  // Define a cor branca e largura da linha
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(15.0);

	/* DESENHA MARGENS DO CAMPO*/
	glBegin(GL_LINE_LOOP);
		glVertex2i(2,2);  glVertex2i(599,2);
		glVertex2i(599,399); glVertex2i(2,399);
	glEnd();
	
	/* DESENHA JOGADORES*/
	//JOGADOR-1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex2i(100,190+move_jogador1Y);  glVertex2i(100,240+move_jogador1Y); //barra do jogador 1
	glEnd();

	//JOGADOR-2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex2i(500,190+move_jogador2Y);  glVertex2i(500,240+move_jogador2Y); //barra do jogador 2
	glEnd();


	//BOLA
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(15.0);
	glBegin(GL_POINTS);
		glVertex2i(movebolax+200,movebolay+210);
	glEnd();

	glutSwapBuffers();
 }

 // Função de callback para movimentar o jogador 1
void jogador1(int passo){
	
	moveJogador(&move_jogador1Y,&movimento_jogador1);

	glutPostRedisplay();
	glutTimerFunc(VELOCIDADE_JOGADORES,jogador1, 1);

}

// Função de callback para movimentar o jogador 2
void jogador2(int passo){
	
	moveJogador(&move_jogador2Y,&movimento_jogador2);

	glutPostRedisplay();
	glutTimerFunc(VELOCIDADE_JOGADORES,jogador2, 1);

}

// Função de callback para capturar eventos do teclado
void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 13: // Tecla Enter
			pause = false;
			if(pts_jogador1==NUM_RODADAS || pts_jogador2==NUM_RODADAS){
				pts_jogador1 = pts_jogador2 = 0;
			}
			direcao=1;
		
			break;
		case 27: // Tecla ESC
			exit(0);
			break;
		case 'w':
		case 'W':
			movimento_jogador1 = 1; 
			break;
		case 's':
		case 'S':
			movimento_jogador1 = 3; 
			break;
	}
}

// Função de callback para capturar eventos de teclas especiais
void KeySpecial(int key, int x, int y){
	switch(key){
		case 101: // Tecla seta para cima
			movimento_jogador2 = 1;
			break;
		case 103: // Tecla seta para baixo
			movimento_jogador2 = 3;
			break;
	}
}

// Função para movimentar os jogadores
void moveJogador(int *move_jogadorY, int *movimento_jogador){
	
	switch(*movimento_jogador){
		case 1:
			*move_jogadorY +=30;
			if(*move_jogadorY+240 >= 399){ 
				*movimento_jogador = 2; // Se chegar no limite da tela, para
			}
			break;
		case 2:
			break;
		case 3:
			*move_jogadorY -=30;
			if(*move_jogadorY+190 <= 5) {
				*movimento_jogador = 2; // Se chegar no limite da tela, para
			}
			break;
	}
	
	*movimento_jogador = 2;
	
	if(*move_jogadorY+240 >= 399)
		*move_jogadorY=156;
	else if(*move_jogadorY+190 <= 5)
		*move_jogadorY=-184;
	
}

// Função de callback para movimentar a bola
void bola(int passo)
{

	if(!pause){
		if(direcao==1)
		{
			movebolax += 5;
			if(movebolax==290) {
			
				if(movebolay+210 < move_jogador2Y+190 || movebolay+200 > move_jogador2Y+240){
					pts_jogador1++;
				}else{
					direcao = 0;
					angulo = gerar_angulo();
				}
				

			}else{
				if(movebolax==390){
					setPause();
				}
			}
			
			movebolay += sin(angulo) * direcao_vertical * 5;

			if(movebolay+210 >= 388 || movebolay+200 <=5){
				direcao_vertical *= -1;
			}

			

		}
		else
		{
			if(direcao==0){
				movebolax -= 5;
				if(movebolax==-90){ 
			
					if(movebolay+210 < move_jogador1Y+190 || movebolay+200 > move_jogador1Y+240){
						pts_jogador2++;
					}else{
						direcao = 1;
						angulo = gerar_angulo();
					}
			
				}else{
					if(movebolax==-195){
						setPause();
					}
				}

				movebolay += sin(angulo) * direcao_vertical * 5;
				if(movebolay+210 >= 388 || movebolay+200 <=5){
					direcao_vertical *= -1;
				}

				
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(VELOCIDADE_BOLA,bola, 1);
}

// Função para desenhar o texto
void DesenhaTexto(char *s){
	unsigned int i;
	for (i = 0; i < (unsigned int)strlen (s); i++)
		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, s[i]);
}

void DesenhaPtsPlacar(char *s){
	unsigned int i;
	for (i = 0; i < (unsigned int)strlen (s); i++)
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

// Desenha o placar inteiro
void JanelaPlacar(void){
	
	glutSetWindow(janelaPlacar);
	glClearColor(0.25, 0.25, 0.25, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

  // Desenha os textos no placar
	glColor3f(0.0F, 1.0F, 0.0F);
	glBegin (GL_LINE_LOOP);
		glVertex2f (-0.999F,  0.99F);
		glVertex2f (-0.999F, -0.99F);
		glVertex2f (0.999F, -0.99F);
		glVertex2f (0.999F,  0.99F);
	glEnd();

	glColor3f (1.0F, 1.0F, 1.0F);
	sprintf (label, "Ciencia da Computacao");
	glRasterPos2f (-0.98F, 0.55F);
	DesenhaTexto (label);
	
	sprintf (label, "Tecle ESC - Sair");
	glRasterPos2f (-0.98F, 0.0F);
	DesenhaTexto (label);
	sprintf (label, "Tecle ENTER - Iniciar");
	glRasterPos2f (-0.98F, -0.55F);
	DesenhaTexto (label);

	sprintf (label, "PLACAR");
	glRasterPos2f (0.6F, 0.55F);
	DesenhaTexto (label);

  // Desenha a pontuação do jogador 1
	glColor3f(1.0, 1.0, 1.0);
	sprintf (label,  "%i",pts_jogador1);
	glRasterPos2f (0.5F, -0.2F);
	DesenhaPtsPlacar (label);

	if(pts_jogador1==NUM_RODADAS){
		glColor3f(1.0, 1.0, 1.0);
		sprintf (label,  "Vencedor");
		glRasterPos2f (0.45F, -0.50F);
		DesenhaTexto (label);
	}
	
	glColor3f(1.0, 1.0, 1.0);
	sprintf (label,  "Jogador 1");
	glRasterPos2f (0.43F, -0.75F);
	DesenhaTexto (label);

  // Desenha a pontuação do jogador 2
	glColor3f(1.0, 1.0, 1.0);
	sprintf (label, "%i",pts_jogador2);
	glRasterPos2f (0.8F, -0.2F);
	DesenhaPtsPlacar (label);
	
	if(pts_jogador2==NUM_RODADAS){
		glColor3f(1.0, 1.0, 1.0);
		sprintf (label,  "Vencedor");
		glRasterPos2f (0.75F, -0.50F);
		DesenhaTexto (label);
	}
	
	glColor3f(1.0, 1.0, 1.0);
	sprintf (label,  "Jogador 2");
	glRasterPos2f (0.73F, -0.75F);
	DesenhaTexto (label);

  // Troca os buffers de tela
	glutSwapBuffers ();
}

int gerar_angulo(){
	return (rand() % 80)+1;
}

// Função para pausar o jogo e reiniciar variáveis
void setPause(){
	
	movebolax = movebolay = 0;
	movimento_jogador1 = movimento_jogador2 = 2;
	move_jogador1Y = move_jogador2Y = 0;
	pause = true;
	direcao_vertical = 1;
	direcao = 2;
	angulo = 0;
}