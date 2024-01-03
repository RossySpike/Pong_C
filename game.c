//SDL 
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>//SLD2
#include <stdbool.h>

//booleanos
//Incluimos los headers necesarios
SDL_Window* ventana=NULL;
SDL_Renderer* renderer=NULL;
int ejecutandose=0, last_frame_time=0;

//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********
struct valores_de_objeto{int x,y,ancho,largo,velx,vely,puntos;}pelota,raqueta0,raqueta1;
//Declaramos una estructura donde vamos a guardar los datos necesarios para imprimir los elementos del juego
//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********


//Creamos una funcion que cree una ventana
int iniciar_ventana(void){//void pq no queremos que reciba ningun parametro
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){//Inicializamos SDL con SDL_Init y con el comando SDL_INIT_EVERYTHING le decimos que inicie todo
        fprintf(stderr,"ERROR! No se pudo incializar SDL\n");//Si es distinto de cero Ocurrio un error y esta linea lo informa
        return 0;
    }
    SDL_Window* ventana=SDL_CreateWindow(//Aqui creamos una ventana
    "Mi primera ventana :D",//Titulo de la ventana
    SDL_WINDOWPOS_CENTERED,//Aqui se le da el valor de x donde aparecera la ventana, con el comando SDL_WINDOWPOS_CENTERED lo centrar
    SDL_WINDOWPOS_CENTERED,//Aqui se le da el valor y donde aparecera la ventan
    640,//anchura de la ventana
    480,//altura de la ventana
    SDL_WINDOW_SHOWN//Le indicamos que muestre la ventana, aunque creo que esto lo toma por default no estoy seguro si es posible obviar este param
    );
    if (!ventana){//! es el operador no, y este if chequea si lo que esta adentro es falsey
        fprintf(stderr,"ERROR! No se pudo crear la ventana SDL\n");
        return 0;
    }
    renderer=SDL_CreateRenderer(ventana,-1,0);//Con esta funcion se crea el rederizador, esta requiere el parametro de la ventana donde el renderizador es mostrado, el driver con el que se va a inicializar (-1 para que agarre el primero que soporte) y el ultimo que recibe las SDL_Flags
    if (!renderer){//Lo mismo que hicimos con la variable "ventana"
            fprintf(stderr,"Error creando el renderer SDL\n");
            return 0;
    }
    return 1;
}//Ya tenemos nuestra ventana creada, si compilamos este programa y lo ejecutamos se abrira una ventana en negro con el titulo que le dimos, pero, no nos sirve de nada una ventana en negro, asi que ahora vamos a darle un color

void render(void){
    SDL_SetRenderDrawColor(renderer,51,51, 51,0);//Con esta funcion seleccionamos el color con el que se dibuja las operaciones, en este caso la ventana, toma como parametros el contexto de renderizado y el color en codigo decimal RGB, en el orden rojo, verde y azul, por ultimo el valor de transparencia (mientras mas alto mas opaco)
    SDL_RenderClear(renderer);

//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********
    SDL_Rect pelota_rect={pelota.x,pelota.y,pelota.ancho,pelota.largo};
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&pelota_rect);

    SDL_Rect raqueta0_rect={raqueta0.x,raqueta0.y,raqueta0.ancho,raqueta0.largo};
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&raqueta0_rect);

    SDL_Rect raqueta1_rect={raqueta1.x,raqueta1.y,raqueta1.ancho,raqueta1.largo};
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&raqueta1_rect);

    SDL_RenderPresent(renderer);
//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********
}//Aqui ya creamos una ventana, yo le di un color oscuro pero tu le puedes dar el que tu quieras, sin embargo, necesitamos que esa ventana cierre

void inputs(void){//procesamos las entradas
    SDL_Event event;
    SDL_PollEvent(&event);//obtiene eventos & significa que le pasa el valor por referencia 
    switch(event.type){
        case SDL_QUIT:
            ejecutandose=0;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym==SDLK_ESCAPE){//si la tecla escape es presionada se cierra la ventana
                ejecutandose=0;
                break;
            }
//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********
            if (event.key.keysym.sym==SDLK_w) {
                if (raqueta0.y!=0){
                    raqueta0.y-=20;
                    break;
                }
            }
            if (event.key.keysym.sym==SDLK_s) {
                if(raqueta0.y+raqueta0.largo!=480){
                    raqueta0.y+=20;
                    break;
                }
            }
            if (event.key.keysym.sym==SDLK_i) {
                if (raqueta1.y!=0){
                    raqueta1.y-=20;
                    break;
                }
            }
            if (event.key.keysym.sym==SDLK_k) {
                if(raqueta1.y+raqueta1.largo!=480){
                    raqueta1.y+=20;
                    break;
                }
            }
//***********OMITE ESTA PARTE HASTA QUE SE INDIQUE LO CONTRARIO**********
    }
}

//Cerrar la ventana
void elim_ventana(void){
    SDL_DestroyRenderer(renderer);//eliminamos el renderer
    SDL_DestroyWindow(ventana);//eliminamos la ventana
    SDL_Quit();//limpiamos todo
}
//Y listo! ya tienes tu ventana

//Ahora, vamos a poner las cosas un poco mas complejas, recreemos el juego Pong, ya puedes ver las partes que se te pidio omitir por favor vuelve al inicio
void elementos(void){
    //pelota
    pelota.x=640/2;
    pelota.y=480/2;
    pelota.ancho=20;
    pelota.largo=20;
    pelota.velx=100;
    pelota.vely=100;

    //raqueta0
    raqueta0.x=0;
    raqueta0.y=0;
    raqueta0.ancho=15;
    raqueta0.largo=60;

    //raqueta1
    raqueta1.x=625;
    raqueta1.y=420;
    raqueta1.ancho=15;
    raqueta1.largo=60;
}

void refresh(void){
    int time_to_wait=(1000/30)-(SDL_GetTicks()-last_frame_time);
    if (time_to_wait>0 && time_to_wait <= 1000/30){
        SDL_Delay(time_to_wait);
    }
    //Obtener el factor de delta tiempo convertido en segundos, sera usado para actualizar el objeto
    float delta_time=(SDL_GetTicks()-last_frame_time)/1000.0f;
    last_frame_time=SDL_GetTicks();
    pelota.x-=pelota.velx*delta_time;
    pelota.y+=pelota.vely*delta_time;

    //colisiones
    //colisiones para el valor y osea arriba y abajo
    if (pelota.y<0){
        pelota.y=0;
        pelota.vely=-pelota.vely;
    }
    if (pelota.y+pelota.largo>480){
        pelota.y=480-pelota.largo;
        pelota.vely=-pelota.vely;
    }
    //colisiones para el valor x osea izq y der
    if (pelota.x<raqueta0.ancho&&pelota.y+pelota.largo<=raqueta0.y+raqueta0.largo+pelota.largo-1&&pelota.y+(pelota.largo*2)-1>=raqueta0.y){
        /*Explicacion del if:
        Se necesita saber cuando la pelota y la raqueta se tocan para que la primera pueda rebotar
        este condicional cumple esa funcion, 
        'pelota.x<raqueta0.ancho' revisa si la posicion del eje x (izq/der) de la pelota es menor al ancho de la raqueta es importante tener en cuenta que el ancho es interpretado como una coordenada en el eje x
        y actua como una especia de pared, en el momento en el que el valor de x de la pelota sea menor a la coordenada indicada esta condicion se va a cumplir, sin embargo
        esto va a pasar en cualquier coordenada de y, pero no queremos esto porque necesitamos que solo se cumpla cuando toque la raqueta
        'pelota.y+(pelota.largo*2)-1<=raqueta0.y+raqueta0.largo' para entenderlo un poco mejor lo voy a poner graficamente, imagina que esta es la pelota:
           .__________ donde esta la * es la coordenada . y 
            |        |
            |        |
            |        |
           *|________|donde esta * es el largo  
            Si sumamos y + largo nos da toda la superficie del del lado izquierdo del cuadro, que es lo que necesitamos saber para poder calcular si toca la raqueta o no
            asi que hacemos lo mismo con los datos de la raqueta y tenemos las 2 superficies que pueden colisionar
            no obstante es como la condicion solo es <= mientras esta se cumpla siempre va a rebotar, sin importar que la raqueta no este ahi, por esta razon es necesaria una tercera condicion
            'pelota.y+(pelota.largo*2)-1>=raqueta0.y' cumple con el valor opuesto de la condicion anterior por lo tanto, ahora hay un espacio restringido que es lo que queremos
            ya que el chiste del juego es que la raqueta choque con la pelota 
            habras notado que agregue '+(pelota.largo*2)-1' esto es para darle mas margen a la pelota
            y si hay un pixel de pelota que toca la raqueta, esta pueda rebotar (por eso el -1)
            */
        pelota.x=raqueta0.ancho;
        pelota.velx=-pelota.velx;
    }
    if (pelota.x+pelota.largo>raqueta1.x&&pelota.y+pelota.largo<=raqueta1.y+raqueta1.largo+(pelota.largo-1)&&pelota.y+(pelota.largo*2)-1>=raqueta1.y){
        pelota.x=raqueta1.x-pelota.ancho;
        pelota.velx=-pelota.velx;
    }
    //Calcular puntos
    if (pelota.x<0) {//lado izq
        raqueta0.puntos+=1;
        pelota.x=640/2-pelota.ancho;
        pelota.y=0-pelota.largo;
        pelota.velx=-pelota.velx;
    }
    if (pelota.x+pelota.ancho>640){//lado derecho
        raqueta1.puntos+=1;
        pelota.x=640/2-pelota.ancho;
        pelota.y=480-pelota.largo;
        pelota.velx=-pelota.velx;
    }
}

int main(){
    ejecutandose=iniciar_ventana();
    elementos();
    while (ejecutandose) {
        inputs();
        refresh();
        render();
    }
    elim_ventana();

    return 0;
}